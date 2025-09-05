#include "linked_list.h"

// Remove cycle if exists (Floyd's algorithm to find start)
void removeCycle(Node* head) {
    Node* slow = head; Node* fast = head;
    bool found = false;
    while (fast && fast->next) {
        slow = slow->next; fast = fast->next->next;
        if (slow == fast) { found = true; break; }
    }
    if (!found) return;
    slow = head;
    Node* prev = nullptr; // to keep track of node before fast
    while (slow != fast) {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }
    // fast is at start of cycle; prev is last node in cycle
    if (prev) prev->next = nullptr;
}

int main() {
    Node* head = nullptr; for (int i=1;i<=6;++i) insertAtEnd(head,i);
    Node* tail = head; while (tail->next) tail = tail->next;
    tail->next = head->next->next; // cycle
    removeCycle(head);
    std::cout << "After removing cycle, list: "; printList(head);
    deleteList(head);
    return 0;
}