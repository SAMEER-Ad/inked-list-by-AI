// Function to insert a node at the beginning of a linked list
struct Node {
    int data;
    Node* next;
};

void insertAtBeginning(Node** head_ref, int new_data) {
    // Allocate a new node
    Node* new_node = new Node();
    new_node->data = new_data; // Put in the data
    new_node->next = (*head_ref); // Make next of new node as head
    (*head_ref) = new_node; // Move the head to point to the new node
}