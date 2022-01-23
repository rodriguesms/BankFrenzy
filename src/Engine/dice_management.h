#include <QRandomGenerator>

#ifndef DICE_MANAGEMENT_H
#define DICE_MANAGEMENT_H

#define DICE_MAX_RANGE 6
#define DICE_MIN_RANGE 1
#define EQUAL_ROLLS_MAX_TO_PRISON 3

struct DiceRolls {
    unsigned int dice1;
    unsigned int dice2;
};

    /* If a player roll the dices three times, and both dices are
     * the same for each of the three rolls, he goes to the prison */

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

    while(isThisRollEqual(diceRoll) && (equalRolls < EQUAL_ROLLS_MAX_TO_PRISON)){
        equalRolls++;
        diceRoll.dice1=randomDiceValue();
        diceRoll.dice2=randomDiceValue();
        rollReturn.rolls.push_back(diceRoll);
        rollReturn.jumps = diceRoll.dice1 + diceRoll.dice2;
    }

    rollReturn.goToPrison = (equalRolls == EQUAL_ROLLS_MAX_TO_PRISON);  // triple equal rolls -> go to prison

    return rollReturn;
}

#endif