//
// Created by miguel on 23/01/2022.
//

#ifndef BANKFRENZY_PROPERTY_H
#define BANKFRENZY_PROPERTY_H


#include <string>

class Property {

    private:

        /* Engine Info*/
        int index;
        int ownerPlayerId;
        std::string propertyName;
        std::string propertyColor;
        std::string ownerPlayerName;

        /* Game Info */
        unsigned int value;
        int houseNumber;
        bool hasHotel;
        int baseRent;
        int clusterRent;
        int oneHouseRent;
        int twoHousesRent;
        int threeHousesRent;
        int fourHousesRent;
        int hotelRent;

};


#endif //BANKFRENZY_PROPERTY_H
