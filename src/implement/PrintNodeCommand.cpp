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
    return "Print: node nodeid";
}
