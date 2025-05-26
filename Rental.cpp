// Rental.cpp
#include "Rental.h"
#include "Member.h"
#include "Bicycle.h"

/*
    함수 이름 : Rental::Rental()
    기능      : Rental 클래스의 생성자로, 회원과 자전거 정보를 받아 대여 객체를 생성함
    전달 인자 : Member* m - 대여한 회원 객체의 포인터
               Bicycle* b - 대여된 자전거 객체의 포인터
    반환값    : 없음
*/
Rental::Rental(Member* m, Bicycle* b)
  : member(m)
  , bicycle(b)
{}

/*
    함수 이름 : Rental::getMember()
    기능      : 대여한 회원 정보를 반환함
    전달 인자 : 없음
    반환값    : Member* -> 대여한 회원 객체의 포인터
*/
Member* Rental::getMember() {
    return member;
}

/*
    함수 이름 : Rental::getBicycle()
    기능      : 대여된 자전거 정보를 반환함
    전달 인자 : 없음
    반환값    : Bicycle* -> 대여된 자전거 객체의 포인터
*/
Bicycle* Rental::getBicycle() {
    return bicycle;
}