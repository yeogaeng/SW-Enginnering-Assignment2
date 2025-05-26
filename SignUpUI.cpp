// SignUpUI.cpp
#include "SignUpUI.h"

/*
    함수 이름 : SignUpUI::SignUpUI()
    기능      : SignUpUI 클래스의 생성자로, SignUp 컨트롤러 참조를 초기화함
    전달 인자 : SignUp& ctrl - 회원가입 비즈니스 로직을 처리하는 컨트롤러 객체의 참조
    반환값    : 없음
*/
SignUpUI::SignUpUI(SignUp& ctrl)
  : signUpCtrl(ctrl)
{}

/*
    함수 이름 : SignUpUI::handleSignUp()
    기능      : UI로부터 받은 회원가입 정보를 컨트롤러에 전달하여 처리함
    전달 인자 : string id - 회원 ID
               string password - 회원 비밀번호
               string phoneNumber - 회원 전화번호
    반환값    : bool -> 회원가입 성공 시 true, 실패 시 false
*/
bool SignUpUI::handleSignUp(string id, string password, string phoneNumber) {
    return signUpCtrl.signUp(id, password, phoneNumber);
}