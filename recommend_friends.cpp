#include "SocialNetwork.h"
#include <iostream>
#include <algorithm>

void SocialNetwork::recommend_friends(int u, int k) {
    if (!exists(u)) { std::cout << "Invalid user\n"; return; }
    std::unordered_map<int,int> score;
    for (int f : adj.at(u)) {
        for (int fof : adj.at(f)) {
            if (fof == u) continue;
            if (adj.at(u).count(fof)) continue; // already friend
            score[fof]++;
        }
    }
    std::vector<std::pair<int,int>> vec; // (score, id)
    for (auto &p : score) vec.push_back({p.second, p.first});
    std::sort(vec.begin(), vec.end(), [](auto &a, auto &b){
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });
    std::cout << "Recommendations for " << u << ":";
    int printed = 0;
    for (auto &pr : vec) {
        std::cout << " " << pr.second << "(" << pr.first << ")";
        if (++printed >= k) break;
    }
    if (printed == 0) std::cout << " none";
    std::cout << std::endl;
}
