// Rental.cpp
#include "Rental.h"

int Rental::nextRentalNum = 1;

Rental::Rental(Member* member, Bicycle* bicycle)
    : rentalNum(nextRentalNum++), member(member), bicycle(bicycle) {}

Rental* Rental::createRental(Member* member, Bicycle* bicycle) {
    return new Rental(member, bicycle);
}

int Rental::getRentalNum() const { return rentalNum; }
Member* Rental::getMember() const { return member; }
Bicycle* Rental::getBicycle() const { return bicycle; }
