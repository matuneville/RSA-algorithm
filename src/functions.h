using namespace std;

#include "vector"
#include "string"

#include <cstdint>
typedef __int128 num;

num modularPow(num base, num exponent, num modulus);
bool isPrime(num n);
num generatePrime(num start, num end);
num modInverse(num a, num b);
num gcd(num a, num b);
vector<num> convert2ASCII (string& message);