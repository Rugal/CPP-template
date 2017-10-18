#ifndef MODIFYCOMMAND_H
#define MODIFYCOMMAND_H

#include <string>
#include <vector>
#include "Command.h"

using namespace std;

class ModifyCommand: public Command {
public:
    ModifyCommand(vector<string> commands);
    ~ModifyCommand();

    string execute();
};

#endif /* MODIFYCOMMAND_H */
