#include "SocialNetwork.h"
#include <iostream>

int SocialNetwork::add_user(const std::string& name) {
    int id = nextId++;
    adj[id] = {}; // create node
    if (!name.empty()) names[id] = name;
    std::cout << "Added user " << id << (name.empty() ? "" : (" (" + name + ")")) << std::endl;
    return id;
}
