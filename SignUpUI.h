// SignUpUI.h
#pragma once

#include <string>
#include "SignUp.h"

using std::string;

// <<boundary>> SignUpUI: UI 레이어에서 입력 받아 컨트롤 호출
class SignUpUI {
private:
    SignUp& signUpCtrl;

public:
    // SignUp 컨트롤러를 생성자 주입
    SignUpUI(SignUp& ctrl);

    // 화면으로부터 받은 파라미터를 컨트롤에 전달
    bool handleSignUp(string id, string password, string phoneNumber);
};