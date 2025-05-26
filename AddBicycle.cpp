// AddBicycle.cpp
#include "AddBicycle.h"

/*
    함수 이름 : AddBicycle::AddBicycle()
    기능      : AddBicycle 클래스의 생성자로, BicycleRepository 참조를 초기화함
    전달 인자 : BicycleRepository& bicycleRepository - 자전거 정보를 관리하는 Repository 객체의 참조
    반환값    : 없음
*/
AddBicycle::AddBicycle(BicycleRepository& bicycleRepository)
  : bicycleRepository(bicycleRepository)
{}

/*
    함수 이름 : AddBicycle::addBicycle()
    기능      : 신규 자전거를 등록함
    전달 인자 : string bicycleId - 자전거 ID
               string bicycleName - 자전거 이름
    반환값    : bool -> 자전거 등록 성공 시 true, 실패 시 false
*/
bool AddBicycle::addBicycle(string bicycleId, string bicycleName) {
    // addBicycle이 nullptr을 반환하면 중복 ID로 인한 등록 실패
    return bicycleRepository.addBicycle(bicycleId, bicycleName) != nullptr;
}