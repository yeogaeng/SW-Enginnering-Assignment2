#pragma once

#include <vector>
#include <string>
#include "Member.h"

using std::vector;
using std::string;

// 회원 정보 저장 및 조회를 담당하는 MemberRepository 클래스 정의
class MemberRepository {
private:
    vector<Member*> members;    // 저장된 모든 Member 객체들의 포인터 벡터
    int nextMemberNum;          // 다음 회원에게 부여할 회원 번호
    
    /*
        함수 이름 : MemberRepository::findMemberById()
        기능      : ID로 회원을 조회함
        전달 인자 : string id - 조회할 회원 ID
        반환값    : Member* -> 찾은 회원 객체의 포인터, 없으면 nullptr
    */
    Member* findMemberById(string id);

public:
    /*
        함수 이름 : MemberRepository::MemberRepository()
        기능      : MemberRepository 클래스의 생성자로, 회원 번호 발급기를 1번부터 시작하도록 초기화함
        전달 인자 : 없음
        반환값    : 없음
    */
    MemberRepository();

    /*
        함수 이름 : MemberRepository::~MemberRepository()
        기능      : MemberRepository 클래스의 소멸자로, 동적 할당된 Member 객체들의 메모리를 해제함
        전달 인자 : 없음
        반환값    : 없음
    */
    ~MemberRepository();

    /*
        함수 이름 : MemberRepository::addNewMember()
        기능      : 신규 회원을 추가함
        전달 인자 : string id - 회원 ID
                   string password - 회원 비밀번호
                   string phoneNumber - 회원 전화번호
        반환값    : Member* -> 생성된 회원 객체의 포인터, 중복 ID인 경우 nullptr
    */
    Member* addNewMember(string id, string password, string phoneNumber);

    /*
        함수 이름 : MemberRepository::authenticate()
        기능      : ID와 비밀번호를 검증하여 회원 인증을 수행함
        전달 인자 : string id - 회원 ID
                   string password - 회원 비밀번호
        반환값    : Member* -> 인증된 회원 객체의 포인터, 인증 실패 시 nullptr
    */
    Member* authenticate(string id, string password);
};