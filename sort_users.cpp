#include "SocialNetwork.h"
#include <iostream>
#include <algorithm>

void SocialNetwork::sort_users() {
    std::vector<std::pair<int,std::string>> vec;
    for (auto &p : names) vec.push_back(p);
    std::sort(vec.begin(), vec.end(), [](auto &a, auto &b){ return a.second < b.second; });
    std::cout << "Users sorted by name:";
    for (auto &p : vec) std::cout << " " << p.first << "(" << p.second << ")";
    std::cout << std::endl;
}
