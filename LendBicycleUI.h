// LendBicycleUI.h
#pragma once

#include <string>
#include <utility>
#include "LendBicycle.h"

using std::string;
using std::pair;

// 자전거 대여 UI를 위한 LendBicycleUI 클래스 정의
class LendBicycleUI {
private:
    LendBicycle& lendCtrl;     // 자전거 대여 비즈니스 로직을 처리하는 컨트롤러 참조

public:
    /*
        함수 이름 : LendBicycleUI::LendBicycleUI()
        기능      : LendBicycleUI 클래스의 생성자로, LendBicycle 컨트롤러 참조를 초기화함
        전달 인자 : LendBicycle& ctrl - 자전거 대여 비즈니스 로직을 처리하는 컨트롤러 객체의 참조
        반환값    : 없음
    */
    LendBicycleUI(LendBicycle& ctrl);

    /*
        함수 이름 : LendBicycleUI::handleLendBicycle()
        기능      : UI로부터 받은 자전거 대여 요청을 컨트롤러에 전달하여 처리함
        전달 인자 : string bicycleId - 대여할 자전거 ID
        반환값    : pair<string,string> -> 대여 성공 시 {자전거ID, 자전거이름}, 실패 시 {"", ""}
    */
    pair<string,string> handleLendBicycle(string bicycleId);
};