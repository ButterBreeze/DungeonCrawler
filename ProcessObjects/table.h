#ifndef TABLE_H
#define TABLE_H
#include "column.h"
#include <iostream>
#include <vector>
class Table
{
private:
    std::vector<Column> columns;

public:
    Table();
    std::vector<Column> getColumns();
    void addColumns(std::vector<Column> newColumns);

};

#endif // TABLE_H
