#include "SocialNetwork.h"
#include <iostream>

void SocialNetwork::mutual_friends(int u, int v) {
    if (!exists(u) || !exists(v)) { std::cout << "Invalid user(s)\n"; return; }
    const auto &A = adj.at(u);
    const auto &B = adj.at(v);
    std::vector<int> mutual;
    if (A.size() < B.size()) {
        for (int x : A) if (B.count(x)) mutual.push_back(x);
    } else {
        for (int x : B) if (A.count(x)) mutual.push_back(x);
    }
    std::cout << "Mutual friends of " << u << " and " << v << ":";
    if (mutual.empty()) std::cout << " none";
    for (int id : mutual) std::cout << " " << id;
    std::cout << std::endl;
}
