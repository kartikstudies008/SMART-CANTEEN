#include <iostream>
#include <queue>
#include <fstream>
#include "token.h"

using namespace std;

int main() {
    int currentTokenNumber = 1;
    int choice;
    int totalRevenue = 0;

    queue<Token> normalQueue;
    queue<Token> vipQueue;

    do {
        cout << "\n===== SMART CANTEEN SYSTEM =====\n";
        cout << "1. Take New Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Waiting Queue\n";
        cout << "4. Show Daily Report\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Token t = createToken(currentTokenNumber);

            if (t.isVIP)
                vipQueue.push(t);
            else
                normalQueue.push(t);

            cout << "\nOrder Added Successfully!\n";
            currentTokenNumber++;
        }

        else if (choice == 2) {
            Token served;
            bool servedFlag = false;

            if (!vipQueue.empty()) {
                served = vipQueue.front();
                vipQueue.pop();
                servedFlag = true;
            }
            else if (!normalQueue.empty()) {
                served = normalQueue.front();
                normalQueue.pop();
                servedFlag = true;
            }

            if (servedFlag) {
                cout << "\nNow Serving:\n";
                cout << "Token: " << served.tokenNumber << endl;
                cout << "Customer: " << served.customerName << endl;
                cout << "Item: " << served.item << endl;
                cout << "Price: " << served.price << endl;
                cout << "VIP: " << (served.isVIP ? "Yes" : "No") << endl;

                totalRevenue += served.price;

                // Save to file
                ofstream file("data.txt", ios::app);
                file << served.tokenNumber << ","
                     << served.customerName << ","
                     << served.item << ","
                     << served.price << ","
                     << served.isVIP << endl;
                file.close();
            }
            else {
                cout << "\nNo Orders to Serve.\n";
            }
        }

        else if (choice == 3) {
            if (vipQueue.empty() && normalQueue.empty()) {
                cout << "\nNo Waiting Orders.\n";
            } else {
                cout << "\n--- VIP Queue ---\n";
                queue<Token> tempVIP = vipQueue;
                while (!tempVIP.empty()) {
                    Token t = tempVIP.front();
                    tempVIP.pop();
                    cout << "Token " << t.tokenNumber
                         << " - " << t.customerName
                         << " (" << t.item << ")\n";
                }

                cout << "\n--- Normal Queue ---\n";
                queue<Token> tempNormal = normalQueue;
                while (!tempNormal.empty()) {
                    Token t = tempNormal.front();
                    tempNormal.pop();
                    cout << "Token " << t.tokenNumber
                         << " - " << t.customerName
                         << " (" << t.item << ")\n";
                }
            }
        }

        else if (choice == 4) {
            cout << "\n===== DAILY REPORT =====\n";
            cout << "Total Revenue: " << totalRevenue << endl;
            cout << "VIP Waiting: " << vipQueue.size() << endl;
            cout << "Normal Waiting: " << normalQueue.size() << endl;
        }

        else if (choice == 5) {
            cout << "\nSystem Closed.\n";
        }

        else {
            cout << "\nInvalid Choice.\n";
        }

    } while (choice != 5);

    return 0;
}