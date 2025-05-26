// LendBicycle.h
#pragma once

#include <string>
#include <utility>
#include "BicycleRepository.h"
#include "MemberRepository.h"
#include "LoginUser.h"

using std::string;
using std::pair;

// 자전거 대여 기능을 위한 LendBicycle 클래스 정의
class LendBicycle {
private:
    BicycleRepository& bicycleRepository;     // 자전거 정보를 관리하는 Repository 참조
    MemberRepository& memberRepository;       // 회원 정보를 관리하는 Repository 참조
    LoginUser& session;                       // 현재 로그인 세션 정보를 관리하는 객체 참조

public:
    /*
        함수 이름 : LendBicycle::LendBicycle()
        기능      : LendBicycle 클래스의 생성자로, Repository들과 LoginUser 참조를 초기화함
        전달 인자 : BicycleRepository& bicycleRepository - 자전거 정보를 관리하는 Repository 객체의 참조
                   MemberRepository& memberRepository - 회원 정보를 관리하는 Repository 객체의 참조
                   LoginUser& session - 로그인 세션 정보를 관리하는 객체의 참조
        반환값    : 없음
    */
    LendBicycle(BicycleRepository& bicycleRepository, MemberRepository& memberRepository, LoginUser& session);

    /*
        함수 이름 : LendBicycle::lendBicycle()
        기능      : 자전거를 대여함
        전달 인자 : string bicycleId - 대여할 자전거 ID
        반환값    : pair<string,string> -> 대여 성공 시 {자전거ID, 자전거이름}, 실패 시 {"", ""}
    */
    pair<string,string> lendBicycle(string bicycleId);
};