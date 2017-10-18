#include <string>
#include <vector>
#include "Command.h"
#include "ModifyCommand.h"

using namespace std;

ModifyCommand::ModifyCommand(vector<string> inputCommands): Command(inputCommands) {
}

ModifyCommand::~ModifyCommand() {
}

string ModifyCommand::execute() {
    return (this->commands.size() < 3)
        ? "Invalid Command"
        : "Modified: resistor name to resistance Ohms";
}
