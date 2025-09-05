#include "linked_list.h"

// Find intersection node (by pointer) of two lists
Node* getIntersection(Node* a, Node* b) {
    Node* p = a; Node* q = b;
    while (p != q) { p = p ? p->next : b; q = q ? q->next : a; }
    return p; // nullptr if no intersection
}

int main() {
    // Create two lists that intersect
    Node* a = nullptr; insertAtEnd(a,1); insertAtEnd(a,2); insertAtEnd(a,3);
    Node* b = nullptr; insertAtEnd(b,4); insertAtEnd(b,5);
    // attach b tail to a->next (value 2)
    Node* tailb = b; while (tailb->next) tailb = tailb->next;
    Node* attach = a->next; tailb->next = attach;
    std::cout << "List A: "; printList(a);
    std::cout << "List B: "; // careful: B shares nodes after attach, print safely
    Node* tmp = b; int i=0; while (tmp && i<10) { std::cout<<tmp->data; if (tmp->next) std::cout<<" -> "; tmp=tmp->next; ++i; }
    std::cout << " -> ...\n";
    Node* inter = getIntersection(a,b);
    std::cout << "Intersection at: " << (inter?std::to_string(inter->data):std::string("none")) << std::endl;
    // cleanup: break intersection to delete without double free
    tailb->next = nullptr;
    deleteList(a); deleteList(b);
    return 0;
}