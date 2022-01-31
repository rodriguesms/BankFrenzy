//
// Created by miguel on 24/01/2022.
//

#include "Property.h"

Property::Property(int index, std::string propertyName, std::string propertyColor, unsigned int value,
                   int baseRent, int clusterRent, std::vector<int> rentInfo) {
    this->index = index;
    this->propertyName=std::move(propertyName);
    this->propertyColor=std::move(propertyColor);
    this->value=value;
    this->baseRent=baseRent;
    this->clusterRent=clusterRent;
    this->rentInfo=std::move(rentInfo);
    ownerId=NAN;
    housesNumber=0;
    hasHotel=false;
}

void Property::setOwnerId(int ownerId) {
    if(ownerId!=this->ownerId){
        this->ownerId=ownerId;
        emit setPropertyToOwner(this->index);
    }
}
void Property::changeMortgageStatus() {
    mortgageStatus = !mortgageStatus;
}

const std::string &Property::getPropertyName() const {
    return propertyName;
}

const std::string &Property::getPropertyColor() const {
    return propertyColor;
}

unsigned int Property::getValue() const {
    return value;
}

int Property::getHousesNumber() const {
    return housesNumber;
}

bool Property::isHasHotel() const {
    return hasHotel;
}

int Property::getBaseRent() const {
    return baseRent;
}

int Property::getClusterRent() const {
    return clusterRent;
}

std::vector<int> Property::getRentInfo() const {
    return rentInfo;
}

int Property::getOwnerId() const {
    return ownerId;
}


