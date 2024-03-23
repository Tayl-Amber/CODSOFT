#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_pushButton_clicked()
{
    QString num1_str = ui->lineEdit->text();
    QString num2_str = ui->lineEdit_2->text();
    QString op = ui->lineEdit_3->text();


    double num1 = num1_str.toDouble();
    double num2 = num2_str.toDouble();


    double result;
    if (op == "+") {
        result = num1 + num2;
    } else if (op == "-") {
        result = num1 - num2;
    } else if (op == "*") {
        result = num1 * num2;
    } else if (op == "/") {
        if (num2 != 0) {
            result = num1 / num2;
        } else {
            ui->label->setText("Error: Division by zero");
            return;
        }
    } else {
        ui->label->setText("Error: Invalid operator");
        return;
    }


    ui->label_2->setText(QString::number(result));
}

