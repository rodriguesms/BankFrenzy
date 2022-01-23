#include "bankfrenzy.h"
#include "./ui_bankfrenzy.h"

BankFrenzy::BankFrenzy(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BankFrenzy)
{
    ui->setupUi(this);
}

BankFrenzy::~BankFrenzy()
{
    delete ui;
}

