#ifndef MEMORY_H
#define MEMORY_H

#include <bits/stdc++.h>
using namespace std;

class Memory {
private:
    std::array<string , 256> memory;
    int counter = 1;
public:
    Memory();
    string getMemory(int address);
    void setMemory(int address, string value);
    bool checkDecimal(const string& str);
    string getInstruction ();
    void setInstructions(vector<string>instruct);
    int getCounter();
    void setCounter(int n);
};

#endif // MEMORY_H
