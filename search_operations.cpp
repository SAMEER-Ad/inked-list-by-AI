#include "linked_list.h"

int main() {
    Node* head = nullptr;
    insertAtEnd(head, 5);
    insertAtEnd(head, 7);
    insertAtEnd(head, 9);
    printList(head);
    std::cout << "Search 7: " << (search(head,7)?"Found":"Not found") << std::endl;
    std::cout << "Search 4: " << (search(head,4)?"Found":"Not found") << std::endl;
    deleteList(head);
    return 0;
}