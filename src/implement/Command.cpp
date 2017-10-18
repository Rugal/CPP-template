#include <string>
#include <vector>
#include "Command.h"

using namespace std;

Command::Command() {
}

Command::Command(vector<string> inputCommands) {
    this->commands = inputCommands;
}

Command::~Command() {
}
