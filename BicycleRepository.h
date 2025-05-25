// BicycleRepository.h
#pragma once

#include <vector>
#include <string>
#include "Bicycle.h"

using std::vector;
using std::string;

// <<repository>> BicycleRepository: 자전거 저장·조회 책임
class BicycleRepository {
private:
    vector<Bicycle*> bicycles;   // 저장된 자전거 목록
    int nextBicycleNum;       // 다음 번호 발급기

public:
    // 생성자: 번호 발급기를 1로 초기화
    BicycleRepository();
    // 소멸자: 동적 할당된 Bicycle 메모리 해제
    ~BicycleRepository();

    // 신규 자전거 추가: 중복 ID면 nullptr, 성공 시 생성된 Bicycle* 반환
    Bicycle* addBicycle(string bicycleId, string bicycleName);
    // ID로 자전거 조회: 없으면 nullptr
    Bicycle* findById(string bicycleId);
};