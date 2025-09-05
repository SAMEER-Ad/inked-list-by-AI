#include "linked_list.h"

int kthFromEnd(Node* head, int k) {
    Node* a = head; Node* b = head;
    while (k-- && b) b = b->next;
    if (k >= -1 && !b && k>=0) return -1; // k too large
    while (b) { a = a->next; b = b->next; }
    return a ? a->data : -1;
}

int main() {
    Node* head = nullptr; for (int i=1;i<=7;++i) insertAtEnd(head,i);
    printList(head);
    std::cout << "3rd from end: " << kthFromEnd(head,3) << std::endl;
    deleteList(head);
    return 0;
}