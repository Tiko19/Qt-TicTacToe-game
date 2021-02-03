#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QMainWindow>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class tictactoe; }
QT_END_NAMESPACE

class tictactoe : public QMainWindow
{
    Q_OBJECT

public:
    tictactoe(QWidget *parent = nullptr);
    ~tictactoe();

private:
    Ui::tictactoe *ui;

private slots:
    void buttonPressed(int);
    void resetButton();
    void quitButton();
    void checkWin();
    int playerNumber();
    QString result(bool);
    void disableAll();
    void enableAll();
    void button1Press();
    void button2Press();
    void button3Press();
    void button4Press();
    void button5Press();
    void button6Press();
    void button7Press();
    void button8Press();
    void button9Press();
};
#endif // TICTACTOE_H
