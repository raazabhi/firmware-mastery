# Advanced Firmware Development Practice

Welcome to the **Firmware Mastery** repository. This project is dedicated to practicing and demonstrating advanced embedded systems engineering, bridging the gap between beginner bare-metal programming and 15+ years of senior-level firmware development.

## 🎯 Project Goals
- Master the fundamental and advanced layers of firmware architecture.
- Gain deep understanding of core communication protocols and their common failure modes.
- Develop skills for robust inline hardware debugging (Logic Analyzers, Oscilloscopes, JTAG/SWD).
- Write professional, error-free code optimized for reliability, following industry standards (e.g., MISRA-C principles).

## 🗂️ Curriculum & Repository Structure

The repository is structured logically to build knowledge incrementally:

### [01_Architecture_and_Foundations](./01_Architecture_and_Foundations)
- **Bare-metal Boot Sequence:** Linker scripts, startup code, and memory mapping.
- **Bit Manipulation & Register Access:** Safe, atomic operations, and utilizing the `volatile` keyword properly.
- **Interrupts:** NVIC setup, tail-chaining, and exception handling.

### [02_Core_Peripherals](./02_Core_Peripherals)
- **GPIO:** Advanced configurations, slew rates, and open-drain vs push-pull.
- **Timers/PWM:** Input capture, motor control dead-time insertion, and high-resolution timing.
- **ADC/DAC:** DMA-driven sampling, filtering, and noise mitigation.

### [03_Communication_Protocols](./03_Communication_Protocols)
- **UART/USART:** Ring buffers, DMA Rx/Tx, and error recovery.
- **I2C:** Clock stretching, multi-master arbitration, and resolving bus hangs.
- **SPI:** High-speed DMA transfers, CPOL/CPHA, and precise chip-select management.
- **CAN/CAN-FD:** Mailbox filtering, bit-timing calculations, and bus-off recovery.
- **USB & Ethernet:** Enumeration, endpoint management, and network stack integration.

### [04_RTOS_and_Concurrency](./04_RTOS_and_Concurrency)
- **Task Management:** Real-time scheduling, stack depth analysis.
- **IPC (Inter-Process Communication):** Queues, Semaphores, Mutexes, and Event Groups.
- **Concurrency Pitfalls:** Preventing Priority Inversion, Deadlocks, and Race Conditions.

### [05_Advanced_System_Engineering](./05_Advanced_System_Engineering)
- **Memory Protection:** Using the MPU to trap stack overflows and null-pointer dereferences.
- **Bootloaders & OTA:** Designing custom bootloaders, flash partitioning, and FOTA updates.
- **Power Management:** Deep sleep modes, WFI/WFE, and context retention.

### [06_Professional_Debugging_and_Validation](./06_Professional_Debugging_and_Validation)
- **HardFault Analysis:** Unwinding the call stack, decoding the Fault Status Registers (CFSR, HFSR).
- **SWO/ITM Tracing:** Real-time variable tracing and ultra-low overhead `printf` over SWO.
- **Hardware Tools:** Using Logic Analyzers to catch SPI phase errors or I2C clock stretching anomalies.

### [07_Advanced_Hardware](./07_Advanced_Hardware)
- **Interrupts & NVIC:** Preemption priorities and volatile shared variables.
- **Hardware Timers:** Prescalers, ARR frequency generation, and PWM duty cycles.
- **DMA (Direct Memory Access):** CPU offloading and cache coherency.
- **Analog & Power:** ADC DSP filtering, WFI deep sleep instructions, and profiling hardware power drain.

---

> *"The difference between a junior and a senior embedded engineer isn't just knowing how to make it work, but knowing exactly how it will fail, and designing it not to."*