// BicycleRepository.cpp
#include "BicycleRepository.h"
#include <algorithm>

/*
    함수 이름 : BicycleRepository::BicycleRepository()
    기능      : BicycleRepository 클래스의 생성자로, 자전거 번호 발급기를 1번부터 시작하도록 초기화함
    전달 인자 : 없음
    반환값    : 없음
*/
BicycleRepository::BicycleRepository()
  : nextBicycleNum(1)
{}

/*
    함수 이름 : BicycleRepository::~BicycleRepository()
    기능      : BicycleRepository 클래스의 소멸자로, 동적 할당된 Bicycle 객체들의 메모리를 해제함
    전달 인자 : 없음
    반환값    : 없음
*/
BicycleRepository::~BicycleRepository() {
    for (auto* b : bicycles) {
        delete b;
    }
}

/*
    함수 이름 : BicycleRepository::addBicycle()
    기능      : 신규 자전거를 추가함
    전달 인자 : string bicycleId - 자전거 ID
               string bicycleName - 자전거 이름
    반환값    : Bicycle* -> 생성된 자전거 객체의 포인터, 중복 ID인 경우 nullptr
*/
Bicycle* BicycleRepository::addBicycle(string bicycleId, string bicycleName) {
    // 중복 ID 검사
    if (findById(bicycleId) != nullptr) {
        return nullptr;
    }
    // Bicycle 객체 생성 및 저장
    Bicycle* b = new Bicycle(nextBicycleNum++, bicycleId, bicycleName);
    bicycles.push_back(b);
    return b;
}

/*
    함수 이름 : BicycleRepository::findById()
    기능      : ID로 자전거를 조회함
    전달 인자 : string bicycleId - 조회할 자전거 ID
    반환값    : Bicycle* -> 찾은 자전거 객체의 포인터, 없으면 nullptr
*/
Bicycle* BicycleRepository::findById(string bicycleId) {
    for (auto* b : bicycles) {
        if (b->getId() == bicycleId) {
            return b;
        }
    }
    return nullptr;
}