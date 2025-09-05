#include "linked_list.h"

// Partition list around x: nodes < x come before nodes >= x (stable)
Node* partition(Node* head, int x) {
    Node dummy1(0), dummy2(0);
    Node *l = &dummy1, *r = &dummy2;
    while (head) {
        if (head->data < x) { l->next = head; l = l->next; }
        else { r->next = head; r = r->next; }
        head = head->next;
    }
    r->next = nullptr; l->next = dummy2.next; return dummy1.next;
}

int main() {
    Node* head = nullptr; insertAtEnd(head,3); insertAtEnd(head,5); insertAtEnd(head,8);
    insertAtEnd(head,5); insertAtEnd(head,10); insertAtEnd(head,2); insertAtEnd(head,1);
    std::cout << "Before: "; printList(head);
    head = partition(head,5);
    std::cout << "After partition around 5: "; printList(head);
    deleteList(head);
    return 0;
}