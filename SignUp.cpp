// SignUp.cpp
#include "SignUp.h"

SignUp::SignUp(MemberRepository& repo)
  : memberRepo(repo)
{}

bool SignUp::handleSignUp(string id, string password, string phoneNumber) {
    // addMember가 nullptr을 반환하면 중복 ID
    return memberRepo.addNewMember(id, password, phoneNumber) != nullptr;
}