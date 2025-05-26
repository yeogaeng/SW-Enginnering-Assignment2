// SignUp.cpp
#include "SignUp.h"

SignUp::SignUp(MemberRepository& repo)
  : memberRepository(repo)
{}

bool SignUp::signUp(string id, string password, string phoneNumber) {
    // addMember가 nullptr을 반환하면 중복 ID
    return memberRepository.addNewMember(id, password, phoneNumber) != nullptr;
}