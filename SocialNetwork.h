#pragma once

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>

class SocialNetwork {
public:
    // Core API
    int add_user(const std::string& name = "");
    void add_friend(int u, int v);
    void mutual_friends(int u, int v);
    void recommend_friends(int u, int k = 5);
    void display_network();
    void findCommunities();

    // EXTRA IDEAS
    void search_user(const std::string& query);
    void sort_users();
    void shortest_path(int u, int v);
    void remove_user(int id);

private:
    std::unordered_map<int, std::unordered_set<int>> adj; // adjacency list
    std::unordered_map<int, std::string> names;           // optional names
    int nextId = 1;

    bool exists(int id) const;
};
