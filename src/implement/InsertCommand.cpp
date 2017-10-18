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
    return (this->commands.size() < 5)
        ? "Invalid Command"
        : "Inserted: resistor " + this->commands[1] + " " + this->commands[2] + " Ohms "+ this->commands[3] +" -> " + this->commands[4];
}
