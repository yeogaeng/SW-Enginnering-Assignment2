#pragma once
#include <string>
#include <vector>
#include <utility>

class Login {
    public:
        static bool login(const std::string& id, const std::string& password);
};