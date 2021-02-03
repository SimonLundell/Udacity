#include <iostream>

struct Node {
  int data;
  Node* next;
};

int main () {
  // create a new pointer, pointing to a type node. Create 2 more pointers to track the head and next node, all assigned to point to new node.
    Node* n = new Node;
    Node* h = n;
    Node* t = n;
    n->data = 1;
  // Create a new node pointer, assign it some data, make old node point to new node and assign the temp pointer "t" to point to the new node.
    n = new Node;
    n->data = 2;
    t->next = n;
    t = t->next;
  // same as above
    n = new Node;
    n->data = 3;
    t->next = n;
    t = t->next;
  // same as above, but setting the "leaf" node to not point anywhere.
    n = new Node;
    n->data = 25;
    t->next = n;
    n->next = nullptr;

    //std::cout << t->data << " " << n->next << " " << h->data << "\n";
    n = h;
    while (n != nullptr) {
      
      std::cout << n->data << "\n";
      n = n->next;
    }
}