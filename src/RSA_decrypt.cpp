#include "functions.h"

using namespace std;

typedef __int128 num;

string RSA_decrypt(vector<num> message, num n, num e, num d){

    string decryptedMessage = "";
    for(num i : message){
        int ASCIIchar = modularPow(i, d, n) % 256;
        decryptedMessage += char(ASCIIchar);
    }

    return decryptedMessage;
}