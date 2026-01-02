#include <iostream>
#include <string>
using namespace std;


class User {
public:
    int id;
    string name;
    string city;
};

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};