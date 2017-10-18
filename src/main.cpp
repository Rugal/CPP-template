#include <iostream>
#include <string>
#include "Command.h"
#include "CommandFactory.h"

using namespace std;

int main() {
    CommandFactory cf;
    string inputLine;
    getline(cin, inputLine);
    while(!cin.eof()) {
        Command *c = cf.wrapCommand(inputLine);
        cout << c->execute() << endl;
        delete c;
        getline(cin, inputLine);
    }
    return 0;
}
