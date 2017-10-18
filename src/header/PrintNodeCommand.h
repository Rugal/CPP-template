#ifndef PRINTNODECOMMAND_H
#define PRINTNODECOMMAND_H

#include <string>
#include <vector>
#include "Command.h"

using namespace std;

class PrintNodeCommand: public Command {
public:
    PrintNodeCommand(vector<string> commands);
    ~PrintNodeCommand();

    string execute();
};

#endif /* PRINTNODECOMMAND_H */
