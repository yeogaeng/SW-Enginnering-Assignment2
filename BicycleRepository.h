// BicycleRepository.h
#pragma once

#include <vector>
#include <string>
#include "Bicycle.h"

using std::vector;
using std::string;

// 자전거 정보 저장 및 조회를 담당하는 BicycleRepository 클래스 정의
class BicycleRepository {
private:
    vector<Bicycle*> bicycles;   // 저장된 모든 자전거 객체들의 포인터 벡터
    int nextBicycleNum;          // 다음 자전거에게 부여할 자전거 번호

public:
    /*
        함수 이름 : BicycleRepository::BicycleRepository()
        기능      : BicycleRepository 클래스의 생성자로, 자전거 번호 발급기를 1번부터 시작하도록 초기화함
        전달 인자 : 없음
        반환값    : 없음
    */
    BicycleRepository();
    
    /*
        함수 이름 : BicycleRepository::~BicycleRepository()
        기능      : BicycleRepository 클래스의 소멸자로, 동적 할당된 Bicycle 객체들의 메모리를 해제함
        전달 인자 : 없음
        반환값    : 없음
    */
    ~BicycleRepository();

    /*
        함수 이름 : BicycleRepository::addBicycle()
        기능      : 신규 자전거를 추가함
        전달 인자 : string bicycleId - 자전거 ID
                   string bicycleName - 자전거 이름
        반환값    : Bicycle* -> 생성된 자전거 객체의 포인터, 중복 ID인 경우 nullptr
    */
    Bicycle* addBicycle(string bicycleId, string bicycleName);
    
    /*
        함수 이름 : BicycleRepository::findById()
        기능      : ID로 자전거를 조회함
        전달 인자 : string bicycleId - 조회할 자전거 ID
        반환값    : Bicycle* -> 찾은 자전거 객체의 포인터, 없으면 nullptr
    */
    Bicycle* findById(string bicycleId);
};