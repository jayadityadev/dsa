#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int top = -1;
int stack[MAX];

void push(int element) {
    if (top == MAX - 1) {
        printf("Cannot push element to stack - Stack Overflow\n\n");
        return;
    }
    stack[++top] = element;
    printf("%d pushed to stack successfully!\n\n", element);
}

int pop() {
    if (top == -1) {
        printf("Cannot pop element from stack - Stack Underflow\n\n");
        return -1; // Return -1 to indicate underflow
    }
    return stack[top--];
}

void display() {
    if (top == -1) {
        printf("Stack is empty - nothing to display\n\n");
        return;
    }
    printf("Stack elements are: ");
    for (int i = top; i >= 0; i--) {
        printf("%d\t", stack[i]);
    }
    printf("\n\n");
}

void check_overflow_underflow() {
    if (top == -1) {
        printf("Stack is empty - Underflow condition\n\n");
    } else if (top == MAX - 1) {
        printf("Stack is full - Overflow condition\n\n");
    } else {
        printf("Stack is neither full nor empty. Current size: %d\n\n", top + 1);
    }
}

void palindrome() {
    if (top == -1) {
        printf("Stack is empty\n\n");
        return;
    }
    int isPalindrome = 1;
    for (int i = 0; i <= top / 2; i++) {
        if (stack[i] != stack[top - i]) {
            isPalindrome = 0;
            break;
        }
    }
    if (isPalindrome) {
        printf("Stack is a palindrome\n\n");
    } else {
        printf("Stack is not a palindrome\n\n");
    }
}

void main() {
    int choice, element, popped;
    while (1) {
        printf("Available stack operations:\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Check for overflow/underflow\n5. Check for palindrome\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                popped = pop();
                if (popped != -1) {
                    printf("%d popped from stack successfully\n\n", popped);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                check_overflow_underflow();
                break;
            case 5:
                palindrome();
                break;
            case 6:
                printf("Exiting....\n");
                exit(0);
            default:
                printf("Invalid operation. Please try again.\n\n");
        }
    }
}
