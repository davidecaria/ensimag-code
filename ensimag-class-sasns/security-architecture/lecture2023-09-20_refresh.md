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
| KeyGen    | 1<sup>λ</sup> | Kpriv, Kpub   |
| Sig       | M,Kpriv       | σ             |
| Verif     | M,σ,Kpub      | True OR False |