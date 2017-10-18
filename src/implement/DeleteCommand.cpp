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
    return "Deleted: resistor name";
}
