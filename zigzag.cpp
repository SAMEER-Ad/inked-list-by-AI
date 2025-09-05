#include "linked_list.h"

// Rearrange L0->L1->L2->L3... to L0->Ln->L1->Ln-1->...
void zigzag(Node*& head) {
    if (!head || !head->next) return;
    // find middle
    Node* slow = head; Node* fast = head;
    while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
    Node* second = reverseIterative(slow);
    Node* first = head;
    // merge alternately
    while (first && second) {
        Node* n1 = first->next; Node* n2 = second->next;
        first->next = second; if (!n1) break;
        second->next = n1;
        first = n1; second = n2;
    }
}

int main() {
    Node* head = nullptr; for (int i=1;i<=7;++i) insertAtEnd(head,i);
    std::cout << "Before: "; printList(head);
    zigzag(head);
    std::cout << "Zigzag: "; printList(head);
    deleteList(head);
    return 0;
}