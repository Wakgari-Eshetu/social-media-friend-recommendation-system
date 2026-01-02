#include "SocialNetwork.h"
#include <iostream>

void SocialNetwork::add_friend(int u, int v) {
    if (!exists(u) || !exists(v) || u == v) {
        std::cout << "Invalid friend operation for " << u << " & " << v << std::endl;
        return;
    }
    adj[u].insert(v);
    adj[v].insert(u);
    std::cout << "Added friendship: " << u << " - " << v << std::endl;
}
