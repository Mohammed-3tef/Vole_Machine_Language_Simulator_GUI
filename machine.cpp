#include "machine.h"
#include "memory.h"
#include "register.h"
#include "instructions.h"

#include <bits/stdc++.h>
using namespace std;

Machine::Machine(){}

void Machine::showScreenOutput() {

    cout << "\nWhat shows on screen in Hexa: " << hex << endl;
}

void Machine::runStepByStep(Memory& mem, Register& reg, Instructions& inst) {

}
