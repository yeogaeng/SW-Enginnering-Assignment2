// BicycleRepository.cpp
#include "BicycleRepository.h"
#include <algorithm>

BicycleRepository::BicycleRepository()
  : nextBicycleNum(1)
{}

BicycleRepository::~BicycleRepository() {
    for (auto* b : bicycles) {
        delete b;
    }
}

Bicycle* BicycleRepository::addBicycle(string bicycleId, string bicycleName) {
    // 중복 ID 검사
    if (findById(bicycleId) != nullptr) {
        return nullptr;
    }
    Bicycle* b = new Bicycle(nextBicycleNum++, bicycleId, bicycleName);
    bicycles.push_back(b);
    return b;
}

Bicycle* BicycleRepository::findById(string bicycleId) {
    for (auto* b : bicycles) {
        if (b->getId() == bicycleId) {
            return b;
        }
    }
    return nullptr;
}