#include <iostream>
#include "functions.h"
#include "functions.cpp"
#include "RSA_key.cpp"
#include "RSA_encrypt.cpp"
#include "RSA_decrypt.cpp"

using namespace std;

typedef __int128 num;

std::ostream& operator<<(std::ostream& os, __int128 x) {
    if (x < 0) {
        os << '-';
        x = -x;
    }
    if (x > 9) {
        os << (x / 10);
    }
    os << (char)(x % 10 + '0');
    return os;
}

int main(){
    vector<num> key = RSA_Key();
    cout << key[0] << " " << key[1] << " " << key[2] << endl;
    string message = "esto Es SOl0 un test :D";
    vector<num> encryp = RSA_encrypt(key[0], key[1], message);
    for(num i : encryp) cout << i << " ";
    cout << "" <<endl;
    string decryp = RSA_decrypt(encryp, key[0], key[1], key[2]);
    cout << decryp;
}