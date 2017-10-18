#ifndef INSERTCOMMAND_H
#define INSERTCOMMAND_H

#include <string>
#include <vector>
#include "Command.h"

using namespace std;

class InsertCommand: public Command {
public:
    InsertCommand(vector<string> commands);
    ~InsertCommand();

    string execute();
};

#endif /* INSERTCOMMAND_H */
