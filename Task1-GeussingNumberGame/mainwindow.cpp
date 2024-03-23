#include "mainwindow.h"
#include "ui_mainwindow.h"
int guess = 1+(rand()%100);
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
    int userGuess = ui->lineEdit->text().toInt();

    // Compare user's guess with the random number
    if (userGuess == guess) {
        ui->label_2->setText("Congratulations! You guessed it right!");
    } else if (userGuess < guess) {
        ui->label_2->setText("Too low! Try again.");
    } else {
        ui->label_2->setText("Too high! Try again.");
    }
    ui->lineEdit->setText("");
}

