#include "bankfrenzy.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BankFrenzy w;
    w.show();
    return a.exec();
}
