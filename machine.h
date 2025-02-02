#ifndef MACHINE_H
#define MACHINE_H

#include <bits/stdc++.h>
#include "register.h"
#include "memory.h"
#include "instructions.h"

using namespace std;

class Machine {
private:
    Memory machineMemory;
    Register machineRegister;
public:
    Machine();
    void getMemory();
    void getRegister();
    void runInstruction(Memory& mem, Register& reg, Instructions& inst);
    void showScreenOutput();
    void runAll(Memory& mem, Register& reg, Instructions& inst);
    void runStepByStep(Memory& mem, Register& reg, Instructions& inst);
};

#endif // MACHINE_H
