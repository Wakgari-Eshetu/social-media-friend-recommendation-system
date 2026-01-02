#include "SocialNetwork.h"
#include <iostream>

void SocialNetwork::search_user(const std::string& query) {
    std::cout << "Search results for '" << query << "':";
    bool any = false;
    for (auto &p : names) {
        if (p.second.find(query) != std::string::npos) {
            std::cout << " " << p.first << "(" << p.second << ")";
            any = true;
        }
    }
    if (!any) std::cout << " none";
    std::cout << std::endl;
}
