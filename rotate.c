#include "push_swap.h"

void rotate(t_stack *stack) {
    if (stack && stack->head && stack->head->next != stack->head) {
        stack->head = stack->head->next; // Move head to the next element
    }
}

void ra(t_stack *stack) {
    rotate(stack);
    write(1, "ra\n", 3);
}

void rb(t_stack *stack) {
    rotate(stack);
    write(1, "rb\n", 3);
}


void rr(t_stack *a, t_stack *b) {
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}
