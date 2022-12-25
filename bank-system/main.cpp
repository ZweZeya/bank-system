//
//  main.cpp
//  bank-system
//
//  Created by Zwe Zeya on 24/12/22.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "User.hpp"
#include "Bank.hpp"

using namespace std;

// Ask user for account number
long queryAccount() {
    long acc;
    cout<<"Enter account number: ";
    cin>>acc;
    return acc;
};

// Ask user for amount deposit or withdrawal
float queryAmt() {
    float amount;
    cout<<"Enter amount: ";
    cin>>amount;
    return amount;
};

int main(int argc, const char * argv[]) {
    // Creating a bank object
    Bank bank;
    
    // Storing menu options in an array
    const int menuItems = 7;
    string menu[menuItems] = {"Open an Account", "Balance Enquiry", "Deposit", "Withdrawal", "Close an Account", "Show All Accounts", "Quit"};
    
    // Detect user input in choosing the menu options
    while (true) {
        // Display menu options
        cout<<endl;
        for (int i = 1; i <= menuItems; i++) {
            cout<<"       "<<i<<" "<<menu[i - 1]<<endl;
        };
        cout<<endl<<"Enter your choice: ";
        int choice;
        cin>>choice;
        switch(choice) {
            case 1: {
                string fname, lname;
                float ibal;
                cout<<"Enter First Name: ";
                cin>>fname;
                cout<<"Enter Last Name: ";
                cin>>lname;
                cout<<"Enter Initial Balance: ";
                cin>>ibal;
                bank.addUser(fname, lname, ibal);
                cout<<endl<<"Congratulations, account created successfully"<<endl;
                cout<<endl<<bank.getLast();
                break;
            }
            case 2: {
                long acc = queryAccount();
                User foundUser = bank.getAccountDetails(acc);
                if (!bank.validateAccount(acc)) {
                    cout<<"No such account"<<endl;
                } else {
                    cout<<endl<<"Account Details"<<endl;
                    cout<<foundUser<<endl;
                };
                break;
            }
            case 3: {
                long acc = queryAccount();
                if (!bank.validateAccount(acc)) {
                    cout<<"No such account"<<endl;
                } else {
                    float amt = queryAmt();
                    cout<<bank.deposit(acc, amt)<<endl;
                };
                break;
            }
            case 4: {
                long acc = queryAccount();
                if (!bank.validateAccount(acc)) {
                    cout<<"No such account"<<endl;
                } else {
                    float amt = queryAmt();
                    if (!bank.checkWithdrawl(acc, amt)) {
                        cout<<"Insufficent balance"<<endl;
                    } else {
                        cout<<bank.withdraw(acc, amt)<<endl;
                    };
                };
                break;
            }
            case 5: {
                long acc = queryAccount();
                if (!bank.validateAccount(acc)) {
                    cout<<"No such account"<<endl;
                } else {
                    bank.removeAccount(acc);
                    cout<<"Account successfully closed"<<endl;
                };
                break;
            }
            case 6: {
                bank.showAll();
                break;
            }
            case 7: {
                return 0;
            }
            default:
                cout<<"Invalid menu option";
        }
    }

    // return 0;
}
