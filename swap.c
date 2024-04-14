#include "push_swap.h"

int swap(t_stack *stack) {
    t_node *first;
    t_node *second;
    long tmp_value; // Assuming data holds a value like 'long' for the swap; adjust type as needed
    int tmp_index; // Assuming an 'index' field exists and is relevant; adjust type as needed

    // Check if there are at least two nodes in the stack
    if (stack == NULL || stack->head == NULL || stack->head->next == stack->head) {
        // Not enough nodes to swap, or invalid stack
        return (-1);
    }

    first = stack->head;
    second = first->next;

    // Swap 'value' and 'index' between the first two nodes
    tmp_value = first->data; // Adjust 'data' to 'value' if your node structure uses 'value'
    tmp_index = first->index; // Assuming an 'index' exists

    first->data = second->data; // Adjust 'data' to 'value' if your node structure uses 'value'
    first->index = second->index;

    second->data = tmp_value; // Adjust 'data' to 'value' if your node structure uses 'value'
    second->index = tmp_index;

    return (0);
}



void sa(t_stack *stack) {
    swap(stack);
    write(1, "sa\n", 3);
}

void sb(t_stack *stack) {
    swap(stack);
    write(1, "sb\n", 3);
}

void ss(t_stack *stack_a, t_stack *stack_b) {
    swap(stack_a);
    swap(stack_b);
    write(1, "ss\n", 3);
}