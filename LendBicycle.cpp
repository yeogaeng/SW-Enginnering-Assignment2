// LendBicycle.cpp
#include "LendBicycle.h"
#include "LoginUser.h"
#include "Member.h"
#include "RentalCollection.h"
#include "Rental.h"
#include "Bicycle.h"

pair<string, string> LendBicycle::lendBicycle(const string& bicycleId) {
    // 1) 현재 로그인된 사용자의 ID를 가져온다
    string memberId = LoginUser::whoIsLogin();
    if (memberId.empty())
        return {"", ""}; // 로그인되지 않은 상태

    Member* m = Member::findMemberById(memberId);
    if (!m) // 해당 ID의 회원이 존재하지 않음
        return {"", ""};;

    // 2) 자전거 객체 조회
    Bicycle* bike = Bicycle::getBicycle(bicycleId);
    if (!bike) return {"", ""};

    // 3) Rental 생성 및 컬렉션 추가
    RentalCollection* rc = m->getRentalCollection();
    Rental* r = Rental::createRental(m, bike);
    rc->addRental(r);

    return { bike->getId(), bike->getName() };
}