// Bicycle.cpp
#include "Bicycle.h"

/*
    함수 이름 : Bicycle::Bicycle()
    기능      : Bicycle 클래스의 생성자로, 자전거 정보를 초기화함
    전달 인자 : int bicycleNum - 고유 자전거 번호
               string bicycleId - 자전거 ID
               string bicycleName - 자전거 이름
    반환값    : 없음
*/
Bicycle::Bicycle(int bicycleNum, string bicycleId, string bicycleName) : bicycleNum(bicycleNum), bicycleId(bicycleId), bicycleName(bicycleName)
{}

/*
    함수 이름 : Bicycle::getBicycleNum()
    기능      : 자전거의 고유 번호를 반환함
    전달 인자 : 없음
    반환값    : int -> 자전거 고유 번호
*/
int Bicycle::getBicycleNum() {
    return bicycleNum;
}

/*
    함수 이름 : Bicycle::getId()
    기능      : 자전거의 ID를 반환함
    전달 인자 : 없음
    반환값    : string -> 자전거 ID
*/
string Bicycle::getId() {
    return bicycleId;
}

/*
    함수 이름 : Bicycle::getName()
    기능      : 자전거의 이름을 반환함
    전달 인자 : 없음
    반환값    : string -> 자전거 이름
*/
string Bicycle::getName() {
    return bicycleName;
}