// Bicycle.cpp
#include "Bicycle.h"

// 생성자 정의
Bicycle::Bicycle(int bicycleNum, string bicycleId, string bicycleName) : bicycleNum(bicycleNum), bicycleId(bicycleId), bicycleName(bicycleName)
{}

// 고유 번호 반환
int Bicycle::getBicycleNum() {
    return bicycleNum;
}

// ID 반환
string Bicycle::getId() {
    return bicycleId;
}

// 이름 반환
string Bicycle::getName() {
    return bicycleName;
}