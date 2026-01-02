#include "SocialNetwork.h"
#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>

void SocialNetwork::shortest_path(int s, int t) {
    if (!exists(s) || !exists(t)) { std::cout << "Invalid user\n"; return; }
    std::unordered_map<int,int> parent;
    std::queue<int> q; q.push(s); parent[s] = -1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == t) break;
        for (int v : adj[u]) if (!parent.count(v)) { parent[v] = u; q.push(v); }
    }
    if (!parent.count(t)) { std::cout << "No path from " << s << " to " << t << std::endl; return; }
    std::vector<int> path;
    for (int cur = t; cur != -1; cur = parent[cur]) path.push_back(cur);
    std::reverse(path.begin(), path.end());
    std::cout << "Shortest path from " << s << " to " << t << ":";
    for (int id : path) std::cout << " " << id;
    std::cout << std::endl;
}
