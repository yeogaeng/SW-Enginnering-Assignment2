// Bicycle.h
#pragma once

#include <string>
using std::string;

// <<entity>> Bicycle: 자전거 엔티티
class Bicycle {
private:
    int bicycleNum;      // 고유 자전거 번호
    string bicycleId;    // 예: "b1"
    string bicycleName;  // 예: "bikeMaker"

public:
    // 생성자
    Bicycle(int bicycleNum, string bicycleId, string bicycleName);

    // getters
    int    getBicycleNum();
    string getId();
    string getName();
};