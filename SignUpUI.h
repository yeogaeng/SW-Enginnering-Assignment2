// SignUpUI.h
#pragma once
#include <string>
#include <fstream>

using std::string;

// <<boundary>> SignUpUI: 회원가입 입력 처리
class SignUpUI {
public:
    // 반환값: 성공(true)/실패(false)
    static bool handleSignUp(const string& id, const string& password, const string& phoneNumber);
};