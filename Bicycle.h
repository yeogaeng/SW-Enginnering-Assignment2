// Bicycle.h
#ifndef BICYCLE_H
#define BICYCLE_H

#include <vector>
#include <string>

using std::vector;
using std::string;

// <<entity>> Bicycle: 자전거 엔티티
class Bicycle {
private:
    static int nextBicycleNum;
    static vector<Bicycle*> bicycleList;

    int bicycleNum;
    string bicycleId;
    string bicycleName;

    Bicycle(int bicycleNum, const string& bicycleId, const string& bicycleName);

public:
    // 신규 자전거 등록: 성공(true)/실패(false)
    static bool addNewBicycle(const string& bicycleId, const string& bicycleName);
    // ID로 조회
    static Bicycle* getBicycle(const string& bicycleId);

    // getters
    int getBicycleNum() const;
    string getId() const;
    string getName() const;
};

#endif // BICYCLE_H
