#include<stdio.h>
#include<stdlib.h>
# define MAX 5


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
		return;
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
		prinf("Stack is a palindrome\n\n");
	else
		printf("Stack is not a palindrome\n\n");
	}
}

void main() {
	int choice;
	while (1) {
		printf("Available stack operations:\n");
		printf("1. Push\n2. Pop\n3. display\n4. Check for overflow/underflown\n5. Check for palindrome\n6. Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1: int element;
				printf("Enter element to push: ");
				push(element);
				break;
			case 2: int popped = pop();
				printf("%d popped from stack successfully", popped);
				break;
			case 3: printf("The stack elements are: ");
				display();
				break;
			case 4: overflow_underflow();
				break;
			// case 5: palindrome_check();
			// 	break;
			case 6: printf("Exiting....\n");
				exit(0);
			default: printf("Invalid operation.");
		}
	}
}
