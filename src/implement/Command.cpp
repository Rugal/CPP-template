#include <functional>
#include <map>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Command.h"

using namespace std;

string Command::trimString(const string &inputLine) {
    stringstream stringStream(inputLine);
    string actualLine;
    getline(stringStream >> ws, actualLine);

    return actualLine;
}

vector<string> Command::splitString(const string& inputLine) {
    vector<string> result;
    istringstream iss(inputLine);
    for(string s; iss >> s; )
        result.push_back(s);

    return result;
}

Command::Command(const string &line) {
    this->commands = splitString(trimString(line));
    this->funcMap["deleteR"] = &Command::deleteR;
    this->funcMap["insertR"] = &Command::insertR;
    this->funcMap["modifyR"] = &Command::modifyR;
    this->funcMap["printNode"] = &Command::printNode;
    this->funcMap["printR"] = &Command::printR;
}

Command::~Command() {
}

string Command::print() {
    cout << this->commands[0] << endl;
    return this->funcMap[this->commands[0]](*this);
}

string Command::insertR() {
    return "Inserted: resistor name resistance Ohms nodeid -> nodeid";
}

string Command::modifyR() {
    return "Modified: resistor name to resistance Ohms";
}

string Command::printR() {
    return "Print: resistor name";
}

string Command::printNode() {
    return "Print: node nodeid";
}

string Command::deleteR() {
    return "Deleted: resistor name";
}
