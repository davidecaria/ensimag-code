# Lecture notes - 2023/09/20 - Introduction and refresh 2

## Electronic signature

This is one of the building blocks of our secure architecture course.
The idea is to have something that has the following property:
- Authentic
- Unforgeable
- Non-reusable
- Immutable
- Non-repudiation

**Authentic**
The signature that we are looking for has to convince the receiver, and we must be able to prove that it is authentic.

**Unforgeable**
The signature cannot be tampered with and nobody, except the creator, should be able to use it.

**Non-reusable**
It should be something that we do not copy-paste from one element to another.

**Immutable**
Any violation should break the signature and void its use, nobody should be able to alter it and still prove its validity.

**Non-repudiation**
The signature cannot be denied once it has been used by the user.

### How can we sign something?

The usual process requires the user to create an hash of what he wants to sign. Then the hash is ciphered with the private key (previously generated) and the result is appended to the object that we want to sign.

**Example**
Alice wants to send a document to Bob. She wants to make sure that Bob can trust the docuemtn and its content but she is not interested in confidentiality.
Alice generates a key pair (Kpri and Kpub) and create the hash of the initial docuemnt. She can now sign the hash with her Kpri and sent the result along with the document.

Document ---> Hash ---> Signature

Alice may chose many hashing algorithms and various standards for the key pair.

### Definition of an electronic signature
It is a combination of the following elements:

- KeyGen function
- Sig function
- Verif function

Those three functions are use to provide the basic functionalities of the electonic signature system. The KeyGen funciton is used to generate Kpri and Kpub. the Sig function is used to create the signature itself. The verif function is used to verifiy the validity of the signature.

| Function  | Input         | Output        |
| --------  | ------------- | ------------- |
| KeyGen    | 1<sup>λ</sup> | Kpriv, Kpub   |
| Sig       | M,Kpriv       | σ             |
| Verif     | M,σ,Kpub      | True OR False |

The algorithm that we use for each of those function has a malginal importance, what really matters is that the three of them satify the following properties:

- Correctness: This means that Verif should return true, if the the signature has not been forged and it has been created correctly.
- Unforgeability: This means that Verif should return false if the signature has been forged or if it has been created in a wrong way.
- Coherancy: A valid signature must always be valid (now, tomorrow and in 100 years).

**NOTA BENE**
The property of Unforgeability is closely related to the concept of Hardness of a hash/key. We say that the Hashing algorithm is strong enough if there is not polinomial time algorithm that can break it.

### Extra concepts

**PSS** and **DSS**

PSS (Probabilistic Signature Scheme):
- PSS is a probabilistic padding scheme commonly used with RSA (Rivest-Shamir-Adleman) digital signatures.
- It helps improve the security of RSA signatures by introducing an element of randomness into the process.
- The randomness in the padding scheme makes it more resistant to certain types of cryptographic attacks, such as those based on chosen plaintext or adaptive chosen ciphertext scenarios.
- PSS padding includes a hash function and a mask generation function, adding complexity to the signature generation process.

DSS (Digital Signature Standard):
- DSS is a Federal Information Processing Standard (FIPS) for digital signatures, originally proposed by the National Institute of Standards and Technology (NIST) in the United States.
- DSS specifies the algorithms and procedures for the generation and verification of digital signatures based on the Digital Signature Algorithm (DSA).
- DSA is a specific public-key algorithm used for digital signatures, and it relies on modular arithmetic and discrete logarithm problem for its security.
- DSS includes specifications for the generation of digital signatures, the generation of digital signature keys, and the verification of digital signatures.

## Key Exchange

The problem of exchanges a key traces back to the problem of communication. Many times, when looking at communication protocols, we assument that the users involved have already exchanged the related key (symmetric or asymmetric). This is a non-trivial task that is normally adressed by key exchange algorithm. Among them, Diffie-Hellman algorithm holds a key place due to historical and technical reasons.
