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
