// LoginUI.h
#pragma once

#include <string>
#include "Login.h"

using std::string;

// <<boundary>> LoginUI: UI 레이어에서 파싱된 입력을 받아 Controller 호출
class LoginUI {
private:
    Login& loginCtrl;
public:
    // Login 컨트롤러를 생성자 주입
    LoginUI(Login& ctrl);

    // 화면으로부터 전달받은 ID/PW를 컨트롤러에 넘김
    bool handleLogin(string id, string password);
};