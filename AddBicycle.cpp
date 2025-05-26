// AddBicycle.cpp
#include "AddBicycle.h"

AddBicycle::AddBicycle(BicycleRepository& bicycleRepository)
  : bicycleRepository(bicycleRepository)
{}

bool AddBicycle::addBicycle(string bicycleId, string bicycleName) {
    // nullptr을 반환하면 중복 ID이므로 false
    return bicycleRepository.addBicycle(bicycleId, bicycleName) != nullptr;
}