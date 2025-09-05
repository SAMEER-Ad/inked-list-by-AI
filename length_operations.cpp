#include "linked_list.h"

int main() {
    Node* head = nullptr;
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    std::cout << "Length: " << length(head) << std::endl;
    deleteList(head);
    return 0;
}