# CySec Exam 2021/2022 - Smartcards

## Section 1 - Security evaluations for a SmartCard

- **How many security levels (Evaluation Assurance Levels) are defined in the Common Criteria?**

The Common Criteria define seven levels of security, known as Evaluation Assurance Levels (EAL1-7).

- **Which is the level that should obtain a SmartCard used for banking transaction?**

The specific Evaluation Assurance Level (EAL) required for a SmartCard used for banking transactions can vary based on the requirements set by the banking institution and the regulatory standards applicable in a particular region or country. Generally, SmartCards for banking transactions require a high level of security due to the sensitive nature of financial data and transactions. This often means they are evaluated at higher EALs, such as EAL4, EAL5, or even higher.

EAL4 is commonly seen as a good balance between high security and cost-effectiveness, making it a popular choice for many SmartCard applications, including banking. However, for more stringent security requirements or for use in high-security environments, EAL5 or above might be required.

It's important to consult the specific regulations or standards applicable to banking transactions in the relevant jurisdiction, as the specific Evaluation Assurance Level (EAL) required for a SmartCard used in banking transactions is not explicitly mentioned in the provided documents. However, considering the high-security requirements for financial transactions, SmartCards in the banking sector typically need to adhere to higher security standards. This often involves higher EALs, such as EAL4 or above, to ensure robust security against various types of threats and vulnerabilities. The exact EAL would depend on the security requirements set by the banking institution, payment networks, and regulatory standards in the specific region or country.

- **Describe the tools used during an invasive probing attack on embedded devices.**

Invasive probing attacks on embedded devices utilize a variety of specialized tools, including:

1. **Focused Ion Beam (FIB):** This tool is used for imaging and attacking at a very low level on devices such as transistors and different layers of the integrated circuit.

2. **Microprober:** This tool allows for precise probing of the micro-scale structures within a chip, facilitating detailed examination and manipulation.

3. **Chemistry Lab:** A laboratory equipped with various chemicals is required for certain processes involved in invasive attacks, like etching or material modification.

4. **Reactive Ion Etching:** This technique is used for layer removal in the chip to expose underlying structures for further analysis or modification.

5. **Optical Microscope:** Used for detailed observation and reverse engineering at the microscopic level【32†source】【33†source】.

These tools are essential for conducting in-depth analysis and manipulation of the hardware, allowing attackers to retrieve sensitive data, such as encryption keys and PINs, or to modify the behavior of the chip.

- **Describe at least 2 specific tools you can use to perform a perturbation attack.**

To perform a perturbation attack on embedded devices, two specific tools that can be used are:

1. **Laser and Electromagnetic Probes:** These tools are used in semi-invasive attacks. Laser probes can precisely target specific areas of a chip to induce faults, while electromagnetic probes can be used to generate electromagnetic disturbances that affect the chip's operation.

2. **Voltage and Clock Glitch Tools:** These tools are used to create voltage or clock glitches in the device. Voltage glitches involve suddenly dropping or increasing the power supply voltage, while clock glitches involve disrupting the clock signal. Both methods are designed to cause the device to behave unexpectedly, potentially bypassing security mechanisms or revealing sensitive information.
