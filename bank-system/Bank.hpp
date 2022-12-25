//
//  Bank.hpp
//  bank-system
//
//  Created by Zwe Zeya on 25/12/22.
//

#ifndef Bank_hpp
#define Bank_hpp

#include <stdio.h>
#include "User.hpp"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Defining a bank class
class Bank {

private:
    long accounts;
    vector<User> users;

public:
    Bank();
    void addUser(string firstName, string lastName, float balance);
    User getLast();
    long getAccounts();
    void showAll();
    void updateAccounts();
    bool validateAccount(long acc);
    User getAccountDetails(long acc);
    User deposit(long acc, float amt);
    bool checkWithdrawl(long acc, float amt);
    User withdraw(long acc, float amt);
    void removeAccount(long acc);
    

    friend class User;
};


#endif /* Bank_hpp */

