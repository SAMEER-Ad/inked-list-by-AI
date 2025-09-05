#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Shared function declarations used across example translation units
void insertAtHead(Node*& head, int value);
void insertAtEnd(Node*& head, int value);
void insertAtPosition(Node*& head, int value, int pos);

// Lightweight helpers implemented inline for convenience
inline void printList(Node* head) {
    Node* cur = head;
    while (cur) {
        std::cout << cur->data;
        if (cur->next) std::cout << " -> ";
        cur = cur->next;
    }
    std::cout << " -> nullptr\n";
}

inline void deleteList(Node*& head) {
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

#endif // LINKED_LIST_H
