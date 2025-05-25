// Rental.cpp
#include "Rental.h"
#include "Member.h"
#include "Bicycle.h"

Rental::Rental(Member* m, Bicycle* b)
  : member(m)
  , bicycle(b)
{}

Member* Rental::getMember() {
    return member;
}

Bicycle* Rental::getBicycle() {
    return bicycle;
}