// Rental.h
#pragma once

#include <string>
class Member;
class Bicycle;

using std::string;

// <<entity>> Rental
class Rental {
private:
    static int nextRentalNum;
    int rentalNum;
    Member* member;
    Bicycle* bicycle;

    // private 생성자
    Rental(Member* member, Bicycle* bicycle);

public:
    // 팩토리 메서드: 항상 이걸 통해 생성
    static Rental* createRental(Member* member, Bicycle* bicycle);

    int getRentalNum() const;
    Member* getMember() const;
    Bicycle* getBicycle() const;
};
