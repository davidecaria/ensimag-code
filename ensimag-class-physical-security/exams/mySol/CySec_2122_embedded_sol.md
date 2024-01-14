# CySec Exam 2021/2022 - Embedded systems

## Q1 - Why is security in embedded system important? Cite a few domains where embedded systems should be secured, and cite at least an example of an embedded system that was compromised.

Security in embedded systems is critical for several reasons:

1. **Ubiquity**: Embedded systems are everywhere, in a wide range of applications from consumer electronics to critical infrastructure. Their widespread use makes them a prevalent target for attacks.

2. **Access to Sensitive Data**: Many embedded systems process or store sensitive information, such as personal data, financial information, or trade secrets. Unauthorized access to this data can have serious privacy and financial implications.

3. **Control over Physical Systems**: Embedded systems often have direct control over physical processes in industries like manufacturing, automotive, or healthcare. Compromising these systems can lead to physical damage, endangering human lives and causing significant economic loss.

4. **Limited Resources for Security**: Embedded systems usually have constraints in terms of processing power, memory, and energy. This makes implementing robust security measures a challenge, often leading to vulnerabilities.

5. **Long Lifecycle and Lack of Updates**: Many embedded systems are designed to last for years or even decades, with limited scope for updates or patches. This makes them vulnerable to evolving threats over time.

**Domains Where Security of Embedded Systems is Crucial:**

1. **Automotive Industry**: Modern vehicles, including connected and autonomous cars, rely heavily on embedded systems for functions ranging from engine control to safety features and infotainment systems.

2. **Healthcare**: Medical devices such as pacemakers, insulin pumps, and hospital monitoring equipment are embedded systems whose compromise can have direct life-threatening consequences.

3. **Industrial Control Systems**: These systems manage critical infrastructure in sectors like power generation, water treatment, and manufacturing. Compromises in these systems can lead to massive disruptions and environmental damage.

4. **Consumer Electronics**: Smart home devices, smartphones, and other personal gadgets contain embedded systems that manage personal data, making them targets for data theft and privacy breaches.

5. **Telecommunications**: Network equipment like routers and switches are embedded systems that, if compromised, can disrupt communication services and lead to data breaches.

**Example of a Compromised Embedded System:**

- **Stuxnet Worm Attack on Industrial Control Systems**: One of the most famous examples of an embedded system compromise is the Stuxnet worm, which targeted programmable logic controllers (PLCs) used in Iran's nuclear facilities. The malware subtly altered the speeds of centrifuges, causing physical damage while showing normal operating parameters to monitoring systems. This attack underscored the potential for cyber-attacks to cause physical damage to critical infrastructure and highlighted the importance of securing embedded systems against sophisticated threats.

## Q2 - Describe briefly a few side channel attacks that can be mounted against digital systems.

Side-channel attacks are a form of security exploit that target the physical implementation of a digital system rather than exploiting software vulnerabilities. These attacks are based on the analysis of information gathered from the physical system, such as timing information, power consumption, electromagnetic leaks, or even sound. Here are a few common types of side-channel attacks:

1. **Timing Attacks**: These exploit variations in the time taken to execute cryptographic operations to reveal secrets. For example, by measuring how long it takes a system to encrypt a message, an attacker might deduce information about the encryption key or algorithm.

2. **Power Analysis Attacks**: These involve measuring the power consumption of a device during operation. There are two primary types of power analysis attacks:
   - **Simple Power Analysis (SPA)**: This looks at power consumption patterns to guess at what operations the device is performing, potentially revealing secret keys.
   - **Differential Power Analysis (DPA)**: This involves collecting power measurements across many operations and using statistical analysis to find correlations that leak information about the cryptographic keys.

3. **Electromagnetic Attacks**: Similar to power analysis, these attacks analyze electromagnetic emissions from a device. By using an electromagnetic probe placed near the device, an attacker can gather data about the electromagnetic fields generated during cryptographic operations.

4. **Acoustic Cryptanalysis**: This form of attack uses sounds emitted by a device, particularly mechanical or electronic noises, to gather information. For example, the sound of a printer or the hum of a computer processor can sometimes be used to infer sensitive data.

These attacks highlight the need for robust security not just in software, but in the hardware design and physical operation of digital systems. Countermeasures typically include designing systems to operate uniformly in terms of time and power consumption, shielding emissions, and implementing error detection and correction mechanisms.

## Q3 - Describe a countermeasure against side channel attacks that can be applied at architectural level, why it works, and what is the additional protection that is expected against these attacks.

One effective countermeasure against side-channel attacks at the architectural level is the implementation of **Dual-Rail Precharge Logic (DRP)**. This countermeasure is particularly useful against power analysis attacks, including both Simple Power Analysis (SPA) and Differential Power Analysis (DPA).

**How Dual-Rail Precharge Logic Works:**

1. **Dual-Rail Logic**: In traditional single-rail logic, each bit is represented by a single line that can be either high (1) or low (0). In dual-rail logic, each bit is represented by two lines. One line carries the true value (1 or 0), and the other line carries the complement (0 or 1). This means that for every bit of information, both a "1" and a "0" are represented, regardless of the actual value of the bit.

2. **Precharge Phase**: Before each operation, the dual-rail circuit is precharged to a known state, usually with both lines in a neutral or equal state. After the precharge phase, the operation is performed, and the dual-rail outputs transition to their final states representing the actual computed value.

**Why It Works:**

- **Balanced Power Consumption**: Because each bit is represented by two lines and one of them is always transitioning from the precharged state to the final state regardless of the bit value, the power consumption becomes much more uniform. This uniformity makes it difficult to distinguish between a logical "1" and a "0" based on power analysis, thereby mitigating SPA and DPA attacks.

- **Consistent Timing**: The use of dual-rail logic can also contribute to consistent execution timing for operations, which can help protect against timing attacks.

**Additional Protection Expected:**

- **Reduced Leakage of Information**: Since the power consumption is more uniform and does not directly correlate with the actual data values or operations being performed, it becomes significantly harder for an attacker to gain useful information from side-channel measurements.

- **Mitigation of Electromagnetic and Acoustic Side-Channels**: The balanced nature of the dual-rail precharge logic also helps in reducing electromagnetic and acoustic emissions that can be exploited in side-channel attacks.

However, it's important to note that implementing DRP can be complex and may lead to increased circuit area and power consumption. This is due to the need for additional circuitry to handle the dual-rail representation and precharge mechanism. Additionally, careful design is required to ensure that the power consumption is truly balanced and that no unintended side-channel signals are introduced.

## Q4 - Describe the similarities and differences between the Power Consumption and the EM emission with respect to Side Channel Attacks, and the respective countermeasures that can be used to protect against them.

**Similarities Between Power Consumption and EM Emission Side Channel Attacks:**

1. **Physical Leakage Sources**: Both types of attacks exploit unintentional physical leakages from a digital system. Power consumption attacks analyze variations in the electrical power consumed, while EM emission attacks focus on electromagnetic waves emitted during the operation of the device.

2. **Data-Dependent Leakage**: The information leaked in both cases is often data-dependent. This means the changes in power consumption or EM emissions can correlate with the specific operations being performed by the device, especially those involving cryptographic keys.

3. **Statistical Analysis for Data Extraction**: Attackers typically use statistical techniques to analyze the collected data in both types of attacks. This could involve simple observation in the case of Simple Power Analysis (SPA) or more complex statistical methods like Differential Power Analysis (DPA) and Differential Electromagnetic Analysis (DEMA).

4. **Passive Nature of Attacks**: Both attacks are generally non-invasive and passive, meaning they do not require alteration or interference with the normal operation of the device. The attacker simply collects and analyzes the emitted signals.

**Differences Between Power Consumption and EM Emission Side Channel Attacks:**

1. **Type of Leakage**: Power consumption attacks measure the electrical power used by a device, typically by observing the current drawn from a power source. EM emission attacks, on the other hand, focus on the electromagnetic fields generated by the electronic components and operations within the device.

2. **Measurement Approach**: Power analysis typically requires physical access to the device's power supply line for direct measurement. EM attacks can often be performed with an antenna placed near the device, allowing for potential remote eavesdropping.

3. **Locality of Information**: EM emissions can provide localized information about where on a chip certain operations are taking place, due to the spatial nature of electromagnetic fields. Power consumption analysis usually provides a more global view of the device’s activity.

**Countermeasures Against Power Consumption and EM Emission Side Channel Attacks:**

1. **Countermeasures for Power Consumption Attacks:**

- **Constant Power Consumption:** Designing circuits to consume constant power regardless of the operations being performed. This can be challenging to implement effectively.

- **Randomized Execution:** Introducing random delays or changing the order of operations to obscure the correlation between power consumption and data processing.

- **Voltage and Frequency Hopping:** Varying the operating voltage and frequency to make it harder to distinguish patterns in power consumption.

- **Balanced Hardware Design:** Implementing cryptographic algorithms in hardware such that they consume similar power across different input values.

2. **Countermeasures for EM Emission Attacks:**

- **Shielding:** Enclosing the device in an electromagnetic shield to prevent emissions from being captured.

- **Signal Attenuation:** Using materials and design techniques that reduce the strength of electromagnetic emissions.

- **Noise Generation:** Introducing electromagnetic noise to mask the emissions related to sensitive operations.

- **Localized Grounding and Decoupling:** Implementing localized grounding strategies and decoupling mechanisms to minimize EM emissions from specific parts of the circuit.

**Cross-Cutting Countermeasures:**

- **Algorithmic Noise and Blinding:** Incorporating randomness into the data or algorithm to mask the correlation between the physical leakage and the actual operations or data being processed.

- **Software and Hardware Redundancy:** Using redundant software or hardware paths to disperse the signal profile, making it harder to analyze.

- **Physical Isolation:** Isolating sensitive components from other parts of the system to reduce overall leakage.

It's important to note that while these countermeasures can significantly increase the difficulty of successfully executing side-channel attacks, they often come with trade-offs in terms of increased cost, complexity, and reduced performance or efficiency of the attack.

## Q5 - AES can be vulnerable to fault attacks. Describe briefly how Differential Fault Analysis can allow recovering the secret key, and suggest a (few) countermeasure(s) that could be adopted. Which are the pros and cons against of the solution(s) you proposed?

**Differential Fault Analysis (DFA) on AES:**

Differential Fault Analysis is a side-channel attack that targets cryptographic algorithms like AES (Advanced Encryption Standard) by intentionally inducing faults during the encryption process and analyzing the differences between the correct and faulty outputs.

**How DFA Works in AES:**

1. **Fault Induction**: The attacker induces a fault in the AES algorithm during its execution. This can be done in various ways, such as by manipulating the power supply, clock signal, or using a laser or electromagnetic pulse.

2. **Analyzing Outputs**: The attacker then compares the faulty cipher output with the correct cipher output. The differences give clues about the internal state of the AES algorithm, particularly in the last rounds of the encryption process.

3. **Key Recovery**: By carefully analyzing how the introduced fault alters the output, the attacker can make inferences about the values of certain bits in the key. Repeating this process with different faults can eventually reveal the entire key.

**Countermeasures Against DFA:**

1. **Redundancy in Computation**: Implementing redundant computations and comparing the results can detect discrepancies caused by faults. If a discrepancy is detected, the operation can be aborted, or an error can be signaled.

2. **Random Delays**: Introducing random delays in the encryption process can make it more difficult for an attacker to precisely time the fault injection.

3. **Error Detection and Correction Codes**: Implementing error detection and correction mechanisms within the cryptographic algorithm can identify and correct errors due to fault attacks.

4. **Consistency Checks**: Adding additional checks to ensure the consistency of the computation at various stages of the encryption process can detect and mitigate fault attacks.

5. **Hardware Countermeasures**: Designing the hardware to be more resilient to environmental changes and physical tampering, such as using tamper-resistant packaging or sensors to detect abnormal conditions.

**Pros and Cons of These Solutions:**

- **Redundancy in Computation**:
  - Pros: Effective at detecting faults, can be implemented in software.
  - Cons: Increases computational overhead and power consumption.

- **Random Delays**:
  - Pros: Simple to implement, increases the difficulty of successful fault injection.
  - Cons: May not be effective against sophisticated attackers who can adapt to timing variations.

- **Error Detection and Correction Codes**:
  - Pros: Can identify and correct faults, adding an additional layer of security.
  - Cons: Adds complexity and may increase computational overhead.

- **Consistency Checks**:
  - Pros: Effective at detecting anomalies during execution.
  - Cons: Can increase computational overhead and may be circumvented by sophisticated attacks.

- **Hardware Countermeasures**:
  - Pros: Provides physical protection against tampering and environmental manipulation.
  - Cons: Can be expensive to implement and may not be feasible for all devices.

In summary, while these countermeasures can significantly increase the difficulty of performing a successful DFA attack, they often come with trade-offs in terms of increased cost, complexity, and computational overhead. The choice of countermeasure(s) depends on the specific requirements and constraints of the system being protected.

## Q6 - Describe an effective solution to block the access to the internal test structures to malicious users.

Blocking access to internal test structures, like scan chains and built-in self-test (BIST) mechanisms, in integrated circuits (ICs) is crucial for preventing malicious users from exploiting these features for attacks such as reverse engineering or extracting sensitive information. An effective solution for this is the implementation of a secure test access mechanism. Here's how it can be structured:

**Secure Test Access Mechanism:**

1. **Authentication Requirement**: Implement an authentication protocol for accessing the test structures. Only authorized personnel or processes with the correct credentials or cryptographic keys can enable the test mode. This could involve challenge-response authentication using cryptographic algorithms.

2. **Test Access Port Control (TAP Control)**: Integrate a mechanism to control the Test Access Port (TAP) which is part of the JTAG (Joint Test Action Group) standard. The TAP controller should only grant access to the test structures after successful authentication.

3. **Encryption and Decryption**: Use cryptographic methods to encrypt test data and responses. This ensures that even if someone taps the test data, it remains unintelligible without the appropriate decryption key.

4. **Limited Test Functionality in Unauthenticated Mode**: In an unauthenticated state, the test functionality should be limited or entirely disabled. This prevents unauthorized users from accessing full test features.

5. **Frequent Key Changes and Secure Key Storage**: Implement mechanisms for frequently changing the authentication keys and securely storing these keys within the IC. This could involve hardware-based secure storage elements like Physical Unclonable Functions (PUFs).

6. **Physical Tamper Detection and Response**: Incorporate sensors to detect physical tampering and design the IC to erase sensitive data or lock down test access upon tampering detection.

7. **Self-Destruct Mechanism**: In highly sensitive applications, a self-destruct mechanism that physically disables the IC upon detection of unauthorized access attempts can be considered.

8. **Regular Security Updates and Patches**: For systems that allow it, ensure regular updates to the security mechanisms protecting the test structures. This is particularly important to counteract evolving security threats.

**Pros and Cons of This Solution:**

- **Pros:**
  - Enhanced Security: Authentication, encryption, and tamper detection significantly reduce the risk of unauthorized access.
  - Adaptability: This solution can be tailored to various levels of security requirements.
  - Compliance: Meets industry standards and regulations for secure test access in sensitive applications.

- **Cons:**
  - Increased Complexity: Implementing a secure test access mechanism adds complexity to the IC design and may require additional hardware resources.
  - Performance Impact: The additional security layers may impact the performance of the test procedures, potentially increasing the time for testing and diagnostics.
  - Maintenance: Requires ongoing maintenance and updates to ensure security, especially in systems where security protocols can be updated post-deployment.

In conclusion, while a secure test access mechanism adds complexity and may have some impact on performance and maintenance, it is an effective way to protect against unauthorized access to internal test structures, thereby safeguarding sensitive information and intellectual property in integrated circuits.

## Q7 - In microelectronics industry, which are the main counterfeiting type and how are they defined? Which are the main actions for each of their prevention?

Counterfeiting in the microelectronics industry is a significant issue, as it not only affects revenue but also compromises the reliability and security of electronic systems. The main types of counterfeiting in this industry include:

1. **Clone Counterfeits**: This involves replicating the design of authentic microelectronics and manufacturing counterfeit products. Clones may have substandard or inconsistent performance compared to genuine products.

   - **Prevention**:
     - **Intellectual Property Protection**: Implement robust IP protection measures, including encrypting design files and using secure design methodologies that make cloning difficult.
     - **Legal Actions**: Vigorously enforce IP rights through legal channels to deter potential counterfeiters.

2. **Overproduction Counterfeits**: These occur when unauthorized excess units are produced in a legitimate manufacturing facility without the knowledge or consent of the IP owner.

   - **Prevention**:
     - **Strict Contract Enforcement and Auditing**: Enforce stringent contractual terms with manufacturers and conduct regular audits.
     - **Supply Chain Control**: Implement tight controls and tracking within the supply chain to monitor and regulate production quantities.

3. **Recycled Counterfeits**: These involve taking used microelectronics, refurbishing them, and selling them as new. These components may have reduced lifespans or performance issues.

   - **Prevention**:
     - **Traceability Measures**: Use traceability techniques like serialization and tamper-proof labeling to track component history.
     - **Awareness and Training**: Educate buyers and suppliers about the risks of recycled parts and how to identify them.

4. **Remark Counterfeits**: In this case, lower-grade or out-of-specification products are relabeled and sold as higher-grade or meeting certain specifications they do not actually meet.

   - **Prevention**:
     - **Secure Labeling**: Utilize secure and difficult-to-replicate labeling for products.
     - **Quality Assurance Protocols**: Establish strict quality control processes and protocols throughout the manufacturing and distribution process.

5. **Defective/Out-of-Spec Counterfeits**: These are components that have failed quality tests or are out of specification but are still sold in the market.

   - **Prevention**:
     - **Strict Quality Control and Destruction of Defective Units**: Ensure defective units are properly destroyed or recycled in a way that prevents them from entering the supply chain.
     - **Certification and Testing**: Regularly certify and test components at various points in the supply chain.

**General Preventive Actions**:

- **Education and Awareness**: Regularly educating stakeholders in the supply chain about the risks and characteristics of counterfeit components is crucial. This includes training for procurement teams on how to identify counterfeit products.

- **Supplier Verification and Auditing**: Rigorously vet and select suppliers. Conduct regular audits to ensure compliance with anti-counterfeiting measures.

- **Use of Trusted Sources**: Purchase microelectronics from authorized distributors or directly from manufacturers to reduce the risk of encountering counterfeit products.

- **Industry Collaboration**: Engage in industry collaborations and information-sharing initiatives to stay informed about new counterfeiting methods and solutions.

- **Implementation of Advanced Technologies**: Utilize advanced technologies like blockchain for supply chain transparency, RFID tags for tracking, and AI-driven tools for counterfeit detection.

- **Standardization and Regulation**: Support and adhere to industry standards and regulations aimed at preventing counterfeiting.

- **Legal and Regulatory Framework**: Advocate for and comply with legal and regulatory frameworks that deter counterfeiting through penalties and enforcement actions.

- **Customer Communication**: Maintain open communication channels with customers to quickly address any concerns regarding authenticity and to provide assurance of product legitimacy.

**Pros and Cons of These Solutions:**

- **Pros**:
  - **Enhanced Security and Reliability**: The measures increase the overall security and reliability of microelectronic components.
  - **Brand Protection**: They help in protecting the brand integrity and reputation of manufacturers.
  - **Consumer Safety**: By ensuring the authenticity of components, these measures contribute to the safety and performance of final products.

- **Cons**:
  - **Increased Costs**: Implementing these measures can increase the costs of production and supply chain management.
  - **Complexity in Supply Chain**: The added security measures can complicate the supply chain process, potentially impacting efficiency.
  - **Continuous Evolution**: Counterfeiters constantly evolve their methods, requiring continuous updates and adaptations of anti-counterfeiting measures.

Overall, combating counterfeiting in the microelectronics industry requires a multi-faceted approach, combining technological solutions, supply chain management, legal actions, and industry collaboration. While these efforts can introduce additional costs and complexities, the benefits of protecting intellectual property, ensuring product quality, and maintaining consumer trust are significant.

## Q8 - What are the physically unclonable functions, how are they use for circuit trust and which are their performance metrics?

**Physically Unclonable Functions (PUFs)** are hardware-based security features used in electronic devices for authentication and secure key generation. They exploit the inherent and unpredictable physical variations that occur during the manufacturing process, making each PUF unique to its host device. This uniqueness is akin to a "fingerprint" for electronic hardware.

**How PUFs are Used for Circuit Trust:**

1. **Device Authentication**: PUFs can be used to uniquely identify and authenticate individual devices. Since the PUF response is unique and unpredictable, it's challenging for attackers to replicate or clone.

2. **Secure Key Generation**: PUFs can generate cryptographic keys based on their unique response patterns. These keys do not need to be stored in non-volatile memory, reducing the risk of extraction through physical attacks.

3. **Prevention of Counterfeiting**: By integrating PUFs into electronic components, manufacturers can ensure that only authentic, verified components are used in their systems, thereby preventing counterfeiting.

4. **Secure Communication**: PUFs can be used in challenge-response protocols for secure communication between devices or components.

**Performance Metrics for PUFs:**

1. **Uniqueness**: This measures how distinct a PUF's response is compared to other PUFs. High uniqueness ensures that each device can be individually identified.

2. **Reliability**: This refers to the consistency of the PUF's response under varying environmental conditions (like temperature and voltage fluctuations). A high reliability is crucial for ensuring that the PUF consistently produces the same output.

3. **Bit Error Rate (BER)**: This metric assesses the error rate in the PUF response. A low BER is desirable for stable operation.

4. **Randomness**: The unpredictability of a PUF's response is essential for security. The response should appear random and unpredictable to an observer.

5. **Reproducibility**: The ability of the PUF to regenerate the same response or key under the same conditions over time.

6. **Tamper-Resistance**: The PUF's resilience to physical and side-channel attacks, ensuring that its characteristics cannot be easily altered or determined.

7. **Physical Footprint**: The size of the PUF on the chip. A smaller footprint is often desirable to save space for other components.

8. **Power Consumption**: The amount of power the PUF requires to operate. Lower power consumption is advantageous, especially in battery-powered or energy-sensitive applications.

9. **Readout Speed**: The time it takes for the PUF to generate a response. Faster readout speeds are beneficial for applications that require real-time or near-real-time authentication.

In summary, PUFs provide a robust and efficient method for enhancing security and trust in electronic circuits. They offer a hardware-based solution to challenges like key storage, device authentication, and protection against cloning or counterfeiting. However, the design and integration of PUFs require careful consideration of their performance metrics to ensure that they meet the specific security and operational needs of the application.
