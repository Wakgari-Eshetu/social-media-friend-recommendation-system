#include "SocialNetwork.h"
#include <iostream>

void SocialNetwork::display_network() {
    for (auto &p : adj) {
        std::cout << p.first << ":";
        for (int v : p.second) std::cout << " " << v;
        auto it = names.find(p.first);
        if (it != names.end()) std::cout << " (" << it->second << ")";
        std::cout << std::endl;
    }
}
