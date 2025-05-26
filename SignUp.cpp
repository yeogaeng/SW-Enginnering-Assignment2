// SignUp.cpp
#include "SignUp.h"

/*
    함수 이름 : SignUp::SignUp()
    기능      : SignUp 클래스의 생성자로, MemberRepository 참조를 초기화함
    전달 인자 : MemberRepository& repo - 회원 정보를 관리하는 Repository 객체의 참조
    반환값    : 없음
*/
SignUp::SignUp(MemberRepository& repo)
  : memberRepository(repo)
{}

/*
    함수 이름 : SignUp::signUp()
    기능      : 신규 회원을 등록함
    전달 인자 : string id - 회원 ID
               string password - 회원 비밀번호
               string phoneNumber - 회원 전화번호
    반환값    : bool -> 회원가입 성공 시 true, 실패 시 false
*/
bool SignUp::signUp(string id, string password, string phoneNumber) {
    // addNewMember가 nullptr을 반환하면 중복 ID로 인한 가입 실패
    return memberRepository.addNewMember(id, password, phoneNumber) != nullptr;
}