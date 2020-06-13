#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->addItem("Миронович Олександр");
    ui->listWidget->addItem("Петренко Петро");
    ui->listWidget->addItem("Василенко Василь");

    ui->listWidget_2->addItem("Іваненко Іван");
    ui->listWidget_2->addItem("Андрієнко Андрій");
    ui->listWidget_2->addItem("Остапенко Остап");
}

MainWindow::~MainWindow()
{
    delete ui;
}

