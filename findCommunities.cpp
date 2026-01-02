#include "SocialNetwork.h"
#include <iostream>
#include <queue>

void SocialNetwork::findCommunities() {
    std::unordered_set<int> vis;
    for (auto &p : adj) {
        int id = p.first;
        if (vis.count(id)) continue;
        std::vector<int> comp;
        std::queue<int> q; q.push(id); vis.insert(id);
        while (!q.empty()) {
            int cur = q.front(); q.pop(); comp.push_back(cur);
            for (int nb : adj[cur]) if (!vis.count(nb)) { vis.insert(nb); q.push(nb); }
        }
        std::cout << "Community:";
        for (int u : comp) std::cout << " " << u;
        std::cout << std::endl;
    }
}
