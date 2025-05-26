// Rental.h
#pragma once

#include <string>
class Member;
class Bicycle;

class Rental {
private:
    Member* member;
    Bicycle* bicycle;

public:
    // 생성자: Member*, Bicycle* 를 전달받아 새로운 대여 객체 생성
    Rental(Member* member, Bicycle* bicycle);
    Member*  getMember();
    Bicycle* getBicycle();
};