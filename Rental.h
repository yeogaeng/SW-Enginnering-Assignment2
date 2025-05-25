// Rental.h
#pragma once

#include <string>
class Member;
class Bicycle;

// <<entity>> Rental: 대여 정보 엔티티
class Rental {
private:
    Member*  member;    // 이 대여를 한 회원
    Bicycle* bicycle;   // 대여된 자전거

public:
    // 생성자: Member*, Bicycle* 를 전달받아 새로운 대여 객체 생성
    Rental(Member* member, Bicycle* bicycle);

    // 조회 메서드
    Member*  getMember();
    Bicycle* getBicycle();
};