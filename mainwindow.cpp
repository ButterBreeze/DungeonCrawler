#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <dirent.h>
#include <string.h>
#include <vector>
#include <windows.h>
#include <fstream>
#include "ProcessObjects/tinyxml2.h"

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

void MainWindow::on_btnCrawlTheDatabase_clicked()
{

}
