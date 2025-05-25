// AddBicycle.cpp
#include "AddBicycle.h"

AddBicycle::AddBicycle(BicycleRepository& repo)
  : bicycleRepository(repo)
{}

bool AddBicycle::handleAddNewBicycle(string bicycleId, string bicycleName) {
    // addBicycle이 nullptr을 반환하면 중복 ID이므로 false
    return bicycleRepository.addBicycle(bicycleId, bicycleName) != nullptr;
}