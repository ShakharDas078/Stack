#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

struct Stack {
    int data[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->data[++stack->top] = value;
        printf("%d pushed onto the stack.\n", value);
    } else {
        printf("Stack is full. Cannot push %d.\n", value);
    }
}

// Function to pop an element from the stack
void pop(struct Stack *stack) {
    if (stack->top >= 0) {
        printf("%d popped from the stack.\n", stack->data[stack->top--]);
    } else {
        printf("Stack is empty. Cannot pop.\n");
    }
}

// Function to check if the stack is empty
bool isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
bool isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to peek at the top element of the stack
int peek(struct Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top];
    } else {
        printf("Stack is empty. Cannot peek.\n");
        return -1; // Return a sentinel value to indicate an error
    }
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));

    pop(&stack);
    printf("Top element after pop: %d\n", peek(&stack));

    pop(&stack);
    pop(&stack);
    pop(&stack);

    return 0;
}

