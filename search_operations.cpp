#include <iostream>

// Node structure for linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Insert at end helper
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) { head = newNode; return; }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// Search for a value in the list
bool search(Node* head, int key) {
    Node* temp = head;
    while (temp) {
        if (temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}

// Print list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr\n";
}

int main() {
    Node* head = nullptr;
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    printList(head); // 1 -> 2 -> 3 -> nullptr
    std::cout << "Search 2: " << (search(head, 2) ? "Found" : "Not found") << std::endl;
    std::cout << "Search 5: " << (search(head, 5) ? "Found" : "Not found") << std::endl;
    return 0;
}