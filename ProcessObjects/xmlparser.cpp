#include "xmlparser.h"



std::vector<Database> XmlParser::getDatabasesFromFile(std::string filePath)
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
    tinyxml2::XMLElement* databaseElement;
    if((databaseElement = configRoot->FirstChildElement("database")) == nullptr)
    {
        throw std::runtime_error("Config file had no database elements");
    }
    do
    {
        databaseNames.emplace_back(databaseElement->GetText());
    } while(configRoot->NextSiblingElement("database") != nullptr);

    //gonna grab all the database xml files for the tables in them and where to place them
    std::vector<Database> databases;

    for (std::string &databaseName : databaseNames)//todo: fix this by making database a folder
    {
        std::vector<std::string> tableNames;
        tinyxml2::XMLDocument databaseDoc;
        tinyxml2::XMLError eResultDatabase = databaseDoc.LoadFile(databaseName.c_str());

        if(eResultDatabase != tinyxml2::XML_SUCCESS)
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
            tableNames.emplace_back(table->GetText());
        } while(databaseRoot->NextSiblingElement("table") != nullptr);

        Database database;
        database.setName(databaseName);
        database.addTables(getTablesFromFiles(tableNames));
    }
    return databases;
}

std::vector<Table> XmlParser::getTablesFromFiles(std::vector<std::string> tableNames)
{
    std::vector<Table> tables;
    for (std::string &tableName : tableNames) {

        tinyxml2::XMLDocument tableDoc;
        tinyxml2::XMLError eResult = tableDoc.LoadFile(tableName.c_str());
        Table table = Table();
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
        std::vector<Column> newColumns;
        do
        {
            newColumns.emplace_back(Column()); //todo: add column details
        } while(tableRoot-> NextSiblingElement("columnn") != nullptr);
        table.addColumns(newColumns);
        tables.emplace_back(table);
    }

    return tables;
}