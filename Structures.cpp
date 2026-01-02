#include <iostream>
#include <string>
using namespace std;


class User { // defines user entity 
public:
    int id; // unique number for each user 
    string name; // user personal information 
    string city;
};

class Node { // linked list node 
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};