#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include <string>
#include <vector>
#include "Command.h"

using namespace std;

class CommandFactory {
private:
    string trimString(const string &inputLine);
    vector<string> splitString(const string &inputLine);
    Command* dispatchCommand(const vector<string> commands);
public:
    CommandFactory();
    ~CommandFactory();

    Command* wrapCommand(const string &inputLine);
};

#endif /* COMMANDFACTORY_H */
