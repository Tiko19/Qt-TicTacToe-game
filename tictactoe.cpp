#include "tictactoe.h"
#include "ui_tictactoe.h"

bool playerTurn = false;
int numPressed = 0;
int choice[9];

tictactoe::tictactoe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::tictactoe)
{
    ui->setupUi(this);

    connect(ui->NewGameButton, SIGNAL(released()), this,SLOT(resetButton()));
    connect(ui->QuitButton, SIGNAL(released()), this,SLOT(quitButton()));
    connect(ui->Button1, SIGNAL(released()), this,SLOT(button1Press()));
    connect(ui->Button2, SIGNAL(released()), this,SLOT(button2Press()));
    connect(ui->Button3, SIGNAL(released()), this,SLOT(button3Press()));
    connect(ui->Button4, SIGNAL(released()), this,SLOT(button4Press()));
    connect(ui->Button5, SIGNAL(released()), this,SLOT(button5Press()));
    connect(ui->Button6, SIGNAL(released()), this,SLOT(button6Press()));
    connect(ui->Button7, SIGNAL(released()), this,SLOT(button7Press()));
    connect(ui->Button8, SIGNAL(released()), this,SLOT(button8Press()));
    connect(ui->Button9, SIGNAL(released()), this,SLOT(button9Press()));
}

tictactoe::~tictactoe()
{
    delete ui;
}

/************************** Display character on clicked button *********************/
QString tictactoe::result(bool b)
        {
            if (b == false)
            {
                return "X";
            }
            else
            {
                return "O";
            }
        }

/*************** Return player number **************/
int tictactoe::playerNumber()
{
    if (playerTurn == false)
    {
        return 1;
    }
        else return 2;
}

/************************** Check if player has won *****************/
void tictactoe::checkWin(){
    int x = playerNumber();
    QMessageBox msgBox;
        if (choice[0] == x && choice[1] == x && choice[2] == x) {
            QMessageBox::information(nullptr, "TicTacToe",
                QString("Player %1 wins!!")
                .arg(x));
            disableAll();
        }
        else if (choice[0] == x && choice[3] == x && choice[6] == x) {
            QMessageBox::information(nullptr, "TicTacToe",
                QString("Player %1 wins!!")
                .arg(x));
            disableAll();
        }
        else if (choice[0] == x && choice[4] == x && choice[8] == x) {
            QMessageBox::information(nullptr, "TicTacToe",
                QString("Player %1 wins!!")
                .arg(x));
            disableAll();
        }
        else if (choice[1] == x && choice[4] == x && choice[7] == x) {
            QMessageBox::information(nullptr, "TicTacToe",
                QString("Player %1 wins!!")
                .arg(x));
            disableAll();
        }
        else if (choice[2] == x && choice[5] == x && choice[8] == x) {
            QMessageBox::information(nullptr, "TicTacToe",
                QString("Player %1 wins!!")
                .arg(x));
            disableAll();
        }
        else if (choice[2] == x && choice[4] == x && choice[6] == x) {
            QMessageBox::information(nullptr, "TicTacToe",
                QString("Player %1 wins!!")
                .arg(x));
            disableAll();
        }
        else if (choice[3] == x && choice[4] == x && choice[5] == x) {
            QMessageBox::information(nullptr, "TicTacToe",
                QString("Player %1 wins!!")
                .arg(x));
            disableAll();
        }
        else if (choice[6] == x && choice[7] == x && choice[8] == x) {
            QMessageBox::information(nullptr, "TicTacToe",
                QString("Player %1 wins!!")
                .arg(x));
            disableAll();
        }
        else if(numPressed == 9){
            msgBox.setText("It's a tie!!");
            msgBox.exec();
        }
        else{
            //Do nothing
        }
}

/************************ Button Controls **********************/
void tictactoe::button1Press(){
    ui->Button1->setEnabled(false);
    ui->Button1->setText(result(playerTurn));
    buttonPressed(0);
}
void tictactoe::button2Press(){
    ui->Button2->setEnabled(false);
    ui->Button2->setText(result(playerTurn));
    buttonPressed(1);
}
void tictactoe::button3Press(){
    ui->Button3->setEnabled(false);
    ui->Button3->setText(result(playerTurn));
    buttonPressed(2);
}
void tictactoe::button4Press(){
    ui->Button4->setEnabled(false);
    ui->Button4->setText(result(playerTurn));
    buttonPressed(3);
}
void tictactoe::button5Press(){
    ui->Button5->setEnabled(false);
    ui->Button5->setText(result(playerTurn));
    buttonPressed(4);
}
void tictactoe::button6Press(){
    ui->Button6->setEnabled(false);
    ui->Button6->setText(result(playerTurn));
    buttonPressed(5);
}
void tictactoe::button7Press(){
    ui->Button7->setEnabled(false);
    ui->Button7->setText(result(playerTurn));
    buttonPressed(6);
}
void tictactoe::button8Press(){
    ui->Button8->setEnabled(false);
    ui->Button8->setText(result(playerTurn));
    buttonPressed(7);
}
void tictactoe::button9Press(){
    ui->Button9->setEnabled(false);
    ui->Button9->setText(result(playerTurn));
    buttonPressed(8);
}

void tictactoe::buttonPressed(int x){
    numPressed++;
    if(playerTurn == false){
        choice[x] = 1;
        checkWin();
    }
    else{
        choice[x] = 2;
        checkWin();
    }
    playerTurn = !playerTurn;
}

void tictactoe::resetButton(){
    std::fill_n(choice, 9, 0);
    numPressed = 0;
    playerTurn = false;
    enableAll();
    ui->Button1->setText("");
    ui->Button2->setText("");
    ui->Button3->setText("");
    ui->Button4->setText("");
    ui->Button5->setText("");
    ui->Button6->setText("");
    ui->Button7->setText("");
    ui->Button8->setText("");
    ui->Button9->setText("");
}

void tictactoe::disableAll(){
    ui->Button1->setEnabled(false);
    ui->Button2->setEnabled(false);
    ui->Button3->setEnabled(false);
    ui->Button4->setEnabled(false);
    ui->Button5->setEnabled(false);
    ui->Button6->setEnabled(false);
    ui->Button7->setEnabled(false);
    ui->Button8->setEnabled(false);
    ui->Button9->setEnabled(false);
}

void tictactoe::enableAll(){
    ui->Button1->setEnabled(true);
    ui->Button2->setEnabled(true);
    ui->Button3->setEnabled(true);
    ui->Button4->setEnabled(true);
    ui->Button5->setEnabled(true);
    ui->Button6->setEnabled(true);
    ui->Button7->setEnabled(true);
    ui->Button8->setEnabled(true);
    ui->Button9->setEnabled(true);
}
void tictactoe::quitButton(){
    tictactoe::close();
}
