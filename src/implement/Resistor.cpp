#include <algorithm>
#include <string>
#include "Resistor.h"

using namespace std;

Resistor::Resistor(int rIndex_, string name_, double resistance_, int endpoints_[2]) {
    this->rIndex = rIndex_;
    this->name = name_;
    this->resistance = resistance_;
    std::copy(this->endpointNodeIDs, this->endpointNodeIDs + CONNECTION, endpoints_);
}

Resistor::~Resistor() {
}

string Resistor::getName() const{
    return this->name;
}
double Resistor::getResistance() const{
    return this->resistance;
}
void Resistor::setResistance (double resistance_) {
    this->resistance = resistance_;
}

void Resistor::print() {
}
