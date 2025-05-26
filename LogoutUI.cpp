// LogoutUI.cpp
#include "LogoutUI.h"

/*
    함수 이름 : LogoutUI::LogoutUI()
    기능      : LogoutUI 클래스의 생성자로, Logout 컨트롤러 참조를 초기화함
    전달 인자 : Logout& ctrl - 로그아웃 비즈니스 로직을 처리하는 컨트롤러 객체의 참조
    반환값    : 없음
*/
LogoutUI::LogoutUI(Logout& ctrl)
  : logoutCtrl(ctrl)
{}

/*
    함수 이름 : LogoutUI::handleLogout()
    기능      : UI로부터 받은 로그아웃 요청을 컨트롤러에 전달하여 처리함
    전달 인자 : 없음
    반환값    : string -> 로그아웃된 사용자의 ID, 로그아웃 실패 시 빈 문자열
*/
string LogoutUI::handleLogout() {
    return logoutCtrl.logout();
}