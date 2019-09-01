#include "database.h"

Database::Database()
{

}

void Database::setName(std::string name)
{
    this->name = name;
}

std::string Database::getName()
{
    return this->name;
}

void Database::addTables(std::vector<Table> newTables)
{
    this->tables.insert(this->tables.end(), newTables.begin(), newTables.end());
}
