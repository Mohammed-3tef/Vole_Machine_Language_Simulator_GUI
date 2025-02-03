#include "../include/register.h"
#include "ui_mainwindow.h"

#include <bits/stdc++.h>
using namespace std;

Register::Register() {
    for(string& Value: registers) {
        Value = "00";
    }
}

void Register::setRegister(const string& address, const string& value) {
    int index = stoi(address,nullptr,16);
    registers[index] = value;
}

string Register::getRegister(const string& address) {
    int index = stoi(address, nullptr,16);
    return registers[index];
}
