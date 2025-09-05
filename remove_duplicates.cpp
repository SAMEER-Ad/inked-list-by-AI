#include "linked_list.h"
#include <unordered_set>

// Remove duplicates from unsorted list
void removeDuplicates(Node* head) {
    std::unordered_set<int> seen;
    Node* cur = head; Node* prev = nullptr;
    while (cur) {
        if (seen.count(cur->data)) {
            prev->next = cur->next;
            delete cur;
            cur = prev->next;
        } else {
            seen.insert(cur->data);
            prev = cur; cur = cur->next;
        }
    }
}

int main() {
    Node* head = nullptr;
    insertAtEnd(head, 1); insertAtEnd(head,2); insertAtEnd(head,1);
    insertAtEnd(head,3); insertAtEnd(head,2);
    std::cout << "Before: "; printList(head);
    removeDuplicates(head);
    std::cout << "After: "; printList(head);
    deleteList(head);
    return 0;
}