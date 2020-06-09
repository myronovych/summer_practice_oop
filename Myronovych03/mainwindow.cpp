#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <fstream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    string readed = readFile();
    ui->textBrowser-> setText(QString::fromStdString(readed));
    writeFile(readed);
}

MainWindow::~MainWindow() {
    delete ui;
}

string readString(const string& inputLine) {
    string answer="";
    for(size_t i =0;i<inputLine.size();i++)
    {
        answer+= inputLine[i] == '\t' ? ' ': inputLine[i];
    }
    return answer;
}

string MainWindow::readFile() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File to Read"),"",tr("Text (*.txt)"));
    string answer="";
    string readedLine;

    ifstream inputStream( fileName.toUtf8().constData() );

    if (inputStream.is_open()) {
        while (getline(inputStream, readedLine)) {
               answer+=readString(readedLine);
        }
    }

    //closing
    inputStream.close();

    return answer;
}

void MainWindow::writeFile(const string& output) {
    QString strFile = QFileDialog::getSaveFileName(this, tr("Making file"),"output.txt", tr("Text (*.txt)"));
    ofstream outputStream;
    outputStream.open(strFile.toUtf8().constData());
    if (outputStream.is_open()) {
       outputStream << output << endl;
    }
}
