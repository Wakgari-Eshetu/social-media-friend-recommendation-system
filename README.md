# SocialNetwork (C++ split implementation)

Files:
- `SocialNetwork.h` — class declaration
- `add_user.cpp`, `add_friend.cpp`, `mutual_friends.cpp`, `recommend_friends.cpp`, `display_network.cpp`, `findCommunities.cpp`, `search_user.cpp`, `sort_users.cpp`, `shortest_path.cpp`, `remove_user.cpp`, `exists.cpp` — one implementation file per method
- `main.cpp` — demo usage

Build (MinGW / GCC):

```
g++ -std=c++17 *.cpp -o socialnetwork.exe
```

Run:
```
./socialnetwork.exe
```

If you're using MSVC (Visual Studio Developer Command Prompt):
```
cl /EHsc *.cpp
```
