// AddBicycle.h
#pragma once

#include <string>
#include "BicycleRepository.h"

using std::string;

// <<control>> AddBicycle: 자전거 등록 로직 담당
class AddBicycle {
private:
    BicycleRepository& bicycleRepository;

public:
    // Repository를 생성자 주입
    AddBicycle(BicycleRepository& bicycleRepository);

    // 신규 자전거 등록: 성공(true)/실패(false)
    bool addBicycle(string bicycleId, string bicycleName);
};