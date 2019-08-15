#include "xmlparser.h"

XmlParser::XmlParser()
{

}
std::vector<Database> XmlParser::GetDatabasesFromFile(std::string filePath)
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
    tinyxml2::XMLElement* databaseDoc;
    if((databaseDoc = configRoot->FirstChildElement("database")) == nullptr)
    {
        throw std::runtime_error("Config file had no database elements");
    }
    do
    {
        databaseNames.push_back(databaseDoc->GetText());
    } while(configRoot->NextSiblingElement("database") != nullptr);

    //gonna grab all the database xml files for the tables in them and where to place them


    std::vector<Database> databases;

    for(unsigned int i = 0; i < databaseNames.size(); i++)//todo: fix this by making database a folder
    {
        std::vector<std::string> tableNames;
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
            tableNames.push_back(table->GetText());
        } while(databaseRoot->NextSiblingElement("table") != nullptr);

        Database database;
        database.setName(databaseNames[i]);
        database.addTables(getTablesFromFiles(tableNames));
    }
    return databases;
}


std::vector<Table> XmlParser::getTablesFromFiles(std::vector<std::string> tableNames)
{
    std::vector<Table> tables;
    for(unsigned int i = 0; i< tableNames.size(); i++)
    {
        tinyxml2::XMLDocument tableDoc;
        tinyxml2::XMLError eResult = tableDoc.LoadFile(tableNames[i].c_str());
        if(eResult != tinyxml2::XML_SUCCESS)
        {
            throw std::runtime_error("could not open config file");
        }
        tinyxml2::XMLNode* tableRoot = tableDoc.FirstChild();
        tinyxml2::XMLElement* column;
        if((column = tableRoot -> FirstChildElement("column")) == nullptr)
        {
             throw std::runtime_error("Table file had no database elements");
        }
        do
        {
            //todo: add columns
        } while(tableRoot-> NextSiblingElement("columnn") != nullptr);

    }

    return tables;
}

