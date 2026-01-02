# Friend Recommendation System 🔗

**A simple C++ console application that models a social network and provides basic features such as adding users, creating friendships, finding mutual friends, recommending friends, discovering communities, and computing shortest paths.**

---

## 🔧 Features

- Add user (name, city)
- Add friendship between users
- Find mutual friends between two users
- Recommend friends based on number of mutual friends
- Display the full network
- Detect communities (connected components) using DFS
- Search for a user by name
- Sort users alphabetically
- Compute shortest path distance between two users (BFS)
- Remove user

---

## Requirements

- A C++ compiler supporting **C++11 or later** (e.g., **g++ 5+**, **clang 3.3+**, **MSVC 2015+**)
- Recommended compile flags: `-std=c++11` or `-std=c++17` for GNU/Clang; for MSVC use `/std:c++17` (if available)
- No external libraries are required (standard library only)
- Cross-platform: Windows, macOS, and Linux supported
- Optional build tools: `make`, **CMake**, or an IDE (Visual Studio, CLion, Code::Blocks)

**Quick compile examples:**

```bash
# GNU/Clang
g++ -std=c++11 main.cpp SocialNetwork.cpp Structures.cpp -o friendrec

# Windows (MinGW/GCC)
g++ -std=c++11 main.cpp SocialNetwork.cpp Structures.cpp -o friendrec.exe

# MSVC (Developer Command Prompt)
cl /EHsc /std:c++17 main.cpp SocialNetwork.cpp Structures.cpp
```

---

## Build

From the project root (where `main.cpp`, `SocialNetwork.cpp`, and `Structures.cpp` live):

```bash
# GNU/Clang
g++ main.cpp SocialNetwork.cpp Structures.cpp -o friendrec

# Windows (if MinGW/GCC):
# g++ main.cpp SocialNetwork.cpp Structures.cpp -o friendrec.exe
```

Or open the files in your favorite IDE (Visual Studio / Code::Blocks / CLion) and build the project.

---

## Run

```bash
# On Unix/macOS
./friendrec

# On Windows
friendrec.exe
```

The program runs as an interactive console menu. You will be prompted to enter choices and required IDs or names.

---

## Example session

```
1.Add User
2.Add Friend
3.Mutual Friends
4.Recommend Friends
5.Display Network
6.Find Communities
7.Search User
8.Sort Users
9.Shortest Path
10.Remove User
0.Exit
Choice: 1
Enter name: Alice
Enter city: London
User added with ID: 0

Choice: 1
Enter name: Bob
Enter city: Paris
User added with ID: 1

Choice: 2
u v: 0 1
Friendship added

Choice: 5
Alice -> Bob
Bob -> Alice

Choice: 0
```

Notes:
- When adding friends or querying, use user IDs (shown when adding/finding users).

---

## Limitations & Notes 💡

- Maximum users: **100** (defined by `MAX` in `SocialNetwork.cpp`)
- No persistence: data is in-memory and lost when the program exits
- Simple linked-list adjacency representation (see `Structures.cpp` / `SocialNetwork.cpp`)

---

## Contributing

Feel free to open issues or submit PRs to:
- Add persistence (file/DB)
- Increase scalability (use dynamic containers like `std::vector` / `std::unordered_map`)
- Improve CLI UX or add tests

---

## License

This repository is provided as-is. Add a proper license file if you plan on sharing or collaborating publicly.

---

Enjoy! ✅
