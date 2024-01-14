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

## Q2 - Describe a countermeasure against side channel attacks that can be applied at RTL (Register Transfer Level).

At the RTL (Register Transfer Level) of hardware design, implementing **Masking** is a notable countermeasure against side-channel attacks. Masking involves altering sensitive data with random values to obscure the correlation between the data and the physical side-channel emissions (like power consumption or electromagnetic radiation) during processing.

**How Masking Works at RTL:**

1. **Data Masking**: Sensitive data (like cryptographic keys or plaintext) is combined with one or more random values (masks) before any cryptographic operation. This process ensures that the actual data being processed is not directly exposed.

2. **Computation with Masked Data**: The cryptographic operations are then performed on the masked data instead of the raw sensitive data. These operations are modified to account for the masking, ensuring that the output remains correct.

3. **Unmasking**: After the computation, the effect of the mask is removed from the output data to get the correct result of the cryptographic operation.

**Implementation Considerations at RTL:**

- **Designing Masked Operations**: At the RTL, designers need to ensure that all operations on sensitive data are compatible with masking. This may involve redesigning standard components like adders, multipliers, or S-Boxes in cryptographic algorithms.

- **Generating Random Masks**: Secure generation and management of the random masks are crucial. The randomness source should be unpredictable and robust against attacks.

- **Balancing Performance and Security**: Masking increases the complexity of the operations and can impact performance. Careful design is needed to balance the security benefits against the performance overhead.

**Advantages of Masking at RTL:**

- **Effective Against Side-Channel Attacks**: By masking the data, the correlation between the data being processed and the measurable side-channel emissions is significantly reduced, making it difficult for attackers to gain meaningful information.
- **Versatile**: Masking can be applied to various cryptographic algorithms and is effective against different types of side-channel attacks, including simple and differential power analysis.

**Disadvantages of Masking at RTL:**

- **Increased Complexity**: The design and verification processes become more complex due to the need for additional components to handle masking and unmasking.
- **Performance Overhead**: Masking can lead to longer computation times and increased power consumption.
- **Potential Vulnerabilities**: If not implemented correctly, masking can introduce new vulnerabilities, or the randomness source itself may become a target for attackers.

In summary, while masking is a powerful technique to mitigate side-channel attacks at the RTL level, it requires careful implementation and consideration of the trade-offs between security enhancement and potential performance impacts.

## Q3 - Describe how you would choose an Error Detecting Code to protect a public-key cryptosystem from fault attacks, and why.

Choosing an Error Detecting Code (EDC) to protect a public-key cryptosystem from fault attacks involves several considerations. These attacks manipulate the cryptographic algorithm's execution to derive secret keys or bypass security checks. An effective EDC can detect alterations in the data, preventing the attack from succeeding. Here's how to choose an EDC and the rationale behind it:

1. **Error Detection Requirements**:
   - **Understand the Fault Model**: Determine the types of faults likely to occur or be induced (e.g., bit flips, stuck-at faults). This helps in selecting an EDC that is effective against the specific fault model relevant to the cryptosystem.
   - **Coverage**: Choose an EDC with high error coverage, capable of detecting a wide range of error types and patterns. For public-key cryptosystems, which often involve large data blocks, the EDC should detect both single-bit and multi-bit errors.

2. **Implementation Constraints**:
   - **Performance Overhead**: Consider the computational overhead of the EDC. Public-key operations are already resource-intensive; adding an EDC should not excessively degrade performance.
   - **Resource Utilization**: Evaluate the impact on hardware or memory resources, especially for embedded or constrained environments.

3. **Types of EDCs**:
   - **Parity Bits**: Simple and low overhead, but only effective for single-bit error detection.
   - **Cyclic Redundancy Check (CRC)**: Good for detecting burst errors. CRCs are widely used due to their balance between error detection capabilities and computational requirements.
   - **Hamming Code**: Detects and corrects single-bit errors and detects double-bit errors, suitable for scenarios where errors are rare but potentially catastrophic.
   - **Reed-Solomon Codes**: Excellent for correcting burst errors, used in systems where data corruption can occur in blocks.

4. **Security Implications**:
   - **Integration with Cryptographic Processes**: Ensure the EDC does not inadvertently introduce vulnerabilities or leak information about the cryptographic operations.
   - **Tamper-Resistance**: The EDC implementation itself should be resistant to tampering and fault injection.

5. **Scalability and Flexibility**:
   - Choose an EDC that can be scaled according to different security levels and can adapt to future changes in the cryptosystem or threat landscape.

**Why Choose an EDC for Public-Key Cryptosystems**:
- **Protecting Key Integrity**: EDCs help ensure that the keys and other critical data have not been corrupted, maintaining the integrity of cryptographic operations.
- **Thwarting Fault Attacks**: By detecting errors, EDCs can prevent fault attacks from deriving useful information through manipulated computations.
- **Maintaining Reliability**: EDCs contribute to the overall reliability of the system, a critical aspect for trust in cryptographic applications.

In conclusion, the choice of an EDC for a public-key cryptosystem should be driven by a thorough understanding of the fault model, performance and resource constraints, and the security implications. The goal is to select an EDC that offers a balance between robust error detection and minimal impact on the system’s performance and resources.

## Q4 - Describe the pipeline redundancy technique, used against fault attacks. Which are the advantages/disadvantages of this technique?

**Pipeline Redundancy Technique Against Fault Attacks:**

Pipeline redundancy is a technique used in hardware design to protect against fault attacks. It involves duplicating the stages in a pipeline architecture, so each stage's computation is performed twice in parallel. The results from the redundant stages are then compared to detect discrepancies that may indicate a fault.

**How It Works:**

1. **Duplication of Pipeline Stages**: Each stage of the processing pipeline is duplicated. The same operation is performed concurrently in both the original and the redundant pipelines.

2. **Simultaneous Processing**: The data flows through both pipelines simultaneously. The redundant pipeline mirrors the operations of the primary pipeline.

3. **Comparison and Error Detection**: The outputs of corresponding stages in the primary and redundant pipelines are continuously compared. Any mismatch indicates a potential fault, triggering error handling procedures such as system reset, alert generation, or transitioning to a safe state.

4. **Error Handling**: Once a fault is detected, appropriate measures are taken to ensure system integrity. This might involve discarding corrupted data, re-executing operations, or shutting down the system.

**Advantages of Pipeline Redundancy:**

- **Increased Reliability**: Offers a high degree of fault tolerance, making the system more robust against random hardware failures and deliberate fault attacks.
- **Immediate Detection**: Faults can be detected immediately as they occur, allowing for quick response and mitigation.
- **Scalability**: The level of redundancy can be scaled depending on the required level of fault tolerance and the criticality of the application.
- **No Specialized Hardware Required**: Can be implemented using standard hardware components, without the need for specialized fault detection hardware.

**Disadvantages of Pipeline Redundancy:**

- **Increased Hardware Overhead**: Duplicating pipeline stages requires additional hardware, leading to increased costs and larger chip area.
- **Higher Power Consumption**: The additional hardware also consumes more power, which can be a significant drawback in power-sensitive applications.
- **Complexity in Design and Verification**: Designing and verifying a system with pipeline redundancy is more complex, potentially increasing development time and cost.
- **Latency Impact**: While overall throughput might not be significantly affected, the latency for individual operations may increase due to the added comparison and error-handling logic.

In summary, pipeline redundancy is an effective technique for protecting against fault attacks, offering immediate error detection and increased system reliability. However, it comes with trade-offs in terms of increased hardware requirements, power consumption, and design complexity. The decision to use pipeline redundancy should be based on a careful evaluation of these factors in the context of the specific application and its fault tolerance requirements.

## Q5 - Explain what is a Physically Unclonable Function and which are its characteristics.

A Physically Unclonable Function (PUF) is a hardware security mechanism that exploits the inherent physical variations of semiconductor manufacturing processes to create a unique and unclonable identity for a device. These variations are unintentional and uncontrollable but consistent, making each PUF response distinctive to the specific hardware it resides on.

**Characteristics of Physically Unclonable Functions:**

1. **Uniqueness**: Each PUF generates a unique response or "fingerprint" due to the random physical variations (like variations in the dopant level, line width, and transistor threshold voltages) in the manufacturing process. This means no two PUFs, even those manufactured under the same conditions, will produce the same response.

2. **Unclonability**: Due to the random and complex nature of the physical variations, it is practically impossible to clone or replicate a PUF response in another device, even by the manufacturer.

3. **Physical Source of Entropy**: PUFs provide a source of entropy derived from physical characteristics, which is valuable for cryptographic operations such as key generation.

4. **Variability**: The response of a PUF can vary slightly due to environmental factors like temperature and voltage changes. This necessitates error correction methods when PUFs are used for cryptographic key generation.

5. **Tamper-Evidence**: Attempts to physically probe or tamper with a PUF typically alter its structure, hence changing its response. This property can be used for tamper detection.

6. **Non-Reproducibility**: Even with complete knowledge of the design and manufacturing process, it is not feasible to reproduce the exact physical characteristics that give rise to a specific PUF response.

7. **Low Cost**: Many PUF implementations can be realized using existing hardware (like SRAM cells in processors) without significant additional manufacturing costs.

8. **Challenge-Response Pair (CRP) Based Operation**: In many PUF designs, the response depends not only on the physical characteristics but also on an externally provided 'challenge'. This leads to a vast number of potential CRPs, increasing security.

**Applications of PUFs**:

- **Device Authentication**: PUFs are used to authenticate devices in a secure and tamper-proof manner.
- **Secure Key Generation**: PUFs can generate cryptographic keys that are not stored in non-volatile memory, reducing the risk of key extraction attacks.
- **Anti-counterfeiting**: In supply chain management, PUFs can be used to verify the authenticity of products, as each PUF-equipped device carries a unique, unclonable identity.
- **Hardware Binding**: PUFs can bind software or data to specific hardware, ensuring that they cannot be copied or moved to unauthorized devices.

**Challenges and Considerations:**

- **Environmental Sensitivity**: PUF responses can be affected by environmental conditions. Robust error correction and conditioning algorithms are often required to ensure consistent responses.
- **Security Assessment**: It is crucial to assess the security of PUF implementations, as some designs might be susceptible to modeling attacks where an attacker develops a mathematical model to predict PUF responses.
- **Integration into Existing Systems**: While PUFs offer enhanced security, integrating them into existing systems requires careful consideration of the impact on system architecture and performance.

In summary, Physically Unclonable Functions provide a powerful means of establishing hardware security and device authenticity, leveraging the inherent physical randomness of semiconductor manufacturing. Their uniqueness and unclonability make them well-suited for a range of security applications, though considerations around environmental sensitivity and integration must be addressed.

## Q6 - Why the “split manufacturing” technique can prevent the insertion of Hardware Trojan Horses?

The "split manufacturing" technique is a security strategy used in the production of integrated circuits (ICs) to prevent the insertion of Hardware Trojan Horses. This technique involves dividing the manufacturing process across different facilities, typically separating the fabrication of the lower layers (which include the transistors and critical lower interconnects) from the higher metal layers of the IC.

**How Split Manufacturing Prevents Hardware Trojans:**

1. **Separation of Responsibilities**: By dividing the manufacturing process between different facilities, no single party has complete knowledge of the entire IC design. This lack of complete design information makes it challenging for a malicious actor at any one facility to insert a Hardware Trojan effectively.

2. **Complexity in Trojan Insertion**: The insertion of a Hardware Trojan typically requires understanding both the functional logic (lower layers) and the interconnects (higher layers) of the IC. Split manufacturing means that a potential attacker in the foundry has no knowledge of the higher metal layers, which are often where critical signal paths are located.

3. **Obfuscation of Design Intent**: The higher metal layers, which are fabricated separately, often contain the critical wiring that defines the IC's functionality. Without access to these layers, it's difficult for a malicious actor to understand the context of the lower layers well enough to insert a Trojan without detection.

4. **Increased Difficulty in Reverse Engineering**: Split manufacturing also makes reverse engineering more challenging. An attacker attempting to understand the complete IC design would need to access both sets of manufacturing data (lower and higher layers) and then accurately reconstruct the full design.

**Limitations and Challenges:**

- **Increased Cost and Complexity**: Split manufacturing can increase the cost and complexity of the IC production process, as it requires coordination between multiple foundries and potentially involves additional steps to integrate the separately fabricated layers.
- **Design and Performance Considerations**: Designers might need to adapt their designs to suit split manufacturing processes, which could impact the performance and yield of the final IC.
- **Logistical and Trust Issues**: There's a need to establish trust with multiple foundries, and managing the logistics of split manufacturing can be challenging.

In summary, split manufacturing is an effective strategy to mitigate the risk of Hardware Trojans in ICs by compartmentalizing the fabrication process. However, the benefits of increased security must be weighed against the potential for higher costs, logistical complexity, and possible design limitations.
