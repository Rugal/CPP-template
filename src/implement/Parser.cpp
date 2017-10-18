#include <string>
#include <vector>
#include "Command.h"
#include "CommandFactory.h"
#include "Parser.h"

using namespace std;

Parser::Parser() {
}

Command* Parser::parse(const string &inputLine) {
    return (inputLine.empty())
        ? new Command()
        : this->factory.wrapCommand(inputLine);
}
