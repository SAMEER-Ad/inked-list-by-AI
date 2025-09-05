#include "linked_list.h"

bool isPalindrome(Node* head) {
    if (!head || !head->next) return true;
    // find middle
    Node* slow = head; Node* fast = head;
    while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
    // reverse second half
    Node* second = reverseIterative(slow);
    Node* p = head; Node* q = second; bool ok = true;
    while (q) { if (p->data != q->data) { ok = false; break; } p = p->next; q = q->next; }
    // restore
    reverseIterative(second);
    return ok;
}

int main() {
    Node* head = nullptr; insertAtEnd(head,1); insertAtEnd(head,2); insertAtEnd(head,3);
    insertAtEnd(head,2); insertAtEnd(head,1);
    printList(head);
    std::cout << "Palindrome: " << (isPalindrome(head)?"Yes":"No") << std::endl;
    deleteList(head);
    return 0;
}