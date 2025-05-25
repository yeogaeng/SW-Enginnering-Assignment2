#ifndef LOGINUSER_H
#define LOGINUSER_H

#include <string>

using std::string;

// <<entity>> LoginUser: 로그인 세션 관리 클래스
class LoginUser {
private:
    // 현재 활성화된 세션 ID
    static string sessionId;

    // 생성자 삭제: 인스턴스를 직접 생성할 수 없음
    LoginUser() = delete;

public:
    // 로그인 요청: 성공 시 새로운 세션 생성 후 true 반환
    // id: 회원 로그인 아이디
    static bool addLoginUser(const string& id);

    // 로그아웃 요청: 활성 세션이 있으면 해제 후 true 반환
    static string deleteLoginUser();

    // 로그인 상태 조회: 세션 활성 중이면 id return. 없으면 null
    static string whoIsLogin();

    // (선택) 현재 세션 ID 반환
    static string getSessionId();
};

#endif // LOGINUSER_H