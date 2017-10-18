#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>

using namespace std;

class Command {
protected:
    vector<string> commands;
public:
    Command();
    Command(vector<string> commands);
    virtual ~Command();

    virtual string execute() {return "Invalid Command";}
};

#endif /* COMMAND_H */
