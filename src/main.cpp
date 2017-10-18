#include <iostream>
#include <string>
#include "Command.h"
#include "Parser.h"

using namespace std;

int main() {
    Parser p;
    string inputLine;
    for(cout << "-> ", getline(cin, inputLine); !cin.eof(); cout << "-> ", getline(cin, inputLine)) {
        if (inputLine.empty())
            continue;
        Command *c = p.parse(inputLine);
        cout << c->execute() << endl;
        delete c;
    }
    return 0;
}
