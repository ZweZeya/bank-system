//
//  User.cpp
//  bank-system
//
//  Created by Zwe Zeya on 25/12/22.
//

#include "User.hpp"
#include <iostream>
#include <fstream>

using namespace std;

// Constructor
User::User(string firstName, string lastName, long accNum, float balance) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->accNum = accNum;
    this->balance = balance;
};

// Operator overload to display the user object
ostream & operator<<(ostream &os, User user) {
    os<<"First Name: "<<user.firstName<<endl;
    os<<"Last Name: "<<user.lastName<<endl;
    os<<"Account Number: "<<user.accNum<<endl;
    os<<"Balance: "<<user.balance<<endl;
    return os;
};

// Operator overload to write user object in a txt file
ofstream & operator<<(ofstream &ofs, User user) {
    ofs<<user.firstName<<" ";
    ofs<<user.lastName<<" ";
    ofs<<user.accNum<<" ";
    ofs<<user.balance<<endl;
    return ofs;
};



