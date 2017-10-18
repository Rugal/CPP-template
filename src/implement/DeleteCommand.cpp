#include <string>
#include <vector>
#include "Command.h"
#include "DeleteCommand.h"

using namespace std;

DeleteCommand::DeleteCommand(vector<string> inputCommands): Command(inputCommands) {
}

DeleteCommand::~DeleteCommand() {
}

string DeleteCommand::execute() {
    if (this->commands.size() < 2)
        return "Invalid Command";

    return this->commands[1].compare("all")
        ? "Deleted: resistor name"
        : "Deleted: all resistors";
}
