// ShowLendInfoUI.cpp
#include "ShowLendInfoUI.h"

/*
    함수 이름 : ShowLendInfoUI::ShowLendInfoUI()
    기능      : ShowLendInfoUI 클래스의 생성자로, ShowLendInfo 컨트롤러 참조를 초기화함
    전달 인자 : ShowLendInfo& ctrl - 대여 정보 조회 비즈니스 로직을 처리하는 컨트롤러 객체의 참조
    반환값    : 없음
*/
ShowLendInfoUI::ShowLendInfoUI(ShowLendInfo& ctrl)
  : showCtrl(ctrl)
{}

/*
    함수 이름 : ShowLendInfoUI::handleShowLendInfo()
    기능      : UI로부터 받은 대여 정보 조회 요청을 컨트롤러에 전달하여 처리함
    전달 인자 : 없음
    반환값    : vector<pair<string,string>> -> {자전거ID, 자전거이름} 쌍의 벡터
*/
vector<pair<string,string>> ShowLendInfoUI::handleShowLendInfo() {
    return showCtrl.showLendInfo();
}