#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initializeGame();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeGame()
{
    currentPlayer = CellState::X;
    ui->pushButton->setText(""); // Reset text on all buttons
    ui->pushButton_2->setText("");
    ui->pushButton_3->setText("");
    ui->pushButton_4->setText("");
    ui->pushButton_5->setText("");
    ui->pushButton_6->setText("");
    ui->pushButton_7->setText("");
    ui->pushButton_8->setText("");
    ui->pushButton_9->setText("");

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            gameBoard[i][j] = CellState::Empty;
        }
    }
    updateLabel();
}

void MainWindow::updateLabel()
{
    QString player;
    if (currentPlayer == CellState::X)
        player = "X";
    else
        player = "O";
    ui->label->setText("Current player: " + player);
}

void MainWindow::cellClicked(int row, int col)
{
    if (gameBoard[row][col] == CellState::Empty) {
        gameBoard[row][col] = currentPlayer;
        QPushButton *button = qobject_cast<QPushButton *>(sender());
        if (currentPlayer == CellState::X)
            button->setText("X");
        else
            button->setText("O");

        if (checkWin()) {
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Game Over", "Player " + QString(currentPlayer == CellState::X ? "X" : "O") + " wins!\nDo you want to play again?", QMessageBox::Yes|QMessageBox::No);
            if (reply == QMessageBox::Yes) {
                initializeGame();
            } else {
                QApplication::quit();
            }
        } else if (checkDraw()) {
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Game Over", "It's a draw!\nDo you want to play again?", QMessageBox::Yes|QMessageBox::No);
            if (reply == QMessageBox::Yes) {
                initializeGame();
            } else {
                QApplication::quit();
            }
        } else {
            currentPlayer = (currentPlayer == CellState::X) ? CellState::O : CellState::X;
            updateLabel();
        }
    }
}

bool MainWindow::checkWin() const
{
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (gameBoard[i][0] != CellState::Empty && gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2])
            return true;
        if (gameBoard[0][i] != CellState::Empty && gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i])
            return true;
    }

    // Check diagonals
    if (gameBoard[0][0] != CellState::Empty && gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2])
        return true;
    if (gameBoard[0][2] != CellState::Empty && gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0])
        return true;

    return false;
}

bool MainWindow::checkDraw() const
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (gameBoard[i][j] == CellState::Empty)
                return false;
        }
    }
    return true;
}

void MainWindow::on_pushButton_clicked()
{
    cellClicked(0, 0);
}

void MainWindow::on_pushButton_2_clicked()
{
    cellClicked(0, 1);
}

void MainWindow::on_pushButton_3_clicked()
{
    cellClicked(0, 2);
}

void MainWindow::on_pushButton_4_clicked()
{
    cellClicked(1, 0);
}

void MainWindow::on_pushButton_5_clicked()
{
    cellClicked(1, 1);
}

void MainWindow::on_pushButton_6_clicked()
{
    cellClicked(1, 2);
}

void MainWindow::on_pushButton_7_clicked()
{
    cellClicked(2, 0);
}

void MainWindow::on_pushButton_8_clicked()
{
    cellClicked(2, 1);
}

void MainWindow::on_pushButton_9_clicked()
{
    cellClicked(2, 2);
}
