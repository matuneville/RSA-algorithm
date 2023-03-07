#include "functions.h"

#include "vector"

using namespace std;

#include <cmath>
typedef __int128 num;

// public and private key generator
vector<num> RSA_Key (){

    srand((unsigned) time(NULL));

    num p = generatePrime(10000000, 1000000000);
    num q = generatePrime(10000000, 1000000000);

    num n = p * q;
    num phi = (p-1)*(q-1);

    // Now find "e" such as is coprime with phi
    num e;
    do {
        e = rand() % (phi-2) + 2;
    } while (gcd(e, phi) != 1);

    num d = modInverse(e, phi);

    return {n, e, d};
}