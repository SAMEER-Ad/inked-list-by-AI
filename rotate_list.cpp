#include "linked_list.h"

// Rotate right by k
Node* rotateRight(Node* head, int k) {
    if (!head || !head->next || k==0) return head;
    int n = 1; Node* tail = head;
    while (tail->next) { tail = tail->next; ++n; }
    k %= n; if (!k) return head;
    tail->next = head; // make circle
    int steps = n - k;
    Node* newTail = head;
    for (int i=1;i<steps;++i) newTail = newTail->next;
    Node* newHead = newTail->next; newTail->next = nullptr; return newHead;
}

int main() {
    Node* head = nullptr; for (int i=1;i<=6;++i) insertAtEnd(head,i);
    printList(head);
    head = rotateRight(head, 2);
    std::cout << "After rotate by 2: "; printList(head);
    deleteList(head);
    return 0;
}