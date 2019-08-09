#include "processmodel.h"


ProcessModel::ProcessModel(VXmlParser vXmlParser)
{
 xmlParser = vXmlParser;
}

///
/// \brief getFilesToParse
/// \return directories to parse throws error if something be wrong with the config file
///
