// ShowLendInfo.h
#pragma once

#include <vector>
#include <string>
#include <utility>

using std::vector;
using std::pair;
using std::string;

class LoginUser;

// 대여 정보 조회 기능을 위한 ShowLendInfo 클래스 정의
class ShowLendInfo {
private:
    LoginUser& session;     // 현재 로그인 세션 정보를 관리하는 객체 참조

public:
    /*
        함수 이름 : ShowLendInfo::ShowLendInfo()
        기능      : ShowLendInfo 클래스의 생성자로, LoginUser 참조를 초기화함
        전달 인자 : LoginUser& session - 로그인 세션 정보를 관리하는 객체의 참조
        반환값    : 없음
    */
    ShowLendInfo(LoginUser& session);

    /*
        함수 이름 : ShowLendInfo::showLendInfo()
        기능      : 로그인된 회원의 대여 정보 리스트를 조회함
        전달 인자 : 없음
        반환값    : vector<pair<string,string>> -> {자전거ID, 자전거이름} 쌍의 벡터
    */
    vector<pair<string,string>> showLendInfo();
};