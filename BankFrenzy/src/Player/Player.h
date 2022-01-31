//
// Created by miguel on 31/01/2022.
//

#ifndef BANKFRENZY_PLAYER_H
#define BANKFRENZY_PLAYER_H
#import <QObject>
#import "../Properties/Property.h"

class Player : public QObject {

    Q_OBJECT

    private:
        int index;
        std::vector<Property> properties;
        std::string ownerName;
        unsigned int money;
        unsigned int debts;



};


#endif //BANKFRENZY_PLAYER_H
