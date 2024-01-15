# CySec Exam 2021/2022 - Smartcards

## Section 1 - Security evaluations for a SmartCard

### **1.1 How many security levels (Evaluation Assurance Levels) are defined in the Common Criteria?**

The Common Criteria define seven levels of security, known as Evaluation Assurance Levels (EAL1-7).

### **1.2 Which is the level that should obtain a SmartCard used for banking transaction?**

The specific Evaluation Assurance Level (EAL) required for a SmartCard used for banking transactions can vary based on the requirements set by the banking institution and the regulatory standards applicable in a particular region or country. Generally, SmartCards for banking transactions require a high level of security due to the sensitive nature of financial data and transactions. This often means they are evaluated at higher EALs, such as EAL4, EAL5, or even higher.

EAL4 is commonly seen as a good balance between high security and cost-effectiveness, making it a popular choice for many SmartCard applications, including banking. However, for more stringent security requirements or for use in high-security environments, EAL5 or above might be required.

It's important to consult the specific regulations or standards applicable to banking transactions in the relevant jurisdiction, as the specific Evaluation Assurance Level (EAL) required for a SmartCard used in banking transactions is not explicitly mentioned in the provided documents. However, considering the high-security requirements for financial transactions, SmartCards in the banking sector typically need to adhere to higher security standards. This often involves higher EALs, such as EAL4 or above, to ensure robust security against various types of threats and vulnerabilities. The exact EAL would depend on the security requirements set by the banking institution, payment networks, and regulatory standards in the specific region or country.

### **1.3 Describe the tools used during an invasive probing attack on embedded devices.**

Invasive probing attacks on embedded devices utilize a variety of specialized tools, including:

1. **Focused Ion Beam (FIB):** This tool is used for imaging and attacking at a very low level on devices such as transistors and different layers of the integrated circuit.

2. **Microprober:** This tool allows for precise probing of the micro-scale structures within a chip, facilitating detailed examination and manipulation.

3. **Chemistry Lab:** A laboratory equipped with various chemicals is required for certain processes involved in invasive attacks, like etching or material modification.

4. **Reactive Ion Etching:** This technique is used for layer removal in the chip to expose underlying structures for further analysis or modification.

5. **Optical Microscope:** Used for detailed observation and reverse engineering at the microscopic level【32†source】【33†source】.

These tools are essential for conducting in-depth analysis and manipulation of the hardware, allowing attackers to retrieve sensitive data, such as encryption keys and PINs, or to modify the behavior of the chip.

### **1.4 Describe at least 2 specific tools you can use to perform a perturbation attack.**

To perform a perturbation attack on embedded devices, two specific tools that can be used are:

1. **Laser and Electromagnetic Probes:** These tools are used in semi-invasive attacks. Laser probes can precisely target specific areas of a chip to induce faults, while electromagnetic probes can be used to generate electromagnetic disturbances that affect the chip's operation.

2. **Voltage and Clock Glitch Tools:** These tools are used to create voltage or clock glitches in the device. Voltage glitches involve suddenly dropping or increasing the power supply voltage, while clock glitches involve disrupting the clock signal. Both methods are designed to cause the device to behave unexpectedly, potentially bypassing security mechanisms or revealing sensitive information.

## Section 2 - RSA attack

### **2.1 A consumption curve is recorded during the processing of this algorithm. Describe the experimental set-up to acquire such a curve**

To describe the experimental set-up for acquiring a consumption curve during the processing of the RSA algorithm, we would typically follow these steps:

1. **Equipment Preparation:**
   - **Oscilloscope:** An oscilloscope with sufficient sampling rate to capture the power consumption over time is required.
   - **Probe:** A probe that can measure the power consumption, such as a current probe or a differential voltage probe across a shunt resistor, is needed.
   - **Device Under Test (DUT):** The chip that performs the RSA modular exponentiation must be accessible for the measurement.

2. **Connection Setup:**
   - The measurement probe is connected in series with the power supply line of the DUT to capture the power consumption accurately.
   - If using a shunt resistor, it's placed in series with the supply line and the voltage drop across it is measured to infer the current draw.

3. **Data Acquisition Configuration:**
   - The oscilloscope is configured to trigger at the start of the RSA operation to ensure that the entire process is captured.
   - The time base is adjusted so that the oscilloscope can capture the consumption curve throughout the entire operation of the RSA algorithm.
   - The vertical resolution is set to accurately capture the fluctuations in power consumption.

4. **Execution of the Algorithm:**
   - The RSA operation is initiated on the DUT.
   - The oscilloscope begins capturing the power consumption curve as soon as the operation starts.

5. **Data Capturing:**
   - The power consumption is continuously recorded until the RSA operation is complete. This data will typically show variations in power usage as different parts of the algorithm are executed.

### **2.2 Retrieve one byte of the private key with the help of the curve.**

To extract a byte of the private key from the power consumption trace during RSA operations, we undertake a methodical process that includes the following key steps:

1. **Algorithm Analysis:**
The proposed implementation of the RSA algorithm operates on an asymmetric basis, utilizing the square-and-multiply method. This approach results in varying power consumptions that are dependent on the type of operation being performed. By examining the algorithm closely, we recognize that the power trace can provide us with discernible indicators of the algorithm's execution flow, particularly the power differential between squaring and multiplying operations.

3. **Trace to Bit Mapping:**
From the power trace, we observe distinctive peaks and valleys corresponding to the computational intensity of the RSA algorithm's steps. The peaks in the power trace are indicative of the multiply operation—triggered when the key bit is '1' and the algorithm enters the 'if' branch. Conversely, valleys in the trace suggest the execution of only the squaring operation, signifying that the key bit at that point is '0'.

5. **Key Reconstruction:**
Having aligned the power trace peaks and valleys with their respective key bit values, we initiate the reconstruction of the key by backtracking. For instance, a power trace sequence of peaks (P) and valleys (V) like 'P - V - P - V - P - P - V - P - P - V - P' translates to a binary sequence '1 - 0 - 1 - 0 - 1 - 1 - 0 - 1 - 1 - 0 - 1'. It is crucial to remember that the bits are in reverse order due to the specific notation used in the RSA algorithm, so the actual key sequence would be reversed from the order in which it is read from the trace.

By applying this structured approach, we can piece together the key's binary sequence. If the trace pattern identified is 'P - V - P - V - P - P - V - P - P - V - P', the resulting key sequence, when reversed to match the algorithm's notation, is '10110110101', which represents the portion of the private key we sought to retrieve.

### **2.3 Propose an improvement to this algorithm such that the previous attack is not possible anymore.**

1. **Algorithmic Balancing:**
Adjust the algorithm to perform a fixed number of operations per cycle, regardless of the key bit being processed. This could mean always performing both the square and multiply operations but discarding the result of the multiply when the key bit is '0'. This balance ensures the power consumption remains consistent across all cycles.

3. **Randomize Operation Order:**
Introduce non-deterministic order of operations where possible. For instance, rather than always performing the square operation before the multiply, randomize which operation comes first to prevent a clear power consumption pattern from forming.

By incorporating these improvements, the RSA algorithm would become more resistant to side-channel attacks based on power analysis, as the modifications aim to eliminate distinguishable power consumption patterns that can be tied to specific key bits. It's important to note that implementing these changes should be done with care to ensure that the security enhancements do not inadvertently introduce new vulnerabilities or significantly impact the algorithm's performance

### **2.4 Is this new algorithm is safe against perturbation attacks? Explain why.**
It is way more robuts but it can be vulnerable to other perturbation attacks.

## Section 3 - Verify PIN

### **3.1 Explain the countermeasures at lines 1 and 2**

The idea of having a custom constant value for true and false may be to avoid unintentional return values that may lead to success/fail of the function. 

### **3.2 Explain the countermeasures from line 12 to 15**

The main countermeasure is the use of the counter *correct_digits*. This eliminates the possibility of a timing attack based on the execution time of the check. Specifically, by using a counter, we can effectively make the time for each check constant. The user is unaware of the process until he hits the correct PIN. This differs a lot concerning a design in which we instantly return when we hit the wrong digit of the pin.

### **3.3 Explain the countermeasures at lines 9 and 16**

Those two lines implent the protection againts brute force attacks. By setting a maximum number of trials, we avoid exaustive attacks which will lead to the PIN value in a finate ammount of time (due to the length of the PIN).

## Section 4 - Symmetric cipher

### **4.1 Explain shortly how to perform a Side Channel attack on an AES.**

1. Setup
2. Acquiring data (power consumption)
3. Leakage assesment (use t-student to find two sets that have distinguishable means)
4. Attack on a specfic part of the AES algorithm (ex: First AddRoundKey)

### **4.2 What is a Differential Fault Attack (DFA) on a symmetric cipher?**
A Differential Fault Attack (DFA) is an advanced cryptanalysis technique that involves intentionally inducing faults in the computation of a cryptographic algorithm and analyzing the differences (or differentials) between the correct outputs and the faulty outputs to deduce information about the secret key. When applied to a symmetric cipher, such as AES, the process typically involves the following steps:

1. **Fault Induction:**
   - The attacker introduces errors into the cryptographic device's operation. This can be done through various means such as voltage spikes, clock glitches, temperature variations, or laser beams directed at the chip.

2. **Faulty Output Collection:**
   - The attacker collects the erroneous ciphertexts generated due to the induced faults, along with the correct ciphertext produced without fault induction.

3. **Differential Analysis:**
   - The attacker then compares the correct ciphertext with the faulty ciphertexts. The differences between these outputs are analyzed to determine how the induced fault affected the cipher's operation.

4. **Key Hypothesis and Verification:**
   - By understanding the cipher's structure and how the fault propagates through the rounds of encryption, the attacker can make educated guesses about the secret key or certain bits of it. They can verify these hypotheses by checking if the assumed key bits would lead to the observed differences in the ciphertext.

5. **Key Recovery:**
   - Through iterative analysis and hypothesis testing, the attacker can gradually recover parts of the key or the entire key.

DFA is particularly effective against symmetric ciphers because they typically involve a series of well-defined transformations. If an attacker knows the specific round where the fault was induced and can control or observe the fault's impact, they can use this knowledge to reverse-engineer the key that produced the observed faulty outputs.

### **4.3 How many faults and what kind of faults do you need to succeed a Piret and Quisquater DFA on AES?**

The Piret and Quisquater Differential Fault Analysis (DFA) method on AES typically requires inducing a single fault. The attack focuses on injecting a fault into the AES state array during the execution of the last or the penultimate round before the final ciphertext is produced. The type of fault needed for this attack is very specific:

1. **Byte Fault:** The fault should affect only one byte of the state array. By altering just a single byte, the attacker can use the difference between the correct and faulty

 ciphertexts to make inferences about the key.

2. **Well-Timed Fault:** The fault must be induced at a precise time, specifically when the AES cipher is undergoing its last round of encryption operations. This is due to the attack exploiting the simplicity of the last round, which does not include the MixColumns operation.

Using the AES round transformations and the observed faulty output, the attacker can work backward to deduce the correct value of the key bytes that were used in the last round key (RoundKey). Since AES key schedule is reversible, recovering the last round key can lead to the recovery of the entire AES key.

The Piret and Quisquater attack is significant because it demonstrated that even a single well-placed fault can compromise the security of an otherwise secure encryption algorithm like AES. This underscores the importance of implementing hardware and software countermeasures in cryptographic devices to detect and mitigate fault attacks.




