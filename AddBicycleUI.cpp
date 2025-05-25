#include "AddBicycleUI.h"
#include "AddBicycle.h"

bool AddBicycleUI::handleAddNewBicycle(const string& bicycleId, const string& bicycleName) {
    return AddBicycle::addNewBicycle(bicycleId, bicycleName);
}