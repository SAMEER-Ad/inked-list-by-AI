#include "linked_list.h"

Node* swapPairs(Node* head) {
    Node dummy(0); dummy.next = head; Node* prev = &dummy;
    while (prev->next && prev->next->next) {
        Node* a = prev->next; Node* b = a->next;
        a->next = b->next; b->next = a; prev->next = b; prev = a;
    }
    return dummy.next;
}

int main() {
    Node* head = nullptr; for (int i=1;i<=6;++i) insertAtEnd(head,i);
    std::cout << "Before: "; printList(head);
    head = swapPairs(head);
    std::cout << "After swap pairs: "; printList(head);
    deleteList(head);
    return 0;
}