// LendBicycleUI.h
#pragma once

#include <string>
#include <utility>
#include "LendBicycle.h"

using std::string;
using std::pair;

// <<boundary>> LendBicycleUI: UI 레이어에서 자전거 대여 컨트롤 호출
class LendBicycleUI {
private:
    LendBicycle& lendCtrl;

public:
    // LendBicycle 컨트롤러를 생성자 주입
    LendBicycleUI(LendBicycle& ctrl);

    // 파싱된 bicycleId를 컨트롤러에 전달
    // 반환: {id,name} or {"",""}
    pair<string,string> handleLendBicycle(string bicycleId);
};