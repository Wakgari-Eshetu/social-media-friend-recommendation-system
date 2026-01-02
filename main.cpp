#include <iostream>
#include "SocialNetwork.cpp"

using namespace std;

int main() {
    SocialNetwork sn;
    int choice, u, v;

    do {
        cout << "\n1.Add User\n2.Add Friend\n3.Mutual Friends\n4.Recommend Friends\n";
        cout << "5.Display Network\n6.Find Communities\n7.Search User\n";
        cout << "8.Sort Users\n9.Shortest Path\n10.Remove User\n0.Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1: sn.add_user(); break;
            case 2: cout << "u v: "; cin >> u >> v; sn.add_friend(u, v); break;
            case 3: cout << "u v: "; cin >> u >> v; sn.mutual_friends(u, v); break;
            case 4: cout << "u: "; cin >> u; sn.recommend_friends(u); break;
            case 5: sn.display_network(); break;
            case 6: sn.findCommunities(); break;
            case 7: sn.search_user(); break;
            case 8: sn.sort_users(); break;
            case 9: cout << "src dest: "; cin >> u >> v; sn.shortest_path(u, v); break;
            case 10: cout << "id: "; cin >> u; sn.remove_user(u); break;
        }
    } while (choice != 0);

    return 0;
}