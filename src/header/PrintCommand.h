#ifndef PRINTCOMMAND_H
#define PRINTCOMMAND_H

#include <string>
#include <vector>
#include "Command.h"

using namespace std;

class PrintCommand: public Command {
public:
    PrintCommand(vector<string> commands);
    ~PrintCommand();

    string execute();
};

#endif /* PRINTCOMMAND_H */
