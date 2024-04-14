#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;

	if (stack == NULL || stack->head == NULL)
		return ;
	current = stack->head;
	while (current->next != stack->head)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(current); // Free the last node
	stack->head = NULL;
	free(stack); // Free the stack itself
}

// Function to create a new Node
t_node	*create_node(long data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

// Function to push a new node onto the stack
void push(t_stack *stack, long data) {
    t_node *new_node = create_node(data);
    if (new_node == NULL) {
        // Handle memory allocation failure
        return;
    }

    if (stack->head == NULL) {
        // If the stack is empty, this new node is both the head and forms a circular reference to itself
        stack->head = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
    } else {
        // Insert the new node before the current head, making it the new head
        // This is because we want to maintain the order such that the last given number becomes the top of the stack
        new_node->prev = stack->head->prev; // New node's prev points to what was the last node
        new_node->next = stack->head;       // New node's next points to the current head
        
        stack->head->prev->next = new_node; // The old last node's next points to the new node
        stack->head->prev = new_node;       // The current head's prev points to the new node
        stack->head = new_node;             // Update the head to point to the new node
    }
}

t_stack	*array_to_stack_desc(long arr[], int size)
{
    t_stack	*stack;
    int		i;

    // Allocate memory for the stack
    stack = (t_stack *)malloc(sizeof(t_stack));
    if (stack == NULL)
        return (NULL);  // Return NULL if memory allocation fails

    stack->head = NULL;
    
    // Start from the last element of the array and move to the first element
    for (i = size - 1; i >= 0; i--)
    {
        push(stack, arr[i]);  // Push elements to the stack
    }
    
    return stack;
}
