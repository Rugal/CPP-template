#include <sstream>
#include <string>
#include <vector>
#include "Command.h"
#include "InsertCommand.h"
#include "ModifyCommand.h"
#include "CommandFactory.h"

string CommandFactory::trimString(const string &inputLine) {
    stringstream stringStream(inputLine);
    string actualLine;
    getline(stringStream >> ws, actualLine);

    return actualLine;
}

vector<string> CommandFactory::splitString(const string& inputLine) {
    vector<string> result;
    istringstream iss(inputLine);
    for(string s; iss >> s; )
        result.push_back(s);

    return result;
}

CommandFactory::CommandFactory() {
}

CommandFactory::~CommandFactory() {
}

Command* CommandFactory::dispatchCommand(const vector<string> commands) {
    if (commands.empty()) {
        return new Command(commands);
    }
    if (!commands[0].compare("insertR")) {
        return new InsertCommand(commands);
    }
    if (!commands[0].compare("modifyR")) {
        return new InsertCommand(commands);
    }
    return new Command(commands);
}

Command* CommandFactory::wrapCommand(const string &inputLine) {
    vector<string> result = this->splitString(this->trimString(inputLine));
    return this->dispatchCommand(result);
}
