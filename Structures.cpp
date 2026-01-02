#include <iostream>
#include <string>
using namespace std;

// ---------------- USER CLASS ----------------
class User {
public:
    int id;
    string name;
    string city;
};

// ---------------- LINKED LIST NODE ----------------
class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};