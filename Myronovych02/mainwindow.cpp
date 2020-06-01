#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QLabel"
#include "QScreen"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
   QMainWindow::resizeEvent(event);

   QString s = "width: "+QString::number(event->size().width())+"; height: "+QString::number(event->size().height());
   ui->screenSizeLabel->setText(s);
}
