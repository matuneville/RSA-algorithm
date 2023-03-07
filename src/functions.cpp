#include "functions.h"

using namespace std;
#include <random>

typedef __int128 num;

// most efficient way to make modular exponentiation, used to encrypt n decrypt
num modularPow(num base, num exponent, num modulus) {
    num result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent /= 2;
    }
    return result;
}

bool isPrime(num n) {
    if (n <= 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    for (num i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// generate a prime number within a range [start, end]
num generatePrime(num start, num end) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<num> dis(start, end);

    num n;
    do {
        n = dis(gen);
    } while (!isPrime(n));
    return n;
}

// calculate modular multiplicative inverse
num modInverse(num a, num b) {
    num b0 = b, t, q;
    num x0 = 0, x1 = 1;
    if (b == 1) return 1;
    while (a > 1) {
        q = a / b;
        t = b, b = a % b, a = t;
        t = x0, x0 = x1 - q * x0, x1 = t;
    }
    if (x1 < 0) x1 += b0;
    return x1;
}

// calculate gcd with euclidean algorithm
num gcd(num a, num b){
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        }
        else {
            b = b % a;
        }
    }
    if (a == 0) {
        return b;
    }
    return a;
}

vector<num> convert2ASCII (string& message){
    vector<num> ASCIImessage = {};

    for (char i : message)
        ASCIImessage.push_back(num(i));

    return ASCIImessage;
}