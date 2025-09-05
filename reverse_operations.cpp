#include "linked_list.h"

// Iterative reverse: returns new head
Node* reverseIterative(Node* head) {
    Node* prev = nullptr;
    Node* cur = head;
    while (cur) {
        Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}

// Recursive reverse helper: returns new head
Node* reverseRecursive(Node* head) {
    if (!head || !head->next) return head;
    Node* rest = reverseRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return rest;
}

int main() {
    Node* head = nullptr;
    // build list 1->2->3->4
    for (int i = 4; i >= 1; --i) insertAtHead(head, i);
    std::cout << "Original: ";
    printList(head);

    Node* rev1 = reverseIterative(head);
    std::cout << "Reversed (iterative): ";
    printList(rev1);

    Node* rev2 = reverseRecursive(rev1);
    std::cout << "Reversed back (recursive): ";
    printList(rev2);

    deleteList(rev2);
    return 0;
}