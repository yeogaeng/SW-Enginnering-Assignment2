// Rental.h
#pragma once

#include <string>
class Member;
class Bicycle;

// 대여 정보를 관리하는 Rental 클래스 정의
class Rental {
private:
    Member* member;      // 대여한 회원 객체의 포인터
    Bicycle* bicycle;    // 대여된 자전거 객체의 포인터

public:
    /*
        함수 이름 : Rental::Rental()
        기능      : Rental 클래스의 생성자로, 회원과 자전거 정보를 받아 대여 객체를 생성함
        전달 인자 : Member* member - 대여한 회원 객체의 포인터
                   Bicycle* bicycle - 대여된 자전거 객체의 포인터
        반환값    : 없음
    */
    Rental(Member* member, Bicycle* bicycle);
    
    /*
        함수 이름 : Rental::getMember()
        기능      : 대여한 회원 정보를 반환함
        전달 인자 : 없음
        반환값    : Member* -> 대여한 회원 객체의 포인터
    */
    Member*  getMember();
    
    /*
        함수 이름 : Rental::getBicycle()
        기능      : 대여된 자전거 정보를 반환함
        전달 인자 : 없음
        반환값    : Bicycle* -> 대여된 자전거 객체의 포인터
    */
    Bicycle* getBicycle();
};