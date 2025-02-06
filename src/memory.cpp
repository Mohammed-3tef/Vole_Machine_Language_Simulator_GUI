#include "../include/memory.h"

#include <bits/stdc++.h>

using namespace std;


// Constructor to initialize the array with 0 in all cells
Memory::Memory() {
    for (int i = 0; i < 256; i++) {
        memory[i] = "00";
    }
}

// Getter to read from memory
string Memory::getMemory(int address) {
    return memory[address];
}

// Setter to write in the memory
void Memory::setMemory(int address, string value) {
    memory[address] = value;
}

bool Memory::checkDecimal(const string &str) {
    for (char i: str) {
        // Check if the character is a valid decimal number.
        if (!isdigit(i)) return false;
    }
    return true;
}

string Memory::getInstruction() {
    return memory[counter] + memory[counter + 1];
}

int Memory::getCounter(){
    return counter;
}

void Memory::setCounter(int n){
    counter = n;
}

void Memory::setInstructions(vector<string>instruct, int count){
    int c = counter;

    // Load the program into the memory.
    for (int i = 0; i < int(instruct.size()); ++i) {
        memory[c] = instruct[i].substr(0, 2);
        ++c;
        memory[c] = instruct[i].substr(2);
        ++c;
    }
}
