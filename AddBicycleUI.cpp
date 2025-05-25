// AddBicycleUI.cpp
#include "AddBicycleUI.h"

AddBicycleUI::AddBicycleUI(AddBicycle& ctrl)
  : addBicycleCtrl(ctrl)
{}

bool AddBicycleUI::handleAddNewBicycle(string bicycleId, string bicycleName) {
    return addBicycleCtrl.handleAddNewBicycle(bicycleId, bicycleName);
}