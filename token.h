#ifndef TOKEN_H
#define TOKEN_H

#include <string>
using namespace std;

struct Token {
    int tokenNumber;
    string customerName;
    string item;
    int price;
    bool isVIP;
};

Token createToken(int tokenNumber);

#endif