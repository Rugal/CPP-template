#ifndef COMMAND_H
#define COMMAND_H

#include <functional>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Command {
private:
    vector<string> commands;
    map<string, std::function<string(Command&)>>  funcMap;

    string trimString(const string &inputLine);
    vector<string> splitString(const string& inputLine);
    string deleteR();
    string insertR();
    string modifyR();
    string printNode();
    string printR();
public:
    Command(const string &line);
    ~Command();

    string print();
};

#endif /* COMMAND_H */
