#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

// Simple singly-linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Inline implementations so example translation units can compile standalone
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

inline void insertAtHead(Node*& head, int value) {
    Node* n = new Node(value);
    n->next = head;
    head = n;
}

inline void insertAtEnd(Node*& head, int value) {
    Node* n = new Node(value);
    if (!head) { head = n; return; }
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = n;
}

inline void insertAtPosition(Node*& head, int value, int pos) {
    if (pos <= 0 || !head) { insertAtHead(head, value); return; }
    Node* cur = head;
    int i = 0;
    while (cur->next && i < pos - 1) { cur = cur->next; ++i; }
    Node* n = new Node(value);
    n->next = cur->next;
    cur->next = n;
}

inline int length(Node* head) {
    int len = 0;
    while (head) { ++len; head = head->next; }
    return len;
}

inline bool search(Node* head, int key) {
    while (head) { if (head->data == key) return true; head = head->next; }
    return false;
}

inline Node* reverseIterative(Node* head) {
    Node* prev = nullptr; Node* cur = head;
    while (cur) { Node* nxt = cur->next; cur->next = prev; prev = cur; cur = nxt; }
    return prev;
}

inline Node* reverseRecursive(Node* head) {
    if (!head || !head->next) return head;
    Node* rest = reverseRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return rest;
}

inline Node* mergeSorted(Node* a, Node* b) {
    Node dummy(0); Node* tail = &dummy;
    while (a && b) {
        if (a->data <= b->data) { tail->next = a; a = a->next; }
        else { tail->next = b; b = b->next; }
        tail = tail->next;
    }
    tail->next = a ? a : b;
    return dummy.next;
}

#endif // LINKED_LIST_H
