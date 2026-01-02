#include "SocialNetwork.h"
#include <iostream>

void SocialNetwork::remove_user(int id) {
    if (!exists(id)) { std::cout << "User not found\n"; return; }
    for (int nb : adj[id]) adj[nb].erase(id);
    adj.erase(id);
    names.erase(id);
    std::cout << "Removed user " << id << std::endl;
}
