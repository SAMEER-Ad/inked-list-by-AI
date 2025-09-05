#include "linked_list.h"

// Demonstrates iterative and recursive traversal
void printRecursive(Node* head) {
    if (!head) { std::cout << "nullptr\n"; return; }
    std::cout << head->data;
    if (head->next) std::cout << " -> ";
    printRecursive(head->next);
}

int main() {
    Node* head = nullptr;
    for (int i = 1; i <= 5; ++i) insertAtEnd(head, i);
    std::cout << "Iterative: "; printList(head);
    std::cout << "Recursive: "; printRecursive(head);
    deleteList(head);
    return 0;
}