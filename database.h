#ifndef DATABASE_H
#define DATABASE_H
#include <vector>
#include <iostream>
#include "table.h"

class Database
{
public:
    Database();
    void setName(std::string name);
    std::string getName();
    void addTables(std::vector<Table> newTables);

private:
    std::string name;
    std::vector<Table> tables;
};

#endif // DATABASE_H
