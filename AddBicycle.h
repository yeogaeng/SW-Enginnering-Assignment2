#pragma once
#include <string>

using std::string;

// <<control>> AddBicycle
class AddBicycle {
public:
    // 신규 자전거 등록: 성공(true)/실패(false)
    static bool addNewBicycle(const string& bicycleId, const string& bicycleName);
};