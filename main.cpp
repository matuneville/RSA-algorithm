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

num stringToNum (string num_str){
    num n = 0;
    for (char c : num_str) {
        n = n * 10 + (c - '0');
    }
    return n;
}

vector<num> stringOfNumsToVector(string str){
    vector<string> message{};
    string number = "";
    for (char c : str){
        if (c != ' ')
            number += c;
        else{
            message.push_back(number);
            number = "";
        }
    }
    if (str[str.length()-1] != ' ')
        message.push_back(number);

    vector<num> messageInNums{};
    for (string word : message){
        num i = stringToNum(word);
        messageInNums.push_back(i);
    }

    return messageInNums;
}

int main() {
    int state = 0;


        cout << "Enter 1 to generate a key \nEnter 2 to encrypt a message \nEnter 3 to decrypt a message \nEnter 4 to finish the running program"<< endl;
        cin >> state;

        if (state == 1){
            vector<num> key = RSA_Key();
            cout << "Yor public key is  (n,e) = ("<< key[0] << ", "<< key[1]<< ")"<< endl;
            cout << "Yor private key is (n,d) = ("<< key[0] << ", "<< key[2]<< ")"<< endl;
        }

        else if (state == 2){
            string message;
            string nn, ee;
            cout << "Enter n & e separated with a space: "<< endl;
            cin >> nn >> ee;
            cin.ignore(); // so it does not bug at the getline function

            num n = stringToNum(nn);
            num e = stringToNum(ee);


            cout << "Enter the message you want to encrypt with the previous key: "<< endl;
            getline(cin, message);

            vector<num> encryptedMessage = RSA_encrypt(n, e, message);
            cout << "\nYour encrypted message is: "<< endl;
            for (num i : encryptedMessage){
                cout << i << " ";
            }
            cout << "" << endl;
        }

        else if (state == 3){
            string message, decryptedMessage;
            string nn, ee, dd;
            cout << "Enter n, e & d separated with a space: "<< endl;
            cin >> nn >> ee >> dd;
            cin.ignore(); // so it does not bug at the getline function

            num n = stringToNum(nn);
            num e = stringToNum(ee);
            num d = stringToNum(dd);

            cout << "Enter the message you want to decrypt separating the numbers with a space: "<< endl;
            getline(cin, message);

            vector<num> messageInVector = stringOfNumsToVector(message);
            decryptedMessage = RSA_decrypt(messageInVector, n, e, d);

            cout << "\nYour decrypted message is: \n" << decryptedMessage<< endl;
        }

        else{
            cout << "The entered number does not match with any option. Run again"<< endl;
        }

    cout << "\nProgram finished." << endl;
    return 0;
}
