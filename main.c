#include "push_swap.h"
int isEmpty(t_stack *stack);
int lstsize(t_stack *stack);
void sortStackAsc(t_stack** a, t_stack** b);
int is_sorted(t_stack *list);

int	main(int argc, char **argv)
{
	long	*numbers_array;
	int		size;
	t_stack	*a;
	t_stack	*b;

	numbers_array = return_numbers(argc, argv, &size);
    // printArray(numbers_array, size);
	a = array_to_stack_desc(numbers_array, size);
	b = (t_stack *)malloc(sizeof(t_stack));
    b->head = NULL;
    sortStackAsc(&a,&b);
	free(numbers_array);
	free_stack(a);
	free(b);
	return (0);
}

void sortStackAsc(t_stack** a, t_stack** b) {
    while (!isEmpty(*a) && !is_sorted(*a)) {
        // Find the smallest element in stack a
        int min = (*a)->head->data;
        int size = lstsize(*a);
        int minIndex = 0;
        for (int i = 0; i < size && !is_sorted(*a); i++) {
            if ((*a)->head->data < min) {
                min = (*a)->head->data;
                minIndex = i;
            }
            ra(*a);
        }

        // Move the smallest element to the top of stack a
        if (minIndex <= size / 2) {
            for (int i = 0; i < minIndex && !is_sorted(*a); i++) {
                ra(*a);
            }
        } else {
            for (int i = 0; i < size - minIndex && !is_sorted(*a); i++) {
                rra(*a);
            }
        }

        // Push the smallest element to stack b
        pb(a, b);
    }

    // Move all elements back to stack a
    while (!isEmpty(*b)) {
        pa(a, b);
    }
}

int isEmpty(t_stack *stack) {
    return (stack == NULL || stack->head == NULL);
}

int lstsize(t_stack *stack) {
    if (isEmpty(stack)) {
        return 0;
    }

    int count = 0;
    t_node *current = stack->head;
    do {
        count++;
        current = current->next;
    } while (current != stack->head);

    return count;
}

int is_sorted(t_stack *list) {
    if (list == NULL || list->head == NULL || list->head->next == NULL) {
        // Empty list or single element is considered sorted
        return 1;
    }

    t_node *current = list->head;
    t_node *prev = current;
    current = current->next;

    do {
        if (prev->data > current->data) {
            // Not sorted
            return 0;
        }

        prev = current;
        current = current->next;
    } while (current != list->head); // Loop until we reach the head again

    // Reached the end (head) without finding any unsorted elements
    return 1;
}