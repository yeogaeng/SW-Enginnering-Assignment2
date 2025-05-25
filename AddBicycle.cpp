#include "AddBicycle.h"
#include "Bicycle.h"

bool AddBicycle::addNewBicycle(const string& bicycleId, const string& bicycleName) {
    return Bicycle::addNewBicycle(bicycleId, bicycleName);
}
