// LendBicycleUI.cpp
#include "LendBicycleUI.h"

LendBicycleUI::LendBicycleUI(LendBicycle& ctrl)
  : lendCtrl(ctrl)
{}

pair<string,string> LendBicycleUI::handleLendBicycle(string bicycleId) {
    return lendCtrl.handleLendBicycle(bicycleId);
}