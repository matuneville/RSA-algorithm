#include "functions.h"

#include "vector"

using namespace std;

typedef __int128 num;

vector<num> RSA_encrypt(num n, num e, string message){
    vector<num> ASCIImessage = convert2ASCII(message);
    vector<num> RSAmessage{};

    for(num i : ASCIImessage)
        RSAmessage.push_back(modularPow(i, e, n));

    return RSAmessage;
}