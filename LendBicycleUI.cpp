#include "LendBicycleUI.h"
#include "LendBicycle.h"

pair<string,string> LendBicycleUI::handleLendBicycle(const string& bicycleId) {
    return LendBicycle::lendBicycle(bicycleId);
}