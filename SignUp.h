#pragma once
#include <string>

using std::string;

class SignUp {
public:
    // 신규 회원 등록: 성공(true)/실패(false)
    static bool signUp(const string& id, const string& password, const string& phoneNumber);
};