// Bicycle.cpp
#include "Bicycle.h"

using std::vector;
using std::string;

int Bicycle::nextBicycleNum = 1;
vector<Bicycle*> Bicycle::bicycleList;

Bicycle::Bicycle(int bicycleNum, const string& bicycleId, const string& bicycleName)
    : bicycleNum(bicycleNum), bicycleId(bicycleId), bicycleName(bicycleName) {}

bool Bicycle::addNewBicycle(const string& id, const string& name) {
    // 중복 ID 방지
    for (auto* b : bicycleList) {
        if (b->bicycleId == id) return false;
    }
    Bicycle* b = new Bicycle(nextBicycleNum++, id, name);
    bicycleList.push_back(b);
    return true;
}

Bicycle* Bicycle::getBicycle(const string& id) {
    for (auto* b : bicycleList) {
        if (b->bicycleId == id) return b;
    }
    return nullptr;
}

int Bicycle::getBicycleNum() const { return bicycleNum; }
const string& Bicycle::getId() const { return bicycleId; }
const string& Bicycle::getName() const { return bicycleName; }
