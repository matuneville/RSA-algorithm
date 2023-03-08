# RSA Cryptosystem 🔢🔠🔣
This project is an implementation of the Rivest–Shamir–Adleman public-key cryptosystem.
Developed in C++.

## Algorithm working ⚙
The RSA encryption algorithm uses two large prime numbers, p and q, to generate a public and private key pair. The key generation and the encryption and decryption of the message are calculated with some number theory principles, following by the next steps:

1. Choose two large prime numbers, p and q.
2. Calculate n = p * q.
3. Calculate phi(n) = (p-1) * (q-1).
4. Choose a number e such that 1 < e < phi(n) and gcd(e, phi(n)) = 1.
5. Calculate d such that d = e^-1 (mod phi(n)).
6. The public key is the pair (n, e), and the private key is the pair (n, d).

To encrypt a message _M_ using the public key _(n, e)_, we compute c = m^e (mod n). To decrypt the encrypted message _C_ using the private key _(n, d)_, we compute M = C^d (mod n).  

Some interesting arithmetic algorithms are needed for this program, such as the Modular Exponentiation and the Extended Euclidean Algorithm. 

## How-to-use 📤📥
To run the program, first you need to execute `main.cpp`. At the console, you choose wether you want to generate a key, to encrypt a message or to decrypt a encrypted message.  

1. Key generation: The receiver of the message generates a public-private key pair. The public key can be shared with anyone and is used for encryption, while the private key is kept secret and is used for decryption.

2. Encryption: Person A wants to send a message to Person B, who previously generated both public and private key pairs. Person A encrypts the message using Person B's public key.
    - Transmission: Person A sends the encrypted message to Person B over an insecure communication channel, such as the internet.

3. Decryption: Person B receives the encrypted message and decrypts it using their private key.

    - Authentication: To ensure the integrity of the message, Person B can also use their private key to sign the message before sending it back to Person A. Person A can verify the signature using Person B's public key, ensuring that the message was not tampered with during transmission.

## Message transmission example
Alex wants to send a message to Bob.

### **1.** Bob runs the program and select the first option, entering 1:  

<sub>Console output:</sub>
```
Enter 1 to generate a key
Enter 2 to encrypt a message
Enter 3 to decrypt a message
Enter 4 to finish the running program
1
```
&nbsp; &nbsp; &nbsp; &nbsp; The output will be the key pairs:

<sub>Console output:</sub>
```
Yor public key is  (n,e) = (206924232571196639, 18467)
Yor private key is (n,d) = (206924232571196639, 86850583126682675)

Program finished.
```

### **2.** Alex, after being given the public key sent by Bob, selects option 2 to encrypt the message. Then, he must enter the public key and the message to encrypt:

<sub>Console output:</sub>
```
Enter n & e separated with a space:
206924232571196639 18467

Enter the message you want to encrypt with the previous key:
you owe me a beer, Bob
```

&nbsp; &nbsp; &nbsp; &nbsp; Thus, the encrypted message will be printed, and Alex must sent it to Bob:

<sub>Console output:</sub>
```
Your encrypted message is:
147787322645733633 202487013767163311 203065024425582209 194940318183295935 202487013767163311 145913483848123097 149715205604063354 194940318183295935 52414444430127901 149715205604063354 194940318183295935 143035618706740844 194940318183295935 131853107429446003 149715205604063354 149715205604063354 33118807850836336 20378192095849578 194940318183295935 117703768523261622 35645651969635732 149715205604063354 203588970894083069

Program finished.
```

### **3.** Bob, after receiving the ecrypted message sent by Alex, selects the third option to decrypt it. He enters the three values of both private and public keys, and the encrypted message in a single line:

<sub>Console output:</sub>
```
Enter n, e & d separated with a space:
206924232571196639 18467 86850583126682675

Enter the message you want to decrypt separating the numbers with a space:
147787322645733633 ... ... ... ... 203588970894083069
```

&nbsp; &nbsp; &nbsp; &nbsp; Thus, the decrypted message will be printed at the console:

<sub>Console output:</sub>
```
Your decrypted message is:
you owe me a beer, Alex

Program finished.
```