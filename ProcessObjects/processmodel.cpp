#include "processmodel.h"


ProcessModel::ProcessModel(VXmlParser* vXmlParser)
    : xmlParser(vXmlParser)
{

}



///
/// \brief getFilesToParse
/// \return directories to parse throws error if something be wrong with the config file
///
std::vector<Database> ProcessModel::getFilesToParse()
{
    std::vector<Database> databases = std::vector<Database>();

    return databases;
}
