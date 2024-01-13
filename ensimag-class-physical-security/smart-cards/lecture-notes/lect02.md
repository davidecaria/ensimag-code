# Lecture 02: Dive into smartcards

This lecture provides a detailed insight into the security mechanisms of smartcards and the various invasive techniques used to compromise their security.

- Smart Card Basics and Micro-Module: Explains the fundamentals of smart cards, including their types (contact and contactless) and micro-module components like pins and power supply.

- Communication Standards: Discusses communication standards like ISO 7816-3 and ISO 14443, detailing activation sequences, communication protocols, and data units.

- Device Level and Hardware Security: Covers the hardware components of smart cards, such as CPUs, cryptographic processors, and security features like ciphered memories and environmental analysis detectors.

- Attacks on Smartcards: Focuses on various attack methods, including invasive, semi-invasive, and non-invasive techniques, and tools used in these attacks.

- Invasive Attacks Details: Delves into the specifics of invasive attacks, like reverse engineering and micro-probing, and how they are executed at the transistor level.

- Memory Reading and Microprobing: Addresses techniques for reading memory types in smartcards and the process of micro-probing sensitive data.

- Added Security Measures: Discusses anti-probing layers and their removal as a part of security measures in smartcards.

- Examples of Physical Attacks: Provides real-world examples of known physical attacks on smartcards, illustrating the practical implications of the discussed security concepts.

- Hardware-based Software Attacks: Covers advanced topics like exploiting hardware through software vulnerabilities (e.g., Spectre and Rowhammer attacks).

## Attacks on smartcards

The goal of the attacks on smartcards is the retrieve sensitive information or modify the behaviour of a chip for later use. We can do it in two ways: Perturbation or Observation 

There are mainly 3 types of attacks:
- Invasive: Reverse-engineering, Micro probing
- Semi-invasive: Laser, Electromagnetic probes
- Non-invasive: Power or Clock glitches, Power Analysis, Software

### Fully invasive attacks

We have two types: Reverse-engineering, Micro probing

**Reverse-engineering**

This technique is expensive but it will reveal the circuit itself. We remove layer by layer until we find the actual substrate 

**Micro-probing**

This tecnique requires high precision devices to probe the specif cells and busses and understand the topology from that

For both techniques there exist countermeasures such as extra layering but they can be circumvented.
