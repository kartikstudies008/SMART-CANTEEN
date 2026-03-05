#include "token.h"
#include <iostream>

using namespace std;

Token createToken(int tokenNumber) {
    Token t;
    t.tokenNumber = tokenNumber;

    cout << "Enter customer name: ";
    cin >> t.customerName;

    cout << "Enter item name: ";
    cin >> t.item;

    cout << "Enter price: ";
    cin >> t.price;

    cout << "Is VIP? (1 for Yes, 0 for No): ";
    cin >> t.isVIP;

    return t;
}