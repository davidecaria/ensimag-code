# CySec Exam 2018/2019 - Embedded systems

## Q1 - Why is security in embedded system important? Cite a few domains where embedded systems should be secured, and describe at least an example of an embedded system that was compromised.

Security in embedded systems is crucial for several reasons:

1. **Sensitive Data Protection**: Many embedded systems handle sensitive information like personal data, financial details, or intellectual property. Security breaches can lead to data theft or manipulation.

2. **Control over Physical Systems**: Embedded systems often have direct control over physical operations in critical infrastructure, vehicles, or medical devices. Compromises can have real-world consequences, including damage and endangerment of lives.

3. **Widespread Use and Connectivity**: With the proliferation of IoT (Internet of Things), embedded systems are increasingly interconnected and remotely accessible, making them attractive targets for cyberattacks.

4. **Resource Constraints**: Embedded systems often have limited computing resources, making traditional security measures challenging to implement.

5. **Longevity and Lack of Updates**: Many embedded systems have long operational lifetimes, with limited opportunities for security updates, making them vulnerable to evolving threats.

**Domains Where Security of Embedded Systems is Essential:**

1. **Healthcare**: Medical devices like pacemakers, insulin pumps, and hospital monitoring systems contain embedded systems where security breaches can have life-threatening implications.

2. **Automotive Industry**: Modern vehicles, including connected and autonomous cars, are controlled by numerous embedded systems. Security flaws can lead to scenarios like unauthorized access or control over vehicle functions.

3. **Industrial Control Systems**: These systems operate in sectors like power generation, water treatment, and manufacturing. Compromises here can lead to massive disruptions and environmental damage.

4. **Consumer Electronics**: Devices like smartphones, smart home systems, and personal gadgets contain embedded systems that manage significant amounts of personal data.

5. **Financial Services**: ATMs and point-of-sale systems, which are embedded systems, handle financial transactions and sensitive banking information.

**Example of a Compromised Embedded System:**

- **Stuxnet Worm Attack (2010)**: One of the most notable examples of an embedded system compromise is the Stuxnet worm.
It targeted PLCs (Programmable Logic Controllers) used in Iran's nuclear facilities. Stuxnet subtly altered the operation of centrifuges while displaying normal operating parameters to monitoring systems.
This attack demonstrated how cyber threats could cause physical damage to industrial systems and highlighted the importance of securing embedded systems against sophisticated threats.

## Q2 - Describe a countermeasure against side channel attacks that can be applied at architectural level.

One effective countermeasure against side-channel attacks at the architectural level of a system is the implementation of **Randomized Execution**. 
This approach involves introducing randomness into the way a system executes its operations, making it difficult for attackers to gather useful information through side-channel observations like timing, power consumption, or electromagnetic emissions.

**How Randomized Execution Works:**

1. **Instruction Shuffling**: Randomly changing the order of execution of instructions that are independent of each other. This shuffling prevents attackers from making reliable inferences based on the sequence of observed operations.

2. **Random Delays**: Introducing random delays in the execution of operations. This variability in timing disrupts the ability of an attacker to perform accurate timing analysis.

3. **Randomized Data Paths**: Altering the data paths used for different operations randomly. This makes it hard to track data flow through power consumption or electromagnetic emissions.

4. **Memory Access Randomization**: Changing the access patterns to memory, so that identical operations do not always result in the same memory access patterns.

**Why It Works:**

- **Obfuscation of Execution Patterns**: By randomizing various aspects of execution, the system no longer exhibits consistent patterns that attackers rely on for side-channel analysis.
- **Increased Noise in Measurements**: The introduced randomness acts as noise in side-channel measurements, significantly reducing the signal-to-noise ratio for the attacker.
- **General Applicability**: This method can be applied to various architectures and does not rely on specific hardware features.

**Additional Considerations for Implementation:**

- **Performance Impact**: Randomized execution can introduce overheads and inefficiencies in the system, potentially impacting performance. Balancing security and performance is key.
- **Randomness Source**: The quality of the randomization depends on the source of randomness. A secure and unpredictable source is necessary for effectiveness.
- **Adaptability**: The level of random

ization should be adaptable based on the security requirements and threat models.

In summary, randomized execution as an architectural countermeasure can significantly enhance resistance to side-channel attacks by disrupting the predictable patterns that such attacks rely on. 
However, careful consideration must be given to its impact on system performance and the quality of randomness to ensure its effectiveness.

## Q3 - AES can be vulnerable to fault attacks. Describe briefly how Differential Fault Analysis can allow recovering the secret key, and suggest a (few) countermeasure(s) that could be adopted. Which are the pros and againsts of the solution you proposed?

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

## Q4 - What is the purpose of Built-In Self Test (BIST) techniques? How can they be useful in a secure cryptographic hardware implementation?

**Purpose of Built-In Self Test (BIST) Techniques:**

Built-In Self Test (BIST) techniques are used to test the functionality and integrity of hardware components, particularly in complex integrated circuits (ICs) like microprocessors and cryptographic hardware. The primary purposes of BIST include:

1. **Automatic Testing**: BIST allows for automated testing of hardware components, which is essential for large-scale manufacturing and maintenance processes where manual testing is impractical.

2. **Fault Detection**: BIST helps in detecting faults and failures in hardware components, either those that occur during manufacturing or those that develop during the lifecycle of the device.

3. **Reducing External Testing Needs**: By incorporating self-testing capabilities, the need for external testing equipment and processes can be reduced, leading to cost and time savings.

4. **Enhancing Reliability**: Regular self-tests ensure the ongoing reliability and proper functioning of hardware components, which is particularly crucial in safety-critical systems.

5. **Improving Security**: In cryptographic hardware, BIST can be used to verify the integrity of security-critical components and to ensure they haven't been tampered with or compromised.

**Usefulness in Secure Cryptographic Hardware Implementation:**

1. **Integrity Checks**: BIST can be used to regularly check the integrity of cryptographic hardware, ensuring that the hardware hasn't been tampered with and is functioning as expected.

2. **Detecting Hardware Trojans**: BIST can help in detecting unauthorized modifications or hardware trojans that might have been introduced in the cryptographic hardware, either during manufacturing or through subsequent tampering.

3. **Ensuring Correct Operation**: Cryptographic operations require precise and accurate computations. BIST ensures that all parts of the cryptographic hardware are functioning correctly and that there are no faults that could compromise cryptographic operations.

4. **Random Number Generator (RNG) Testing**: In cryptographic systems, BIST can be specifically designed to test the quality and randomness of RNGs, which are critical for generating keys and other cryptographic parameters.

5. **Compliance with Security Standards**: Implementing BIST can be a part of complying with security standards and certifications for cryptographic hardware, demonstrating the ability to self-assess and maintain security integrity.

**Considerations:**

- **Design Complexity**: Integrating BIST adds complexity to the hardware design and requires additional resources.
- **Performance Impact**: Running BIST routines can impact the performance of the device, especially if they are run frequently.
- **Security of BIST Mechanisms**: The BIST routines themselves need to be secure and protected against tampering to ensure their effectiveness.

In conclusion, BIST techniques play a crucial role in ensuring the functionality, reliability, and security of cryptographic hardware, but they must be carefully designed and implemented to avoid adding vulnerabilities.

## Q5 - Please describe the untrusted electronic device supply chain and explain which are the main device counterfeiting types. Please provide a brief description (definition) of each counterfeit method.

**Untrusted Electronic Device Supply Chain:**

The untrusted electronic device supply chain refers to the process through which electronic components and devices are designed, manufactured, distributed, and sold, where there are risks and vulnerabilities to security and authenticity at each stage. This can include unauthorized or counterfeit components being introduced, or legitimate components being tampered with. The key stages include:

1. **Design**: The initial creation of the electronic device's blueprint, where intellectual property theft or unauthorized access to design files can occur.

2. **Manufacturing**: The actual production of devices or components, where overproduction, substandard manufacturing, or insertion of malicious elements can happen.

3. **Distribution**: The process of moving the products from manufacturers to consumers, during which time counterfeit products can be introduced, or genuine products can be altered or replaced.

4. **Retail and Use**: The final stage where the end-user acquires and uses the device. Counterfeit products may reach consumers, who are often unable to distinguish them from genuine products.

**Main Device Counterfeiting Types:**

1. **Cloning**: This involves creating an unauthorized copy of a device or component. Cloners may reverse-engineer a product to produce a replica, often using inferior materials or processes.

2. **Overproduction**: Occurs when a contracted manufacturer produces more units than ordered and sells the excess without authorization. These products are often identical to genuine items but are sold outside of official channels.

3. **Re-marking**: Involves changing the labels or markings on a product to misrepresent its specifications, performance, or origin. For example, a lower-grade component may be labeled as a higher-grade.

4. **Recycling**: Entails taking used or discarded electronic components, refurbishing them, and selling them as new. This can lead to performance issues and reduced lifespans.

5. **Tampering**: The alteration of a genuine product, either in hardware or software, to change its functionality or insert malicious features.

6. **Defective/Out-of-Spec Counterfeits**: Selling components that failed quality tests or don’t meet specifications as if they were fully functional.

**Prevention and Mitigation:**

To combat these issues, stringent security measures, thorough vetting of suppliers, regular auditing, use of secure and traceable supply chains, and public awareness campaigns are essential. Also, the implementation of advanced technologies like blockchain for tracking, and AI for counterfeit detection, can significantly bolster the integrity of the supply chain.

## Q6 - Give two hardware features which can thwart return oriented programming attacks. Justify your answer.

Return-Oriented Programming (ROP) attacks are advanced exploitation techniques where an attacker takes control of a computer's execution flow by leveraging pieces of existing code in the system memory, typically ending with a 'return' instruction. These attacks are often used to circumvent traditional security measures like non-executable memory. To thwart ROP attacks, certain hardware features can be implemented:

1. **Hardware-enforced Control Flow Integrity (CFI)**:
   - **Principle**: CFI ensures that the execution of the program follows the legitimate control flow as defined by the program's control flow graph. Hardware-enforced CFI typically involves tagging and tracking control flow transfers (like function calls and returns) and ensuring they align with a predefined valid path.
   - **Justification**: ROP attacks manipulate the control flow by chaining together small sequences of legitimate instructions ending with 'return'. Hardware-enforced CFI can detect and prevent these unauthorized control flow transfers, making ROP attacks significantly more difficult to execute.

2. **Stack Pointer Integrity Checks**:
   - **Principle**: This feature involves hardware mechanisms that monitor and validate changes to the stack pointer. It can ensure that the stack pointer is only modified in legitimate ways, typically in accordance with the calling conventions of the system.
   - **Justification**: ROP attacks often involve manipulating the stack to control the order of 'return' addresses. By enforcing strict rules on how the stack pointer can be modified, these attacks can be detected and blocked. For example, a sudden, unexpected change in the stack pointer that does not align with a legitimate function call or return can be flagged as malicious.

These hardware features enhance the security of a system by providing low-level, fundamental protections against control flow hijacking techniques, including ROP attacks. Their effectiveness lies in their ability to operate independently of higher-level software, making them more difficult for attackers to bypass. However, the design and

 implementation of such features must be done carefully to avoid introducing new vulnerabilities or significantly impacting system performance.

## Q7 - What are the limitations of debug access protection based on Trustzone? Justify your answer.

Debug access protection based on ARM TrustZone, while providing a robust mechanism for securing debug interfaces, has certain limitations:

1. **Complexity and Correct Implementation**:
   - **Justification**: Implementing TrustZone-based debug access protection requires a comprehensive understanding of the security model and careful configuration. Any incorrect implementation or misconfiguration can leave vulnerabilities, potentially exposing the system to attacks. The complexity can be a barrier, especially for developers not specialized in security.

2. **Limited to ARM Architecture**:
   - **Justification**: TrustZone technology is specific to ARM processors. Therefore, this debug protection method is not applicable to systems based on other architectures (like x86 or MIPS). This limits its universality and applicability.

3. **Dependence on Secure World Integrity**:
   - **Justification**: TrustZone-based protection relies on the integrity of the Secure World (TrustZone's secure environment). If the Secure World is compromised (e.g., through software vulnerabilities), the debug protection can also be compromised, potentially allowing unauthorized access.

4. **Performance Overhead**:
   - **Justification**: Implementing stringent security checks in the debug process can introduce performance overheads. While necessary for security, this can slow down development and debugging processes, impacting productivity.

5. **Potential for Lockout**:
   - **Justification**: Overly strict debug access controls can lead to situations where legitimate access to debug features is inadvertently blocked. This can be problematic for legitimate debugging, maintenance, and firmware updates.

6. **Not a Complete Solution**:
   - **Justification**: TrustZone-based debug protection is not a comprehensive security solution by itself. It needs to be part of a layered security approach, as it primarily secures the processor level and may not address other potential attack vectors at different system levels.

7. **Physical Attacks**:
   - **Justification**: While TrustZone can effectively protect against software-based attacks, it may not be as effective against sophisticated physical attacks, such as side-channel attacks or hardware tampering.

In summary, while TrustZone provides a powerful tool for securing debug interfaces, its effectiveness is contingent on correct implementation and is inherently limited to ARM architectures. Additionally, it should be complemented with other security measures to address its limitations and to provide comprehensive protection against a wide range of attack vectors.
