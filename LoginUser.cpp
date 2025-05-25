#include "LoginUser.h"
#include <string>
#include <iostream>

using std::string;

// static 멤버 초기화
string LoginUser::sessionId = "";


string LoginUser::whoIsLogin() {
    return sessionId;
}

//로그인 중인 회원
bool LoginUser::addLoginUser(const string& id) { //로그인 중 확인은 무조건 이전에 진행
    sessionId = id;
    return true;
}

string LoginUser::deleteLoginUser() {
    string currentId = whoIsLogin();
    if (!currentId.empty()){
        sessionId.clear();
        return currentId; //세션 삭제 완료
    }
    return ""; //로그인이 되어있지 않은 경우
}

std::string LoginUser::getSessionId() {
    return sessionId;
}