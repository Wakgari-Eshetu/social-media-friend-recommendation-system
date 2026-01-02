#include <queue>
#include "Structures.cpp" 

#define MAX 100

class SocialNetwork {
private:
    User users[MAX];
    int userCount;
    Node* adj[MAX];

public:
    SocialNetwork() {
        userCount = 0;
        for (int i = 0; i < MAX; i++)
            adj[i] = NULL;
    }

    void add_user() {
        if (userCount >= MAX) return;
        users[userCount].id = userCount;
        cout << "Enter name: "; cin >> users[userCount].name;
        cout << "Enter city: "; cin >> users[userCount].city;
        cout << "User added with ID: " << userCount << endl;
        userCount++;
    }

    void add_friend(int u, int v) {
        if (u >= userCount || v >= userCount) {
            cout << "Invalid user ID\n";
            return;
        }
        // Fixed insertion logic
        Node* newNodeU = new Node(v);
        newNodeU->next = adj[u];
        adj[u] = newNodeU;

        Node* newNodeV = new Node(u);
        newNodeV->next = adj[v];
        adj[v] = newNodeV;

        cout << "Friendship added\n";
    }

    void mutual_friends(int u, int v) {
        cout << "Mutual friends:\n";
        for (Node* t1 = adj[u]; t1 != NULL; t1 = t1->next) {
            for (Node* t2 = adj[v]; t2 != NULL; t2 = t2->next) {
                if (t1->data == t2->data)
                    cout << users[t1->data].name << endl;
            }
        }
    }

    void recommend_friends(int u) {
        if (u < 0 || u >= userCount) {
            cout << "User not found.\n";
            return;
        }

        int score[MAX] = {0};
        int distance[MAX];
        for(int i=0; i<MAX; i++) distance[i] = -1; // -1 means unvisited

        queue<int> q;

        // 1. Initialize BFS
        q.push(u);
        distance[u] = 0;

        // 2. Start BFS Discovery
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            // We only look up to 3 handshakes away (Distance 3)
            if (distance[curr] >= 3) continue; 

            Node* temp = adj[curr];
            while (temp != NULL) {
                int neighbor = temp->data;

                if (distance[neighbor] == -1) { // New person found
                    distance[neighbor] = distance[curr] + 1;
                    q.push(neighbor);

                    // --- SCORING LOGIC ---
                    
                    // If they are a friend of a friend (Distance 2)
                    if (distance[neighbor] == 2) {
                        score[neighbor] += 10; // High priority
                    }
                    // If they are a friend of a friend of a friend (Distance 3)
                    else if (distance[neighbor] == 3) {
                        score[neighbor] += 3; // Lower priority
                    }
                } 
                else if (distance[neighbor] > 1 && neighbor != u) {
                    // If we find them again via a different path, 
                    // it means they have ANOTHER mutual friend.
                    score[neighbor] += 5; 
                }
                temp = temp->next;
            }
        }

        // 3. APPLY OTHER FACTORS (City Matching)
        // We check every user in the system, even if BFS didn't reach them
        for (int i = 0; i < userCount; i++) {
            if (i == u || distance[i] == 1) continue; // Skip self and direct friends

            // Factor: Same City Bonus
            if (users[i].city == users[u].city) {
                score[i] += 7; 
            }
        }

        // 4. DISPLAY RESULTS
        cout << "\n--- Sophisticated Recommendations for " << users[u].name << " ---\n";
        bool found = false;
        for (int i = 0; i < userCount; i++) {
            if (score[i] > 0) {
                found = true;
                cout << ">> " << users[i].name 
                     << " | Strength: " << score[i] 
                     << " | Connection: ";
                
                if (distance[i] == 2) cout << "Friend of a friend";
                else if (distance[i] == 3) cout << "In your extended network";
                else if (distance[i] == -1) cout << "Lives in your city";
                else cout << "Suggested contact";
                
                if (users[i].city == users[u].city && distance[i] != -1) 
                    cout << " (Also in " << users[i].city << ")";
                
                cout << endl;
            }
        }

        if (!found) cout << "No recommendations found yet. Expand your network!\n";
    }

    void display_network() {
        for (int i = 0; i < userCount; i++) {
            cout << users[i].name << " -> ";
            for (Node* temp = adj[i]; temp != NULL; temp = temp->next)
                cout << users[temp->data].name << " ";
            cout << endl;
        }
    }

    void DFS(int v, bool visited[]) {
        visited[v] = true;
        cout << users[v].name << " ";
        for (Node* temp = adj[v]; temp != NULL; temp = temp->next)
            if (!visited[temp->data]) DFS(temp->data, visited);
    }

    void findCommunities() {
        bool visited[MAX] = {false};
        for (int i = 0; i < userCount; i++) {
            if (!visited[i]) {
                cout << "Community: ";
                DFS(i, visited);
                cout << endl;
            }
        }
    }

    void search_user() {
        string name;
        cout << "Enter name: "; cin >> name;
        for (int i = 0; i < userCount; i++)
            if (users[i].name == name) { cout << "Found ID " << users[i].id << endl; return; }
        cout << "Not found\n";
    }

    void sort_users() {
        for (int i = 0; i < userCount - 1; i++)
            for (int j = 0; j < userCount - i - 1; j++)
                if (users[j].name > users[j + 1].name) swap(users[j], users[j + 1]);
        cout << "Sorted\n";
    }

    void shortest_path(int src, int dest) {
        bool visited[MAX] = {false};
        int dist[MAX] = {0};
        queue<int> q;
        q.push(src);
        visited[src] = true;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (Node* t = adj[v]; t != NULL; t = t->next) {
                if (!visited[t->data]) {
                    visited[t->data] = true;
                    dist[t->data] = dist[v] + 1;
                    q.push(t->data);
                }
            }
        }
        cout << "Shortest distance: " << dist[dest] << endl;
    }

    void remove_user(int id) {
        for (int i = id; i < userCount - 1; i++) users[i] = users[i + 1];
        userCount--;
        cout << "User removed\n";
    }
};