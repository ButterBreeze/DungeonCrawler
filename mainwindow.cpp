#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <dirent.h>
#include <string.h>
#include <vector>
#include <windows.h>
#include <fstream>
#include "tinyxml2.h"

std::vector<std::string> getFilesToParse();
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

///
/// \brief getFilesToParse
/// \return directories to parse throws error if something be wrong with the config file
///
std::vector<std::string> getFilesToParse()
{
    //setup for the config file
    tinyxml2::XMLDocument configFile;

    tinyxml2::XMLError eResult = configFile.LoadFile("DungeonCrawler.config");

    if(eResult != tinyxml2::XML_SUCCESS)
    {
        throw std::runtime_error("could not open config file");
    }
    tinyxml2::XMLNode* root = configFile.FirstChild();

    //gonna grab the database's inside of the config
    std::vector<std::string> databaseNames;
    tinyxml2::XMLElement* database;
    if((database = root->FirstChildElement("database")) == nullptr)
    {
        throw std::runtime_error("Config file had no database elements");
    }
    do
    {
        databaseNames.push_back(database->GetText());
    } while(root->NextSiblingElement("database") != nullptr);

    //gonna grab all the database xml files for the tables in them and where to place them


    std::vector<std::string> directoriesToParse;
    return directoriesToParse;
}

