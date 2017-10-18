#ifndef PARSER_H
#define PARSER_H

#include <string>
#include "Command.h"
#include "CommandFactory.h"

using namespace std;

class Parser {
private:
    CommandFactory factory;
public:
    Parser();
    Command* parse(const string &line);

};

#endif /* PARSER_H */
