# Lecture notes from lecture D: Fault attacks

## Overview

The paper and lecture slides include the following topics:

- Invasive and Non-invasive Attacks: It discusses various forms of invasive and non-invasive attacks like side-channel analysis (time, power, EM analysis), fault attacks (voltage, clock glitches, laser shots, etc.), and their countermeasures.

- Perturbation-based Attacks: The document elaborates on methods of modifying nominal working conditions to induce faults/errors, such as temperature, power voltage, clock frequency, and the use of sensors to detect abnormal conditions.

- Ideal Fault Induction Techniques: It covers aspects like location control, timing control, fault type control, reproducibility, and cost factors in fault induction techniques.

- Laser-based Attacks: There's a section on the preparation for and execution of laser-based attacks, with an example involving a Virtex chip.

- Fault-Based Cryptanalysis: The paper explains the combination of fault creation and exploitation in cryptanalysis, with an example of the Bellcore attack on CRT-based RSA encryption.

- AES Implementation and Attacks: It goes into detail about the hardware implementations of AES, S-Box implementations, and different types of fault attacks on AES.

- Countermeasures: Various countermeasures are discussed, including hardware redundancy, information redundancy, error detecting codes (EDCs), and their suitability for different cryptographic systems.

- Case Studies and Analysis: The document includes various case studies, analyses of countermeasure efficiency, and considerations for implementation, particularly concerning error detection and correction codes

## Perturbation-based attacks

These attacks involve deliberately modifying the physical environment or operating conditions of a device to induce faults or errors. There are different methods of creating such perturbations, such as altering temperature, power voltage, or clock frequency. Those parameters can be tuned out of the normal working condition to produce some faults. Another important aspect is the use of sensors to detect these abnormal conditions, thereby causing faults that can be exploited for attacks.
Some examples of this approach may be the rising temperature or the white flash light on top of the circuit.

## Overclocking vs. Clock Glitch

Here we have a major difference that will be later exploited to introduce faults.
Overclocking refers to a fault introduced at each cycle, hence the lack of timing control. There is no identification of the induced error and no spacial control.
Clock glitch instead refers to a fault induced only at the attacked cycle. That cycle is the precise target of the attack, so we have timing and spatial control.

They can both be detected by sensors.

## Ideal fault induction technique

Ideally, fault induction has some characteristics. It cannot be random or too costly; otherwise, it will not be considered feasible. Specifically, its characteristics should be:

- Location control
- Timing control
- Fault-type control
- Focalization control (number of faulty bits)
- Reproductibility
- Low cost
- Easy to develop

## Fault-based attacks: basics

Generally speaking a good fault-based attack is a combination of perturbation and cryptanalysis.
When is the attack successful? When the erroneus result is obtained!

## Redundancy

### Hardware redundancy

In the context of hardware faults, redundacy refers the the act of duplicating (or even more) some specific components to prevent critical faults. The idea is that we can discover if a circuit has a fault (injected fault) if the output of the redundant elements are different. If we have two blocks, A and B, and we inject a fault on A, we are able to raise an allarm based on the comparison between the output of A and the output of B. 

Pros:
- We are able to detect faults
Cons:
- We add 100% of are for the redundant component
- DPA is even easier since we have a higher correlation between data and power

A tradeoff could be the so called **Partial Redundancy**. We may not want to create a copy of each block, but we may want to add some extra elements that will be checked to look for faults. This way we avoid waiting 100% of the area for our circuit and we gain a good level of fault protection. The cons is that we are not protected againts transient faults.

### Information redundancy

Error detection codes are the most basic form of information redundancy. The coice of the code is of paramount importance since we have to trade performance and efficency for a safer hardware. Moreover, it has to be worth it! Types of codes for specific operations:

- Parity: more suited to logical operations
- Residues: more suited to arithmentic operations


