#pragma once
#include <string>
#include <utility>

using std::string;
using std::pair;

// <<boundary>> LendBicycleUI
class LendBicycleUI {
public:
    static pair<string,string> handleLendBicycle(const string& bicycleId);
};