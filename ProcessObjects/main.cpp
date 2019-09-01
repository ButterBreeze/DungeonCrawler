#include <iostream>
#include "processmodel.h"
#include "xmlparser.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    VXmlParser *asdf = new XmlParser();
    ProcessModel processModel = ProcessModel(asdf);
    return 0;
}