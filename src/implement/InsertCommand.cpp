#include <string>
#include <vector>
#include "Command.h"
#include "InsertCommand.h"

using namespace std;

InsertCommand::InsertCommand(vector<string> inputCommands): Command(inputCommands) {
}

InsertCommand::~InsertCommand() {
}

string InsertCommand::execute() {
    return "Inserted: resistor name resistance Ohms nodeid -> nodeid";
}
