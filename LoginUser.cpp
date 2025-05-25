#include "LoginUser.h"
#include <string>
#include <iostream>

using std::string;

// static 멤버 초기화
int LoginUser::sessionNum = -1;
string LoginUser::sessionId = "";


string LoginUser::whoIsLogin() {
    return sessionId;
}

//로그인 중인 회원
bool LoginUser::addLoginUser(int memberNum, const string& id) { //로그인 중 확인은 무조건 이전에 isLogin()에서 진행
    sessionNum = memberNum;
    sessionId = id;
    std::cout << "로그인 중인 회원 : " <<sessionId << sessionNum <<'\n';
    return true;
}

string LoginUser::deleteLoginUser() {
    string currentId = whoIsLogin();
    if (!currentId.empty()){
        sessionNum = -1;
        sessionId.clear();
        //std::cout << "로그인 중인 회원 : " <<sessionId << sessionNum <<'\n';
        return currentId; //세션 삭제 완료
    }
    return ""; //로그인이 되어있지 않은 경우
}



int LoginUser::getSessionNum() {
    return sessionNum;
}

std::string LoginUser::getSessionId() {
    return sessionId;
}