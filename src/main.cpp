#include <iostream>
#include <string>
#include "Command.h"

using namespace std;

int main() {
    string inputLine;
    getline(cin, inputLine);
    while(!cin.eof()) {
        Command c(inputLine);
        cout << c.print() << endl;
        getline(cin, inputLine);
    }
    return 0;
}
