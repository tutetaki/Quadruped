#include "Behaviour.h"
#include "Parameters.h"

int Behaviour::count = 0;

Behaviour::Behaviour() {
    count++;
}

void Behaviour::setFlag(bool f) {
    _flag = f;
}

bool Behaviour::getFlag() {
    return _flag;
}

int* Behaviour::getPulses() {
    return _pulses;
}
