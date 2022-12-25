//
//  Bank.cpp
//  bank-system
//
//  Created by Zwe Zeya on 25/12/22.
//

#include <iostream>
#include <fstream>
#include "Bank.hpp"
#include "User.hpp"

using namespace std;

// Create a bank object
Bank::Bank() {
    ifstream fusers;
    fusers.open("Users.txt");
    ifstream facc;
    facc.open("Account.txt");
    
    // Create users.txt file if it does not exist
    if (!fusers) {
        ofstream usersFile("Users.txt");
        usersFile.close();
    };
    
    // Create account.txt file if it does not exist
    if (!facc) {
        ofstream accountFile("Account.txt");
        accounts = 0;
        accountFile<<accounts;
        accountFile.close();
    };
    
    // Read the contents of the file into a vector
    while (!fusers.eof()) {
        string firstName, lastName;
        int accNum;
        float balance;
        fusers>>firstName>>lastName>>accNum>>balance;
        if (firstName != "") {
            User user(firstName, lastName, accNum, balance);
            users.push_back(user);
        };
    };
    facc>>accounts;
    
    fusers.close();
    facc.close();
};

// Add a new user
void Bank::addUser(string firstName, string lastName, float balance) {
    User newUser(firstName, lastName, ++accounts, balance);
    users.push_back(newUser);
    ofstream fusers("Users.txt", ios::app);
    fusers<<newUser;
    ofstream facc("Account.txt", ios::trunc);
    facc<<accounts;
    
    fusers.close();
    facc.close();
};

// Get the last account in the list
User Bank::getLast() {
    return users.back();
};

// Get number of accounts
long Bank::getAccounts() {
    return accounts;
};

// Display all the current accounts
void Bank::showAll() {
    for (vector<User>::iterator it = users.begin(); it != users.end(); it++) {
        cout<<endl<<"First Name: "<<it->firstName<<endl;
        cout<<"Last Name: "<<it->lastName<<endl;
        cout<<"Account Number: "<<it->accNum<<endl;
        cout<<"Balance: "<<it->balance<<endl;
    };
};

// Check if account exists
bool Bank::validateAccount(long acc) {
    for (vector<User>::iterator it = users.begin(); it != users.end(); it++) {
        if (it->accNum == acc) {
            return true;
        };
    };
    return false;
};

//Get a specific account
User Bank::getAccountDetails(long acc) {
    for (vector<User>::iterator it = users.begin(); it != users.end(); it++) {
        if (it->accNum == acc) {
            return *it;
        };
    };
    User temp("", "", -1, 0);
    return temp;
};

// Update user account details in file
void Bank::updateAccounts() {
    ofstream fusers("Users.txt", ios::trunc);
    for (vector<User>::iterator it = users.begin(); it != users.end(); it++) {
        fusers<<*it;
    };
    fusers.close();
};

// Deposit to a specific account
User Bank::deposit(long acc, float amt) {
    for (vector<User>::iterator it = users.begin(); it != users.end(); it++) {
        if (it->accNum == acc) {
            it->balance += amt;
            updateAccounts();
            return *it;
        };
    };
    User temp("", "", -1, 0);
    return temp;
};

// Check if balance is sufficient for withdrawal
bool Bank::checkWithdrawl(long acc, float amt) {
    for (vector<User>::iterator it = users.begin(); it != users.end(); it++) {
        if (it->accNum == acc) {
            if (it->balance >= amt) {
                return true;
            };
        };
    };
    return false;
};

// Withdraw from a specific account
User Bank::withdraw(long acc, float amt) {
    for (vector<User>::iterator it = users.begin(); it != users.end(); it++) {
        if (it->accNum == acc) {
            it->balance -= amt;
            updateAccounts();
            return *it;
        };
    };
    User temp("", "", -1, 0);
    return temp;
};

// Remove a specific account
void Bank::removeAccount(long acc) {
    int index;
    for (int i = 0; i < users.size(); i++) {
        if (users[i].accNum == acc) {
            index = i;
            users.erase(users.begin() + index);
            updateAccounts();
        };
    };
};


