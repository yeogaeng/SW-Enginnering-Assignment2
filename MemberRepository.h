#pragma once

#include <vector>
#include <string>
#include "Member.h"

using std::vector;
using std::string;

// <<repository>> MemberRepository: 회원 저장·조회 책임
class MemberRepository {
private:
    vector<Member*> members;   // 저장된 모든 Member 객체
    int nextMemberNum;  
     // ID로 회원 조회: 없으면 nullptr
    Member* findMemberById(string id);      // 새 회원 번호 발급기

public:
    // 생성자: 발급기를 1번부터 시작
    MemberRepository();

    // 소멸자: 동적 할당된 Member 메모리 해제
    ~MemberRepository();

    // 신규 회원 추가: 중복 ID면 nullptr 반환, 성공 시 생성된 Member* 반환
    Member* addNewMember(string id, string password, string phoneNumber);

    // ID/PW 검증: 일치하면 Member* 반환, 아니면 nullptr
    Member* authenticate(string id, string password);


};