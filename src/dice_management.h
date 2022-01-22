#include <QRandomGenerator>

#ifndef DICE_MANAGEMENT_H
#define DICE_MANAGEMENT_H

#define DICE_MAX_RANGE 6
#define DICE_MIN_RANGE 1

struct DiceRolls {
    unsigned int dice1;
    unsigned int dice2;
};

struct RollReturn {
    std::vector<DiceRolls> rolls;
    unsigned int jumps;
    bool goToPrison;
};

int randomDiceValue(){
    std::uniform_int_distribution distribution(DICE_MIN_RANGE, DICE_MAX_RANGE);
    return distribution(*QRandomGenerator64::global());
}

bool isThisRollEqual(DiceRolls diceRoll){
    return (diceRoll.dice1 == diceRoll.dice2);
}

DiceRolls simpleDiceRolling() { // ONLY TO DECIDE PLAYER ORDER
    DiceRolls diceRoll{};
    diceRoll.dice1 = randomDiceValue();
    diceRoll.dice2 = randomDiceValue();
    return diceRoll;
}

RollReturn rollDices(){

    DiceRolls diceRoll{};
    RollReturn rollReturn{};

    int equalRolls=0;

    diceRoll.dice1 = randomDiceValue();
    diceRoll.dice2 = randomDiceValue();

    rollReturn.rolls.push_back(diceRoll);
    rollReturn.jumps = diceRoll.dice1 + diceRoll.dice2;

    while(isThisRollEqual(diceRoll) && equalRolls<3){
        equalRolls++;
        diceRoll.dice1=randomDiceValue();
        diceRoll.dice2=randomDiceValue();
        rollReturn.rolls.push_back(diceRoll);
        rollReturn.jumps = diceRoll.dice1 + diceRoll.dice2;
    }

    rollReturn.goToPrison = (equalRolls == 3);  // triple equal rolls -> go to prison

    return rollReturn;
}

#endif