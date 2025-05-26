#include "RentalCollection.h"
#include "Rental.h"

/*
    함수 이름 : RentalCollection::RentalCollection()
    기능      : RentalCollection 클래스의 생성자로, 커서를 0으로 초기화함
    전달 인자 : 없음
    반환값    : 없음
*/
RentalCollection::RentalCollection()
  : cursor(0)
{}

/*
    함수 이름 : RentalCollection::addRental()
    기능      : 새로운 대여 정보를 컬렉션에 추가함
    전달 인자 : Rental* r - 추가할 대여 정보 객체의 포인터
    반환값    : 없음
*/
void RentalCollection::addRental(Rental* r) {
    ownedRentals.push_back(r);
}

/*
    함수 이름 : RentalCollection::findFirst()
    기능      : 컬렉션의 첫 번째 대여 정보를 반환하고 커서를 초기화함
    전달 인자 : 없음
    반환값    : Rental* -> 첫 번째 대여 정보의 포인터, 비어있으면 nullptr
*/
Rental* RentalCollection::findFirst() {
    cursor = 0;  // 커서를 처음 위치로 초기화
    if (ownedRentals.empty()) return nullptr;  // 컬렉션이 비어있는 경우
    return ownedRentals[cursor];
}

/*
    함수 이름 : RentalCollection::getNext()
    기능      : 현재 커서 위치의 다음 대여 정보를 반환하고 커서를 이동함
    전달 인자 : 없음
    반환값    : Rental* -> 다음 대여 정보의 포인터, 더 이상 없으면 nullptr
*/
Rental* RentalCollection::getNext() {
    if (++cursor >= ownedRentals.size()) return nullptr;  // 더 이상 대여 정보가 없는 경우
    return ownedRentals[cursor];
}