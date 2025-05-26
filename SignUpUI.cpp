// SignUpUI.cpp
#include "SignUpUI.h"

// 생성자 정의: member initializer list 로 컨트롤러 참조 주입
SignUpUI::SignUpUI(SignUp& ctrl)
  : signUpCtrl(ctrl)
{}

// 파라미터 그대로 컨트롤러에 전달하고 결과 반환
bool SignUpUI::handleSignUp(string id, string password, string phoneNumber) {
    return signUpCtrl.signUp(id, password, phoneNumber);
}