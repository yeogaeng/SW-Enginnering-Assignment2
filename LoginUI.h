// LoginUI.h
#pragma once

#include <string>
#include "Login.h"

using std::string;

// 로그인 UI를 위한 LoginUI 클래스 정의
class LoginUI {
private:
    Login& loginCtrl;     // 로그인 비즈니스 로직을 처리하는 컨트롤러 참조
    
public:
    /*
        함수 이름 : LoginUI::LoginUI()
        기능      : LoginUI 클래스의 생성자로, Login 컨트롤러 참조를 초기화함
        전달 인자 : Login& ctrl - 로그인 비즈니스 로직을 처리하는 컨트롤러 객체의 참조
        반환값    : 없음
    */
    LoginUI(Login& ctrl);

    /*
        함수 이름 : LoginUI::handleLogin()
        기능      : UI로부터 받은 로그인 정보를 컨트롤러에 전달하여 처리함
        전달 인자 : string id - 회원 ID
                   string password - 회원 비밀번호
        반환값    : bool -> 로그인 성공 시 true, 실패 시 false
    */
    bool handleLogin(string id, string password);
};