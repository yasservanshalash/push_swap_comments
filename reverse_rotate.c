#include "push_swap.h"

void reverse_rotate(t_stack *stack) {
    if (stack && stack->head && stack->head->next != stack->head) {
        stack->head = stack->head->prev; // Move head to the previous element
    }
}

void rra(t_stack *stack) {
    reverse_rotate(stack); // rrb is identical to rra, but operates on stack b
    write(1, "rra\n", 4);
}

void rrb(t_stack *stack) {
    reverse_rotate(stack); // rrb is identical to rra, but operates on stack b
    write(1, "rrb\n", 4);
}


void rrr(t_stack *a, t_stack *b) {
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
}