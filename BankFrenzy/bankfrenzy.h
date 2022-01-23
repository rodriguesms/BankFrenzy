#ifndef BANKFRENZY_H
#define BANKFRENZY_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class BankFrenzy; }
QT_END_NAMESPACE

class BankFrenzy : public QMainWindow
{
    Q_OBJECT

public:
    BankFrenzy(QWidget *parent = nullptr);
    ~BankFrenzy();

private:
    Ui::BankFrenzy *ui;
};
#endif // BANKFRENZY_H
