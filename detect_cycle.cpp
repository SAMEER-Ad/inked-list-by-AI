#include "linked_list.h"

// Floyd's cycle detection
bool hasCycle(Node* head) {
    Node* slow = head; Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    Node* head = nullptr;
    for (int i = 1; i <= 5; ++i) insertAtEnd(head, i);
    // make a cycle for demo: tail -> head->next
    Node* tail = head;
    while (tail->next) tail = tail->next;
    tail->next = head->next; // create cycle
    std::cout << "Has cycle: " << (hasCycle(head)?"Yes":"No") << std::endl;
    // Note: cannot delete list safely because of cycle
    return 0;
}