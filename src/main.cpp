#include <iostream>
#include <string>
#include "Command.h"
#include "CommandFactory.h"

using namespace std;

int main() {
    CommandFactory cf;
    string inputLine;
    for(cout << "-> ", getline(cin, inputLine); !cin.eof(); cout << "-> ", getline(cin, inputLine)) {
        if (inputLine.empty())
            continue;
        Command *c = cf.wrapCommand(inputLine);
        cout << c->execute() << endl;
        delete c;
    }
    return 0;
}
