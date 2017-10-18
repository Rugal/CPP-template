#include <string>
#include <vector>
#include "Command.h"
#include "PrintCommand.h"

using namespace std;

PrintCommand::PrintCommand(vector<string> inputCommands): Command(inputCommands) {
}

PrintCommand::~PrintCommand() {
}

string PrintCommand::execute() {
    if (this->commands.size() < 2)
        return "Invalid Command";

    return this->commands[1].compare("all")
        ? "Print: resistor name"
        : "Print: all resistors";
}
