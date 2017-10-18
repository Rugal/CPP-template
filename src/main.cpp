#include <iostream>
#include <string>
#include "Command.h"

using namespace std;


int main() {
    string inputLine;
    getline(cin, inputLine);
    Command c(inputLine);
    cout << c.print() << endl;
    return 0;
}
