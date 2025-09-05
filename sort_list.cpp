#include "linked_list.h"

// Merge sort for linked list
Node* splitMiddle(Node* head) {
    if (!head) return nullptr;
    Node* slow = head; Node* fast = head->next;
    while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
    Node* mid = slow->next; slow->next = nullptr; return mid;
}

Node* mergeSort(Node* head) {
    if (!head || !head->next) return head;
    Node* mid = splitMiddle(head);
    Node* left = mergeSort(head);
    Node* right = mergeSort(mid);
    return mergeSorted(left,right);
}

int main() {
    Node* head = nullptr;
    insertAtEnd(head, 4); insertAtEnd(head,1); insertAtEnd(head,3);
    insertAtEnd(head,2); insertAtEnd(head,5);
    std::cout << "Unsorted: "; printList(head);
    head = mergeSort(head);
    std::cout << "Sorted: "; printList(head);
    deleteList(head);
    return 0;
}