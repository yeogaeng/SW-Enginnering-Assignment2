#pragma once

#include <vector>
class Rental;

using std::vector;

class RentalCollection {
private:
    vector<Rental*> ownedRentals;
    size_t          cursor;

public:
    RentalCollection();

    // 새 Rental 추가
    void addRental(Rental* r);

    // 순회용 API
    Rental* findFirst();
    Rental* getNext();
};