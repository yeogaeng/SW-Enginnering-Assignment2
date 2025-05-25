// LendBicycle.cpp
#include "LendBicycle.h"
#include "RentalCollection.h"
#include "Rental.h"

LendBicycle::LendBicycle(BicycleRepository& bp,MemberRepository& mp, LoginUser& sess) : bicycleRepository(bp), memberRepository(mp), session(sess){}

pair<string,string> LendBicycle::handleLendBicycle(string bicycleId) {
    Member* m = session.whoIsLogin();
    if (!m) return {"",""};

    Bicycle* bicycle = bicycleRepository.findById(bicycleId);
    if (!bicycle) return {"",""};

    Rental* r = new Rental(m, bicycle);

    RentalCollection* rc = m->getRentalCollection();
    rc->addRental(r);

    return { bicycle->getId(), bicycle->getName() };
}