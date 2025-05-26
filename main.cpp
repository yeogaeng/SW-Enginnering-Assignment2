#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>


#include "SignUpUI.h"
#include "LoginUI.h"
#include "LogoutUI.h"
#include "AddBicycleUI.h"
#include "LendBicycleUI.h"
#include "ShowLendInfoUI.h" 

#include "SignUp.h"
#include "Login.h"
#include "Logout.h"
#include "AddBicycle.h"
#include "LendBicycle.h"
#include "ShowLendInfo.h" 

#include "MemberRepository.h"
#include "LoginUser.h"

using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::string;
using std::vector;
using std::cout;
using std::pair;

/*
	함수 이름 : main()
	기능	  : 자전거 대여 시스템의 메인 함수로, 파일 입출력을 통해 사용자 명령을 처리하고 결과를 출력함
	전달 인자 : 없음
	반환값    : int -> 프로그램 종료 상태 (0: 정상 종료, 1: 오류 발생)
*/
int main() {
    // 필요한 Repository와 Session 객체 생성
    MemberRepository memberRepository;
    // 미리 관리자 등록
    memberRepository.addNewMember("admin","admin","");
    LoginUser session;
    BicycleRepository bicycleRepository;

    // Controller 객체 생성 (비즈니스 로직 처리)
    SignUp      signUpCtrl(memberRepository);
    Login       loginCtrl(memberRepository, session);
    Logout      logoutCtrl(session);
    AddBicycle  addBicycleCtrl(bicycleRepository);
    LendBicycle lendBicycleCtrl(bicycleRepository, memberRepository, session);
    ShowLendInfo showLendCtrl(session);

    // UI 객체 생성 (입력/출력 처리)
    SignUpUI       signUpUI(signUpCtrl);
    LoginUI        loginUI(loginCtrl);
    LogoutUI       logoutUI(logoutCtrl);
    AddBicycleUI   addBicycleUI(addBicycleCtrl);
    LendBicycleUI  lendBicycleUI(lendBicycleCtrl);
    ShowLendInfoUI showLendUI(showLendCtrl);

    // 입력 파일 열기
    ifstream in("input.txt");
    if (!in.is_open()) {
        cout << "입력 파일을 열 수 없습니다.\n";
        return 1;
    }

    // 출력 파일 열기
    ofstream out("output.txt");
    if (!out.is_open()) {
        cout << "출력 파일을 열 수 없습니다.\n";
        return 1;
    }

    string line;
    // 입력 파일에서 한 줄씩 읽어서 처리
    while (std::getline(in, line)) {
        istringstream iss(line);
        int menu, action;
        string id, pw, phone, bicycleId, bicycleName;

        // 메뉴 번호와 액션 번호 읽기
        if (!(iss >> menu >> action)) {
            // 숫자 두 개를 읽을 수 없으면 해당 줄 무시
            continue;
        }

        // 메뉴 번호에 따라 해당 기능 수행
        switch (menu) {
            case 1:  // 회원 관리
                if (action == 1) {
                    // 1.1 회원가입: "1 1 ID PW phone"
                    if (iss >> id >> pw >> phone) {
                        if(signUpUI.handleSignUp(id, pw, phone)){
                            out << "1.1. 회원가입\n";
                            out << "> " << id << " " << pw << " " << phone << "\n\n";
                        }
                    }  
                }
                break;

            case 2:  // 로그인/로그아웃
                if (action == 1) {
                    // 2.1 로그인: "2 1 ID PW"
                    if (iss >> id >> pw) {
                        if(loginUI.handleLogin(id, pw)){
                            out << "2.1. 로그인\n";
                            out << "> " << id << " " << pw << "\n\n";
                        }
                    }
                }
                else if (action == 2) {
                    // 2.2 로그아웃: "2 2"
                    string logoutId = logoutUI.handleLogout();
                    if(!logoutId.empty()){
                        out << "2.2. 로그아웃\n";
                        out << "> " << logoutId << "\n\n";
                    }
                }
                break;

            case 3:  // 자전거 관리
                if (action == 1) {
                    // 3.1 자전거 등록: "3 1 bicycleId bicycleName"
                    if (iss >> bicycleId >> bicycleName) {
                        if(addBicycleUI.handleAddBicycle(bicycleId, bicycleName)){
                            out << "3.1. 자전거 등록\n";
                            out << "> " << bicycleId << " " << bicycleName << "\n\n";
                        }
                    }
                }
                break;

            case 4:  // 자전거 대여
                if (action == 1) {
                    // 4.1 자전거 대여: "4 1 bicycleId"
                    if (iss >> bicycleId) {
                        auto result = lendBicycleUI.handleLendBicycle(bicycleId);
                        if (!result.first.empty() || !result.first.empty()) {
                            out << "4.1. 자전거 대여\n";
                            out << "> " << result.first << " " << result.second << "\n\n";
                        }
                    }
                }
                break;

            case 5:  // 대여 정보 조회
                if (action == 1) {
                    // 5.1 대여 리스트: "5 1"
                    auto list = showLendUI.handleShowLendInfo();
                    out << "5.1. 자전거 대여 리스트\n";
                    for (auto&p : list) {
						string& id = p.first;
						string& name = p.second;
                        out << ">"; 
                        out << " " << id << " " << name << "\n";
                    }
                    out << "\n";
                }
                break;

            case 6:  // 프로그램 종료
                if (action == 1) {
                    // 6.1 종료: "6 1"
                    out << "6.1. 종료\n";
                    return 0; // 프로그램 정상 종료
                }
                break;

            // 그 외 메뉴/액션은 모두 무시
            default:
                break;
        }
    }
    
    // 파일 닫기
    in.close();
    out.close();
    return 0;
}