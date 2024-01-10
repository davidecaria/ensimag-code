# Lecture notes from lecture A: Introduction to embedded systems

## General properties

Embedded systems are generally considered a combination of software and hardware that solve a specific problem.
The use of the word **specific** is important since one of the main differences with respect to traditional hardware (for PCs, laptops, or servers) is that they are not general-purpose. They are made with a specific configuration in mind and designed solely (or almost) for that purpose.
They are generally composed of several microprecessors and have a low chance of being crushed. They should be able to work continuously in a special environment (high temperature, pressure, and low energy). Those kinds of circuits are generally highly constrained, tuned for low cost, consume minimum power, and perform the desired function quickly enough.
They are generally reactive to real-time actions and must apply countermeasures, acquire information, or send feedback within a short period of time.

## Application areas

Over the years, we have seen the presence of embedded systems grow exponentially. They are present in almost all application areas, such as:
- Communication devices
- Automotive industry
- Aerospace applications
- Defence systems

As we can easily spot, the various sectors also include critical application fields where security is of paramount importance. The word critical can refer to several domains, ranging from critical for human health to critical for financial markets.As a consequence of this increase in their application domain, we are experiencing a number of attacks that were not possible before. Some examples may be:
- Automotive industry: Jeep Cherokee hijacking (21.07.2015)
- Smart home industry: Alexa, are you listening? (01.07.2017)
- Nuclear plant industry: Zigbee Chain Reaction (24.05.2017)
- Computer Architecture Industry: Meltdown (01.04.2018)

This is a reminder of the tradeoff that we face most of the time when we design our integrated circuits: how secure should it be? What price are we paying for a more secure system? Can we strike a balance between testability and security?

The problem of testability traces back to the production of those circuits. First, we have the specifications of the hardware. Then the specs are turned into masks (CAD) and then into physical masks. Later, they are printed on what is called a wafer, and subsequently, they are packed as integrated circuits or merged with other boards. During those phases, there is always the possibility of errors and defects; hence, we have to test the devices before shipping them!Even a single grain of dust can cause huge damage, leading to an unexpected short circuit (bridging two connections) or an unexpected open circuit (cutting an intended connection). 

Testing is of paramount importance, but it does not get along with security! To test such products, we may introduce vulnerabilities that go undetected until someone finds an exploit and leverages them. Each design step requires testing, and it can be both expensive and ineffective.
This is why we see the growth of boards such as FPGAs and their integration in many areas. Instead of designing the circuit ourselves, we may decide to integrate different modules that have already been tested and proved to be secure enough.
 