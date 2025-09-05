#include <iostream>

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Function to delete the first node
void deleteFirst(Node*& head) {
    if (head == nullptr) {
        std::cout << "List is empty. Nothing to delete." << std::endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    std::cout << "First node deleted." << std::endl;
}

// Function to delete the last node
void deleteLast(Node*& head) {
    if (head == nullptr) {
        std::cout << "List is empty. Nothing to delete." << std::endl;
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        std::cout << "Last node deleted." << std::endl;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    std::cout << "Last node deleted." << std::endl;
}

// Function to delete a node by value
void deleteByValue(Node*& head, int value) {
    if (head == nullptr) {
        std::cout << "List is empty. Nothing to delete." << std::endl;
        return;
    }
    // If the head node itself holds the value to be deleted
    if (head->data == value) {
        deleteFirst(head);
        return;
    }
    Node* temp = head;
    Node* prev = nullptr;
    while (temp != nullptr && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) {
        std::cout << "Value " << value << " not found in the list." << std::endl;
        return;
    }
    prev->next = temp->next;
    delete temp;
    std::cout << "Node with value " << value << " deleted." << std::endl;
}

// Function to delete a node by position
void deleteByPosition(Node*& head, int position) {
    if (head == nullptr) {
        std::cout << "List is empty. Nothing to delete." << std::endl;
        return;
    }
    if (position == 0) {
        deleteFirst(head);
        return;
    }
    Node* temp = head;
    Node* prev = nullptr;
    for (int i = 0; temp != nullptr && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) {
        std::cout << "Position " << position << " is out of bounds." << std::endl;
        return;
    }
    prev->next = temp->next;
    delete temp;
    std::cout << "Node at position " << position << " deleted." << std::endl;
}

// Function to delete all nodes
void deleteAll(Node*& head) {
    while (head != nullptr) {
        deleteFirst(head);
    }
    std::cout << "All nodes deleted." << std::endl;
}

// Example usage
int main() {
    Node* head = nullptr; // Start with an empty list

    // Example operations can be added here

    return 0;
}