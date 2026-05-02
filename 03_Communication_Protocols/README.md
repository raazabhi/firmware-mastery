# 📡 Communication Protocols Mastery

This module covers the core digital communication protocols you will use daily in embedded systems. As a senior firmware engineer, you aren't just configuring the peripherals; you are defending against hardware glitches, electrical noise, and edge cases.

## 1. I2C (Inter-Integrated Circuit)
**The Protocol:** Synchronous, half-duplex, 2-wire (SCL, SDA), open-drain architecture.
**The "Senior" Focus:**
- **Clock Stretching:** Slaves can hold the SCL line low to tell the master to wait. If your master driver doesn't support this (or times out too early), you'll read corrupted data.
- **The "Bus Hang":** If a master resets mid-transaction, a slave might be stuck holding SDA low (waiting for the next clock pulse). 
  - *Trick to fix:* The master must temporarily reconfigure the SCL pin as a standard GPIO and manually toggle it (bit-bang) up to 9 times until the slave releases SDA.
- **NACK Handling:** A slave will NACK if it's busy or missing. Never assume an I2C transaction succeeds. Always check the return code before using the data buffer.

## 2. SPI (Serial Peripheral Interface)
**The Protocol:** Synchronous, full-duplex, 4-wire (SCLK, MOSI, MISO, CS), push-pull architecture.
**The "Senior" Focus:**
- **CPOL / CPHA Mismatch:** The most common issue. You must align the Master's Clock Polarity and Phase with the Slave's datasheet. If you read data shifted by 1 bit, your Phase is wrong.
- **Dummy Bytes:** Because SPI is full-duplex, to read 1 byte from a sensor, you *must* transmit 1 byte (usually `0xFF` or `0x00`).
- **CS (Chip Select) Timing:** Hardware CS on many MCUs drops immediately after the last clock pulse. Some sensors need a few nanoseconds of hold time. 
  - *Trick to fix:* Use software (GPIO) Chip Select. Manually drive it LOW, start the DMA transfer, wait for transfer complete interrupt, delay slightly, then drive it HIGH.

## 3. UART/USART (Universal Asynchronous Receiver-Transmitter)
**The Protocol:** Asynchronous, full-duplex, 2-wire (TX, RX).
**The "Senior" Focus:**
- **Baud Rate Drift:** Since there is no clock line, internal RC oscillators in MCUs can drift with temperature. A 3% drift causes framing errors.
  - *Trick to fix:* Use an external crystal oscillator (HSE) for reliable UART, or use autobaud detection if supported.
- **The Ring Buffer (Circular Buffer):** Never process UART bytes in the Rx Interrupt Service Routine (ISR). Instead, push them to a volatile ring buffer and process them in the main loop or RTOS task to avoid dropping bytes.
- **Overrun Errors (ORE):** Happens when a new byte arrives before you read the previous one from the hardware register. Your driver must explicitly clear the ORE flag, or the UART peripheral will permanently lock up.

## 4. CAN & CAN-FD (Controller Area Network)
**The Protocol:** Asynchronous, differential signaling, multi-master, broadcast architecture.
**The "Senior" Focus:**
- **Arbitration & Bit Timing:** CAN relies on perfectly synchronized bit segments (Propagation, Phase 1, Phase 2). You must calculate the Time Quanta (TQ) precisely based on the bus length.
- **Mailbox Filters:** Don't process every message on the bus. Configure hardware acceptance filters so the MCU only interrupts for relevant Message IDs.
- **Bus-Off State:** If a node detects too many errors (Tx Error Counter > 255), it physically disconnects from the bus. 
  - *Trick to fix:* Implement an automatic or manual bus-off recovery sequence in your driver, or your device will become a "brick" on the network.

## 🛠️ Essential Debugging Tools & Terminology

### The Tools
1. **Logic Analyzer (e.g., Saleae, PulseView):** Absolutely mandatory for SPI/I2C. You can decode the bits on the wire to prove whether the bug is in your C code or the external sensor.
2. **Oscilloscope:** Used to check signal integrity. A logic analyzer sees a "1" or "0", but an oscilloscope will show you if your I2C pull-up resistors are too weak (creating curved, slow-rising signals).
3. **SWD (Serial Wire Debug):** The modern JTAG. 2 wires (SWDIO, SWCLK). Used for stepping through code, setting breakpoints, and reading memory while the CPU is halted.

### The Terminology
- **Bit-banging:** Manually toggling GPIO pins in software to simulate a protocol (e.g., creating an I2C clock in a `for` loop). Used when hardware peripherals run out.
- **ISR (Interrupt Service Routine):** Code that runs immediately when a hardware event occurs. Must be kept *extremely* short.
- **Volatile:** A C keyword telling the compiler "this variable can change outside of the normal program flow" (e.g., updated by an ISR or hardware register). Without it, the compiler's optimizer will break your code.
- **Race Condition:** When a main loop and an interrupt try to modify the same variable at the same time, resulting in corrupted data.
