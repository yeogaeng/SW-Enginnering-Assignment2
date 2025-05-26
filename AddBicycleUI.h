// AddBicycleUI.h
#pragma once

#include <string>
#include "AddBicycle.h"

using std::string;

// <<boundary>> AddBicycleUI: 파싱된 입력을 받아 자전거 등록 컨트롤 호출
class AddBicycleUI {
private:
    AddBicycle& addBicycleCtrl;

public:
    // AddBicycle 컨트롤러를 생성자 주입
    AddBicycleUI(AddBicycle& ctrl);

    // 화면으로부터 받은 자전거 ID, 이름을 컨트롤에 전달
    bool handleAddBicycle(string bicycleId, string bicycleName);
};