#include "xmlparser.h"

XmlParser::XmlParser()
{

}
std::vector<Database> GetDatabasesFromFile(std::string filePath)
{
    //setup for the config file
    tinyxml2::XMLDocument configFile;

    tinyxml2::XMLError eResult = configFile.LoadFile(filePath.c_str());


    if(eResult != tinyxml2::XML_SUCCESS)
    {
        throw std::runtime_error("could not open config file");
    }
    tinyxml2::XMLNode* configRoot = configFile.FirstChild();

    //gonna grab the database's inside of the config
    std::vector<std::string> databaseNames;
    tinyxml2::XMLElement* database;
    if((database = configRoot->FirstChildElement("database")) == nullptr)
    {
        throw std::runtime_error("Config file had no database elements");
    }
    do
    {
        databaseNames.push_back(database->GetText());
    } while(configRoot->NextSiblingElement("database") != nullptr);

    //gonna grab all the database xml files for the tables in them and where to place them


    std::vector<std::string> directoriesToParse;
    for(unsigned int i = 0; i < databaseNames.size(); i++)//todo: fix this by making database a folder
    {
        std::vector<std::string> tables;
        tinyxml2::XMLDocument databaseDoc;
        tinyxml2::XMLError eResult = databaseDoc.LoadFile(databaseNames[i].c_str());

        if(eResult != tinyxml2::XML_SUCCESS)
        {
            throw std::runtime_error("could not open config file");
        }
        tinyxml2::XMLNode* databaseRoot = databaseDoc.FirstChild();

        tinyxml2::XMLElement* table;
        if((table = databaseRoot->FirstChildElement("table")) == nullptr)
        {
            throw std::runtime_error("Database file had no database elements");
        }
        do
        {
            tables.push_back(table->GetText());
        } while(configRoot->NextSiblingElement("table") != nullptr);

    }
}


std::vector<Table> getTablesFromFiles(std::vector<std::string> tables)
{

}

