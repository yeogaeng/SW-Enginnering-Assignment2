#pragma once
#include <string>
#include <vector>
#include <utility>

using std::vector;
using std::pair;
using std::string;

class LoginUI {
    public:
        static bool handleLogin(const string& id, const string& password);
};