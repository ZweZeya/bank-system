//
//  User.hpp
//  bank-system
//
//  Created by Zwe Zeya on 25/12/22.
//

#ifndef User_hpp
#define User_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

// Defining a user class
class User {
    
private:
    string firstName;
    string lastName;
    float balance;
    long accNum;

protected:
    User(string firstName, string lastName, long accNum, float balance);
    friend ofstream & operator<<(ofstream &ofs, User user);
    
public:
    friend ostream & operator<<(ostream &os, User user);
    
    friend class Bank;
};


#endif /* User_hpp */
