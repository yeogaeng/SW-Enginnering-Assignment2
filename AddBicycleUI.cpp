// AddBicycleUI.cpp
#include "AddBicycleUI.h"

/*
    함수 이름 : AddBicycleUI::AddBicycleUI()
    기능      : AddBicycleUI 클래스의 생성자로, AddBicycle 컨트롤러 참조를 초기화함
    전달 인자 : AddBicycle& ctrl - 자전거 등록 비즈니스 로직을 처리하는 컨트롤러 객체의 참조
    반환값    : 없음
*/
AddBicycleUI::AddBicycleUI(AddBicycle& ctrl)
  : addBicycleCtrl(ctrl)
{}

/*
    함수 이름 : AddBicycleUI::handleAddBicycle()
    기능      : UI로부터 받은 자전거 등록 정보를 컨트롤러에 전달하여 처리함
    전달 인자 : string bicycleId - 자전거 ID
               string bicycleName - 자전거 이름
    반환값    : bool -> 자전거 등록 성공 시 true, 실패 시 false
*/
bool AddBicycleUI::handleAddBicycle(string bicycleId, string bicycleName) {
    return addBicycleCtrl.addBicycle(bicycleId, bicycleName);
}