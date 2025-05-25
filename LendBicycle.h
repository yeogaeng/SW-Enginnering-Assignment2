// LendBicycle.h
#pragma once
#include <utility>
#include <string>

using std::pair;
using std::string;

// <<control>> LendBicycle
// 성공 시 {bicycleId, bicycleName}, 실패 시 {"",""}
class LendBicycle {
public:
    static pair<string, string> lendBicycle(const string& bicycleId);
};