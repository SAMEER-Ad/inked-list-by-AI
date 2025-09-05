#include "linked_list.h"

int main() {
    Node* head = nullptr;
    for (int i = 1; i <= 6; ++i) insertAtEnd(head, i);
    std::cout << "Original: "; printList(head);
    Node* r = reverseIterative(head);
    std::cout << "Iterative reverse: "; printList(r);
    Node* back = reverseRecursive(r);
    std::cout << "Recursive reverse back: "; printList(back);
    deleteList(back);
    return 0;
}