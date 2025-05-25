// LoginUser.cpp
#include "LoginUser.h"

// 생성자: currentMember 를 nullptr 로 초기화
LoginUser::LoginUser()
  : currentMember(nullptr)
{}

// 로그인: member 가 nullptr 이거나 이미 로그인된 상태면 실패
bool LoginUser::addLoginUser(Member* member) {
    if (!member || currentMember) {
        return false;
    }
    currentMember = member;
    return true;
}

// 로그아웃: 언제나 성공, currentMember 를 해제(nullptr)
void LoginUser::deleteLoginUser() {
    currentMember = nullptr;
}

// 지금 로그인 중인 Member* 반환 (nullptr 이면 로그아웃 상태)
Member* LoginUser::whoIsLogin() {
    return currentMember;
}