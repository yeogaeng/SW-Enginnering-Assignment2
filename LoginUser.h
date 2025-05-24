#ifndef LOGINUSER_H
#define LOGINUSER_H

#include <string>

using std::string;

// <<entity>> LoginUser: 로그인 세션 관리 클래스
class LoginUser {
private:
    static int sessionNum;
    // 현재 활성화된 세션 ID
    static string sessionId;

    // 생성자 삭제: 인스턴스를 직접 생성할 수 없음
    LoginUser() = delete;

public:
    // 로그인 요청: 성공 시 새로운 세션 생성 후 true 반환
    // memberNum: 회원 번호, id: 회원 로그인 아이디
    static bool addLoginUser(int memberNum, const string& id);

    // 로그아웃 요청: 활성 세션이 있으면 해제 후 true 반환
    static bool deleteLoginUser();

    // 로그인 상태 조회: true면 세션 활성화됨
    static bool isLogin();

    // (선택) 현재 세션 번호 반환
    static int getSessionNum();

    // (선택) 현재 세션 ID 반환
    static string getSessionId();
};

#endif // LOGINUSER_H