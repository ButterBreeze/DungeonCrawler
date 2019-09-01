#ifndef XMLPARSER_H
#define XMLPARSER_H
#include "vxmlparser.h"
#include "tinyxml2.h"
#include "table.h"
#include "database.h"

class XmlParser :  public VXmlParser
{
private:
    std::vector<Table> getTablesFromFiles(std::vector<std::string> tables);

public:
    std::vector<Database> getDatabasesFromFile(std::string filePath) override;
};

#endif // XMLPARSER_H
