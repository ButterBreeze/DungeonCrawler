#ifndef PROCESSMODEL_H
#define PROCESSMODEL_H
#include <iostream>
#include "vxmlparser.h"
#include <vector>
class ProcessModel
{
private:
 std::vector<std::string> getFilesToParse();
 VXmlParser xmlParser;
public:
    ProcessModel(VXmlParser vXmlParser);

};

#endif // PROCESSMODEL_H
