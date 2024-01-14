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

