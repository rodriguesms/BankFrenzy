#include <QCoreApplication>
#include <QDebug>
#include <QRandomGenerator64>
#include "src/dice_management.h"
#include <iostream>

#define DICE_MAX_RANGE 6

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    RollReturn test = rollDices();

    for(int i = 0; i < test.rolls.size(); i++){
        std::cout << i+1 << "° Roll: [ ";
        std::cout << test.rolls[i].dice1 << ", ";
        std::cout << test.rolls[i].dice2 << " ] " << std::endl;
    }

    std::cout << "Go to prison? " << (test.goToPrison ? "yes" : "no") << std::endl;
    if(!test.goToPrison){
        std::cout << "Jumps: " << test.jumps << std::endl;
    }

    return QCoreApplication::exec();
}
