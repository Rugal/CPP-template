#include <string>
#include <vector>
#include "Command.h"

using namespace std;

Command::Command(vector<string> inputCommands) {
    this->commands = inputCommands;
}

Command::~Command() {
}
