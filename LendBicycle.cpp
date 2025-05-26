// LendBicycle.cpp
#include "LendBicycle.h"
#include "RentalCollection.h"
#include "Rental.h"

/*
    함수 이름 : LendBicycle::LendBicycle()
    기능      : LendBicycle 클래스의 생성자로, Repository들과 LoginUser 참조를 초기화함
    전달 인자 : BicycleRepository& bp - 자전거 정보를 관리하는 Repository 객체의 참조
               MemberRepository& mp - 회원 정보를 관리하는 Repository 객체의 참조
               LoginUser& sess - 로그인 세션 정보를 관리하는 객체의 참조
    반환값    : 없음
*/
LendBicycle::LendBicycle(BicycleRepository& bp,MemberRepository& mp, LoginUser& sess) : bicycleRepository(bp), memberRepository(mp), session(sess){}

/*
    함수 이름 : LendBicycle::lendBicycle()
    기능      : 자전거를 대여함
    전달 인자 : string bicycleId - 대여할 자전거 ID
    반환값    : pair<string,string> -> 대여 성공 시 {자전거ID, 자전거이름}, 실패 시 {"", ""}
*/
pair<string,string> LendBicycle::lendBicycle(string bicycleId) {
    // 현재 로그인된 회원 확인
    Member* m = session.whoIsLogin();
    if (!m) return {"",""};  // 로그인되지 않은 경우 실패

    // 대여할 자전거 조회
    Bicycle* bicycle = bicycleRepository.findById(bicycleId);
    if (!bicycle) return {"",""};  // 자전거가 존재하지 않는 경우 실패

    // 새로운 대여 객체 생성
    Rental* r = new Rental(m, bicycle);

    // 회원의 대여 컬렉션에 추가
    RentalCollection* rc = m->getRentalCollection();
    rc->addRental(r);

    return { bicycle->getId(), bicycle->getName() };  // 대여 성공
}