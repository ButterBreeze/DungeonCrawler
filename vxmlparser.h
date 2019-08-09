#ifndef VXMLPARSER_H
#define VXMLPARSER_H
#include <iostream>
#include <vector>
#include "database.h"

class VXmlParser
{
    virtual std::vector<Database> GetDatabasesFromFile(std::string filePath);

};

#endif // VXMLPARSER_H
