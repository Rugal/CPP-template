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
    return "Print: resistor name";
}
