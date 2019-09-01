#include "table.h"

Table::Table()
{

}

std::vector<Column> Table::getColumns()
{
    return this->columns;
}

void Table::addColumns(std::vector<Column> newColumns)
{
    this->columns.insert(this->columns.begin(), newColumns.begin(), newColumns.end());
}