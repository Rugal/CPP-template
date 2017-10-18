#ifndef DELETECOMMAND_H
#define DELETECOMMAND_H

#include <string>
#include <vector>
#include "Command.h"

using namespace std;

class DeleteCommand: public Command {
public:
    DeleteCommand(vector<string> commands);
    ~DeleteCommand();

    string execute();
};

#endif /* DELETECOMMAND_H */
