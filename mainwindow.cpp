#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_convertToBF_clicked()
{
    QString text = ui->stringEntry->toPlainText();
    QString bf_out = "";
    int current;
    int k = 0;
    for (int i = 0; i < text.length(); i++){
        current = text[i].toLatin1();
        while (k != current) {
            if(k>current){
                bf_out += "-";
                k--;
            }
            else{
                bf_out += "+";
                k++;
            }
        }
        bf_out +=".\n";
    }
    ui->brainFuckOutput->document()->setPlainText(bf_out);
}
