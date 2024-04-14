#include "push_swap.h"

void push_to(t_stack **dest, t_stack **src) {
    if (!src || !(*src)->head) return; // Ensure src is not empty

    t_node *node = (*src)->head; // Node to move from src

    // Remove node from src
    if (node->next == node) { // If only one element in src
        (*src)->head = NULL;
    } else {
        (*src)->head = node->next;
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    // Prepare node for insertion
    node->next = node->prev = NULL; // Isolate node, though not strictly necessary for a stack

    // Add node to dest as the new head (top of the stack)
    if (!(*dest) || !(*dest)->head) { // If dest is empty
        (*dest)->head = node;
        node->next = node->prev = node; // Make it circular by pointing to itself
    } else {
        // Make node the new head of dest
        node->next = (*dest)->head;
        node->prev = (*dest)->head->prev;
        (*dest)->head->prev->next = node; // Connect the last node to the new node
        (*dest)->head->prev = node; // This line is actually unnecessary for stack behavior
        (*dest)->head = node;
    }
}


void pa(t_stack **a, t_stack **b) {
    push_to(a, b); // Take the first element at the top of B and put it at the top of A
    write(1, "pa\n", 3);
}

void pb(t_stack **a, t_stack **b) {
    push_to(b, a); // Take the first element at the top of A and put it at the top of B
    write(1, "pb\n", 3);
}