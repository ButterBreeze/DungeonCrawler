#ifndef VXMLPARSER_H
#define VXMLPARSER_H
#include <iostream>
#include <vector>
#include "database.h"
#include "table.h"

class VXmlParser
{
public:
    virtual std::vector<Database> getDatabasesFromFile(std::string filePath) = 0;
};


#endif // VXMLPARSER_H
