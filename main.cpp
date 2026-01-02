#include "SocialNetwork.h"
#include <iostream>

int main() {
    SocialNetwork sn;

    int a = sn.add_user("Alice");
    int b = sn.add_user("Bob");
    int c = sn.add_user("Carol");
    int d = sn.add_user("Dave");
    int e = sn.add_user("Eve");

    sn.add_friend(a, b);
    sn.add_friend(b, c);
    sn.add_friend(c, a);
    sn.add_friend(c, d);
    sn.add_friend(e, b);

    std::cout << "\n-- Network --\n";
    sn.display_network();

    std::cout << "\n-- Mutual friends --\n";
    sn.mutual_friends(a, c);

    std::cout << "\n-- Recommendations --\n";
    sn.recommend_friends(a, 5);

    std::cout << "\n-- Communities --\n";
    sn.findCommunities();

    std::cout << "\n-- Shortest path --\n";
    sn.shortest_path(a, d);

    std::cout << "\n-- Search & Sort --\n";
    sn.search_user("a");
    sn.sort_users();

    std::cout << "\n-- Remove Bob and show network --\n";
    sn.remove_user(b);
    sn.display_network();

    return 0;
}
