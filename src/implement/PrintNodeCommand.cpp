#include <string>
#include <vector>
#include "Command.h"
#include "PrintNodeCommand.h"

using namespace std;

PrintNodeCommand::PrintNodeCommand(vector<string> inputCommands): Command(inputCommands) {
}

PrintNodeCommand::~PrintNodeCommand() {
}

string PrintNodeCommand::execute() {
    if (this->commands.size() < 2)
        return "Invalid Command";

    return this->commands[1].compare("all")
        ? "Print: node nodeid"
        : "Print: all resistors";
}
