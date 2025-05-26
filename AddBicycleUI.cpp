// AddBicycleUI.cpp
#include "AddBicycleUI.h"

AddBicycleUI::AddBicycleUI(AddBicycle& ctrl)
  : addBicycleCtrl(ctrl)
{}

bool AddBicycleUI::handleAddBicycle(string bicycleId, string bicycleName) {
    return addBicycleCtrl.addBicycle(bicycleId, bicycleName);
}