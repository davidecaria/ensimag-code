# Lecture notes from lecture B: Hardware-based attacks, types of attacks and exploitation examples

## Limitation of the counter-measures

We know that countermeasures are fundamental to keep our system safe and secure. However, we have no guarantee that they work until we test them or until a vulnerability is exploited. Even with the best protection methods, there is no way to achieve 100% protection. This is because we are never 100% sure of the security of our system. We can just hope that our deployed strategy makes it harder and more time-consuming for an attacker to hack into our system.
All possible attacks must be considered simultaneously since the hardening of one of the weaknesses generates an easier path towards another section of our design or architecture.

## Invasive attacks on the circuit

This cathegory of attacks aims at recovering some information of the circuit by exploiting its physical properties. They are generally destructive, hence they may need multiple samples of the circuit to test various sections of it. Among those type of attacks we have:

- Successive layer removal
- Optical observation
- Bus microprobing

Other attacks involve temperature, pressure and other environmental variables but are not so relevant for the course.

### Countermeasures againts invasive attacks

The main countermeasure that we can use is to aviod easy designs, this is because we don't want our architecture to be revealed at once just by removing a simple layer of oxides (chemically). Memory or bus scrambling are efficient tecniques to make the layout more difficult by design. 

## Implementation attacks (Side channel analysis)

This category is one of the most exploited by attackers since it focuses on leveraging hardware or software vulnerabilities or poor implementations. Many times, information can be revealed by a simple asymmetry in a for loop!
Among the side channel attacks we have:

- Time analysis
- Power analysis
- EM analysis

While it is pretty straight-forward to understand how we can tamper a circuit chemically, it may be less intuitive to reveal a secret key by analyzing the power consumption of a circuit. Or how much time it takes for it to execute a particular attack. As an example, let's consider the following:

Suppose that we have a secret key Ks composed of n bits. This key is hardcoded in our system and is used for a set of operations. At some point, we encountered the following code (PSEUDO-CODE):

ks = (k~n-1~,k~n-2~,...,k~0~)
1. S=P
2. For i=n-2 downto 0:
    S = 2S
    if k~i~=1, S=S+P
3. return S

It should be clear enough that if the bit of the secret key ks is 1, a further step is executed, specifically a point addition. This may require more time or more power, and thus, by analyzing the power or time trace, we can deduce which bits of the key are zeros and ones.

### Countermeasures againts side channel attacks

There exists no universal solution for all side channel attacks, the problem may lie in the algorithm, in the design, or even in some other component that is used inside the main module. An example of how to solve the previous problem would be to aviod any data-dependent branching or implement dummy operation that are independent of the key.