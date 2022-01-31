#ifndef BANKFRENZY_PROPERTY_H
#define BANKFRENZY_PROPERTY_H


#include <string>
#include <vector>
#include "../Player/Player.h"
#include <QObject>

class Property : public QObject {

    Q_OBJECT

    private:

        /* Engine Info*/
        int index;
        int ownerId;
        std::string propertyName;
        std::string propertyColor;
        int

        /* Game Info */
        unsigned int value;
        int housesNumber;
        bool hasHotel;
        int baseRent;
        int clusterRent;
        std::vector<int> rentInfo; //[ oneHouseRent[0], twoHousesRent[1], threeHousesRent[2], fourHousesRent[3],
        int mortgage;
        int mortgageRedeem;
        bool mortgageStatus;
        // hotelRent[4] ]

    public slots:

        void setOwnerId(int ownerId);
        void changeMortgageStatus();


    signals:

        void setPropertyToOwner(int index);

    public:

        Property(int index, std::string propertyName, std::string propertyColor, unsigned int value,
                 int baseRent, int clusterRent, std::vector<int> rentInfo);

        int getIndex() const;

        const std::string &getPropertyName() const;

        const std::string &getPropertyColor() const;

        unsigned int getValue() const;

        int getHouseNumber() const;

        bool isHasHotel() const;

        int getBaseRent() const;

        int getClusterRent() const;

        std::vector<int> getRentInfo() const;

        int getHousesNumber() const;

        int getOwnerId() const;

        int getMortgage() const;

        int getmortgageRedeem() const;

        bool isMortgaged() const;

};


#endif //BANKFRENZY_PROPERTY_H
