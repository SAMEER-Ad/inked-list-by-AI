#include "linked_list.h"

int findMiddle(Node* head) {
    Node* slow = head; Node* fast = head;
    while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
    return slow ? slow->data : -1;
}

int main() {
    Node* head = nullptr; for (int i=1;i<=5;++i) insertAtEnd(head,i);
    std::cout << "List: "; printList(head);
    std::cout << "Middle: " << findMiddle(head) << std::endl;
    deleteList(head);
    return 0;
}