// ShowLendInfoUI.h
#pragma once

#include <vector>
#include <string>
#include <utility>
#include "ShowLendInfo.h"

using std::vector;
using std::pair;
using std::string;

// <<boundary>> ShowLendInfoUI: UI 레이어에서 입력 받아 컨트롤 호출
class ShowLendInfoUI {
private:
    ShowLendInfo& showCtrl;

public:
    // ShowLendInfo 컨트롤러를 생성자 주입
    ShowLendInfoUI(ShowLendInfo& ctrl);

    // 대여 정보 조회 요청
    vector<pair<string,string>> handleShowLendInfo();
};