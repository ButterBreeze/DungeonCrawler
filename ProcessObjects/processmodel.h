#ifndef PROCESSMODEL_H
#define PROCESSMODEL_H
#include <iostream>
#include "vxmlparser.h"
#include <vector>
#include "database.h"
class ProcessModel
{
private:
    std::vector<Database> getFilesToParse();
 VXmlParser* xmlParser;

public:
    ProcessModel(VXmlParser* vXmlParser);

};

#endif // PROCESSMODEL_H
