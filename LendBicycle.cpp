// LendBicycle.cpp
#include "LendBicycle.h"
#include "RentalCollection.h"
#include "Rental.h"

LendBicycle::LendBicycle(BicycleRepository& bp, MemberRepository& mp, LoginUser& sess) : bicycleRepository(bp), memberRepository(mp), session(sess){}

pair<string,string> LendBicycle::handleLendBicycle(string bicycleId) {
    // 1) 로그인된 Member 가져오기
    Member* m = session.whoIsLogin();
    if (!m) return {"",""};

    // 2) 자전거 조회
    Bicycle* bicycle = bicycleRepository.findById(bicycleId);
    if (!bicycle) return {"",""};

    // 3) Rental 생성 및 컬렉션 추가
    RentalCollection* rc = m->getRentalCollection();
    Rental* r = Rental::createRental(m, bicycle);
    rc->addRental(r);

    return { bicycle->getId(), bicycle->getName() };
}