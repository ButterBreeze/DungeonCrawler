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


