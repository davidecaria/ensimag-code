# CySec Exam 2021/2022 - Embedded systems

## Q1 - Tables with True or false

Certainly! Here's the analysis of the statements:

1. **Right-to-left or Left-to-right exponentiation algorithms are equivalent with respect to side channel analysis**: **False**. The two methods may have different side-channel leakage characteristics due to variations in their implementation.

2. **Ring Oscillators, used in Random Number Generators, can be biased by electromagnetic pulses**: **True**. Electromagnetic interference can affect the randomness of Ring Oscillators, potentially leading to bias.

3. **Projective representation systems can be a countermeasure to side channel analysis**: **True**. They can alter the observable characteristics of computations, making side-channel analysis more challenging.

4. **Electromagnetic pulses induce delay faults**: **True**. Electromagnetic pulses can interfere with the normal operation of electronic circuits, potentially causing delay faults.

5. **SAT solvers can be used to help side channel attacks**: **True**. SAT solvers can analyze complex logical structures, which can be useful in side-channel attack methodologies.

6. **The order of the operands in a finite field operation is important**: **Depends**. In some finite field operations like addition in GF(2), the order is not important (commutative). However, in other operations or fields, the order might matter.

7. **Hardware Trojans can be detected through side channel analysis**: **True**. Variations in power consumption or electromagnetic emissions due to a hardware Trojan can be detected using side-channel analysis.

8. **Masking is always effective against side channel attacks, independently of the implementation choices**: **False**. The effectiveness of masking can depend heavily on the implementation, and some side-channel attacks can bypass masking.

9. **Hardware Trojans can be detected only at the end of the design flow, once we have the physical circuit**: **False**. They can also be detected during the design and verification phases using various analysis methods.

10. **Voltage glitches can be used to inject faults**: **True**. Voltage glitches can disrupt normal circuit operation and induce faults.

11. **Side channel attacks must analyze the dynamic behavior of the circuit**: **True**. Side channel attacks typically focus on information leaked during the circuit's operation (dynamic behavior).

12. **Pipelined designs can be exploited to protect against passive and active attacks**: **True**. Pipelining can obscure timing information and help mitigate certain attack vectors.

13. **Physical Unclonable Functions have no practical use**: **False**. PUFs are very useful for secure key generation, device authentication, and anti-counterfeiting measures.

14. **Advanced laser attacks can be used to circumvent protections based on redundancy**: **True**. Laser attacks can be precise and powerful enough to affect multiple redundant systems.

15. **AI (Artificial Intelligence) can be used to circumvent protections against side channel analysis**: **True**. AI and machine learning techniques can analyze complex side-channel data and identify patterns that human analysts might miss.

**Additional Articulation:**

- Statements 6 and 9 are nuanced. The significance of operand order in finite field operations depends on the specific operation and field. For hardware Trojans, while physical detection

 is critical, early detection through design and verification is also possible and important.
- For statement 8, masking is a common countermeasure against side-channel attacks, but its effectiveness can be compromised if the implementation is not carefully done, especially in the presence of higher-order attacks.
- In statement 13, the practical utility of Physical Unclonable Functions (PUFs) is well-established in various security applications, making them far from being of no practical use.
- The responses to statements 14 and 15 highlight the evolving nature of attack methodologies, where advanced techniques like laser attacks and AI are increasingly being employed to bypass or compromise security measures. This underscores the need for dynamic and robust security strategies that can adapt to these advanced threats.
  
## Q2 - Describe a countermeasure against side channel attacks that can be applied at architectural level.

A countermeasure against side-channel attacks that can be effectively applied at the architectural level of a system is **Randomized Execution**. This approach involves introducing randomness into the way a system executes its operations, making it difficult for attackers to gather useful information through side-channel observations like timing, power consumption, or electromagnetic emissions.

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
- **Adaptability**: The level of randomization should be adaptable based on the security requirements and threat models.

In summary, randomized execution as an architectural countermeasure can significantly enhance resistance to side-channel attacks by disrupting the predictable patterns that such attacks rely on. However, careful consideration must be given to its impact on system performance and the quality of randomness to ensure its effectiveness.

## Q3 - Discuss the motivations, requirements, advantages, and disadvantages of Double-Data-Rate as a countermeasure against fault attacks.

**Motivations for Double-Data-Rate (DDR) as a Countermeasure Against Fault Attacks:**

1. **Enhanced Security**: Fault attacks exploit vulnerabilities in the timing and execution of operations. DDR, by processing two independent sets of data in a single clock cycle, makes it more challenging to successfully inject and exploit faults.

2. **Improved Efficiency**: DDR effectively doubles the data throughput, processing more data in the same amount of time, which can be beneficial for time-sensitive applications.

3. **Complex Attack Surface**: The simultaneous processing of multiple data streams complicates the task for attackers, as they must now account for more variables and possible outcomes when attempting to inject faults.

**Requirements for Implementing DDR:**

1. **Hardware Capability**: The hardware must support DDR technology, which means it needs to be capable of handling twice the data per clock cycle.

2. **Design Complexity**: Implementing DDR requires a more complex circuit design, including considerations for timing, signal integrity, and power management.

3. **Synchronization**: Accurate synchronization is crucial to ensure that the parallel data streams are processed correctly without errors or data corruption.

**Advantages of DDR as a Countermeasure:**

1. **Increased Throughput**: DDR can double the data processing rate, which is beneficial for high-performance systems.

2. **Enhanced Robustness**: By processing two data streams simultaneously, DDR can increase the resilience of a system against fault attacks, as the complexity of successfully manipulating both data streams is significantly higher.

3. **Redundancy**: In some implementations, DDR can provide redundancy, which is useful for error detection and correction.

**Disadvantages of DDR as a Countermeasure:**

1. **Increased Power Consumption**: Processing more data per clock cycle typically requires more power, which can be a drawback for battery-powered or energy-sensitive devices.

2. **Complexity and Cost**: The increased design complexity can lead to higher production costs and longer development times.

3. **Potential for Increased Latency**: While throughput increases, the latency for individual data processing might increase due to the complexity of handling two data streams.

4. **Design and Testing Challenges**: Ensuring that the DDR system works reliably under all operating conditions can be challenging, requiring extensive testing and validation.

5. **Limited Scope of Protection**: While DDR can provide robustness against certain types of fault attacks, it may not be effective against all varieties, particularly those that do not rely on timing discrepancies.

In summary, while DDR offers increased throughput and enhanced security against fault attacks, it comes with trade-offs in terms of power consumption, complexity, cost, and potentially increased latency. The decision to use DDR as a countermeasure should be based on a careful analysis of these factors in the context of the specific application and threat model.

## Q4 - Discuss the motivations, requirements, advantages, and disadvantages of scrambling the scan chain from a security point of view.

**Motivations for Scrambling the Scan Chain:**

1. **Enhanced Security**: Scan chains, typically used for testing and debugging in integrated circuits, can be exploited to extract sensitive information like cryptographic keys or to insert malicious payloads. Scrambling the scan chain makes such attacks significantly more difficult.

2. **Prevention of Reverse Engineering**: By obscuring the data and structure of the scan chain, it becomes harder for attackers to reverse engineer the chip’s design, protecting intellectual property.

3. **Protection Against Fault Injection**: Scrambling the scan chain can help mitigate attacks that involve manipulating the scan chain to inject faults into the system.

**Requirements for Implementing Scan Chain Scrambling:**

1. **Scrambling Algorithm**: A robust algorithm is needed to effectively scramble and unscramble the data in the scan chain. This algorithm should be secure yet efficient to implement in hardware.

2. **Minimal Impact on Functionality**: The scrambling technique should not interfere with the primary function of the scan chain, which is to facilitate testing and debugging.

3. **Control and Authentication Mechanisms**: Secure mechanisms to control access to the scrambled scan chain are necessary, including possibly implementing authentication protocols.

**Advantages of Scrambling the Scan Chain:**

1. **Increased Resistance to Attacks**: Scrambling adds a layer of security that protects against various attacks, including unauthorized access and extraction of sensitive data.

2. **IP Protection**: Helps in safeguard

ing the intellectual property by preventing reverse engineering attempts.

3. **Compatibility with Existing Infrastructure**: Scan chain scrambling can often be implemented without significant changes to the existing testing infrastructure.

4. **Flexibility**: Scrambling algorithms can be designed to balance security needs with performance requirements, allowing customization based on the application.

**Disadvantages of Scrambling the Scan Chain:**

1. **Design and Implementation Complexity**: Incorporating scrambling into the scan chain adds complexity to the chip design and can increase the development time and cost.

2. **Potential Testing and Debugging Challenges**: Scrambling can complicate the testing and debugging process, as additional steps are needed to unscramble the data. This could potentially lead to longer testing cycles or difficulties in fault isolation.

3. **Performance Overhead**: Depending on the scrambling technique used, there may be a performance overhead in terms of the time taken for testing and debugging due to the additional scrambling and unscrambling processes.

4. **Risk of Lockout**: In cases of failure in the scrambling/unscrambling mechanism or loss of authentication keys, legitimate users may be locked out from accessing the scan chain for necessary testing or debugging.

5. **Balancing Security and Accessibility**: Finding the right balance between making the scan chain secure and keeping it accessible enough for legitimate testing purposes can be challenging.

In conclusion, while scrambling the scan chain provides enhanced security against a range of attacks and helps protect intellectual property, it introduces additional complexity and potential challenges in the testing and debugging processes. The decision to implement scan chain scrambling should consider these trade-offs, assessing the specific security needs against the potential impact on chip development and maintenance.
