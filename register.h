#ifndef REGISTER_H
#define REGISTER_H

#include <bits/stdc++.h>
using namespace std;

class Register {
private:
    vector<string> registers = vector<string>(16);

public:
    Register();
    void setRegister(const string& Address, const string& Value);
    string getRegister(const string& location);
    void displayRegister();
};

#endif // REGISTER_H
