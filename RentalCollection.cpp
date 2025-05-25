#include "RentalCollection.h"
#include "Rental.h"

RentalCollection::RentalCollection()
  : cursor(0)
{}

void RentalCollection::addRental(Rental* r) {
    ownedRentals.push_back(r);
}

Rental* RentalCollection::findFirst() {
    cursor = 0;
    if (ownedRentals.empty()) return nullptr;
    return ownedRentals[cursor];
}

Rental* RentalCollection::getNext() {
    if (++cursor >= ownedRentals.size()) return nullptr;
    return ownedRentals[cursor];
}