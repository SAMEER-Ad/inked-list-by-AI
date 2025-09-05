#include "linked_list.h"

// Merge two sorted lists into one sorted list (reuses nodes)
Node* mergeSorted(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;
    Node dummy(0);
    Node* tail = &dummy;
    while (a && b) {
        if (a->data <= b->data) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next = (a ? a : b);
    return dummy.next;
}

int main() {
    // list A: 1->3->5
    Node* A = nullptr;
    insertAtEnd(A, 1);
    insertAtEnd(A, 3);
    insertAtEnd(A, 5);

    // list B: 2->4->6->8
    Node* B = nullptr;
    insertAtEnd(B, 2);
    insertAtEnd(B, 4);
    insertAtEnd(B, 6);
    insertAtEnd(B, 8);

    std::cout << "A: "; printList(A);
    std::cout << "B: "; printList(B);

    Node* M = mergeSorted(A, B);
    std::cout << "Merged: "; printList(M);

    deleteList(M);
    return 0;
}