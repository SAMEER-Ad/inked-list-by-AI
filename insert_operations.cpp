#include "linked_list.h"

// Insert at beginning
void insertAtHead(Node*& head, int value) {
    Node* n = new Node(value);
    n->next = head;
    head = n;
}

// Insert at end
void insertAtEnd(Node*& head, int value) {
    Node* n = new Node(value);
    if (!head) { head = n; return; }
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = n;
}

// Insert at position (0-based). If pos >= length, inserts at end.
void insertAtPosition(Node*& head, int value, int pos) {
    if (pos <= 0 || !head) { insertAtHead(head, value); return; }
    Node* cur = head;
    int i = 0;
    while (cur->next && i < pos - 1) {
        cur = cur->next;
        ++i;
    }
    Node* n = new Node(value);
    n->next = cur->next;
    cur->next = n;
}

int main() {
    Node* head = nullptr;
    insertAtHead(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtPosition(head, 15, 1); // between 10 and 20
    std::cout << "After inserts: ";
    printList(head);
    deleteList(head);
    return 0;
}