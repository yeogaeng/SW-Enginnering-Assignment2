#pragma once
#include <string>
#include <fstream>

using std::string;

class AddBicycleUI {
public:
    static bool handleAddNewBicycle(const string& bicycleId, const string& bicycleName);
};