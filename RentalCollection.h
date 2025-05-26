#pragma once

#include <vector>
class Rental;

using std::vector;

// 대여 정보 컬렉션을 관리하는 RentalCollection 클래스 정의
class RentalCollection {
private:
    vector<Rental*> ownedRentals;     // 보유한 대여 정보들의 포인터 벡터
    size_t cursor;                    // 순회를 위한 현재 위치 커서

public:
    /*
        함수 이름 : RentalCollection::RentalCollection()
        기능      : RentalCollection 클래스의 생성자로, 컬렉션과 커서를 초기화함
        전달 인자 : 없음
        반환값    : 없음
    */
    RentalCollection();

    /*
        함수 이름 : RentalCollection::addRental()
        기능      : 새로운 대여 정보를 컬렉션에 추가함
        전달 인자 : Rental* r - 추가할 대여 정보 객체의 포인터
        반환값    : 없음
    */
    void addRental(Rental* r);

    /*
        함수 이름 : RentalCollection::findFirst()
        기능      : 컬렉션의 첫 번째 대여 정보를 반환하고 커서를 초기화함
        전달 인자 : 없음
        반환값    : Rental* -> 첫 번째 대여 정보의 포인터, 비어있으면 nullptr
    */
    Rental* findFirst();
    
    /*
        함수 이름 : RentalCollection::getNext()
        기능      : 현재 커서 위치의 다음 대여 정보를 반환하고 커서를 이동함
        전달 인자 : 없음
        반환값    : Rental* -> 다음 대여 정보의 포인터, 더 이상 없으면 nullptr
    */
    Rental* getNext();
};