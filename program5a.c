# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <math.h>
# define STACK_SIZE 50

int stack[STACK_SIZE];
int top = -1;

void push(int element) {
	stack[++top] = element;
	return;
}

int pop() {
	return stack[top--];
}

int eval(char s[]) {
	int temp, op1, op2, result;
	char symbol[1];
	for (int i = 0; i < strlen(s); i++) {
		if (isalnum(s[i])) {
			if (isdigit(s[i])) {
				symbol[0] = s[i];
				temp = atoi(symbol);
				push(temp);
			} else {
				printf("Enter a value of %c: ", s[i]);
				scanf("%d", &temp);
				push(temp);
			}
		} else {
			op2 = pop();
			op1 = pop();
			switch (s[i]) {
				case '^': result = pow(op1, op2); break;
				case '*': result = op1 * op2; break;
				case '/': if (op2 == 0) { printf("Cannot divide by zero!\n"); break; }
					  result = op1 / op2; break;
				case '%': if (op2 == 0) { printf("Cannot divide by zero!\n"); break; }
					  result = op1 % op2; break;
				case '+': result = op1 + op2; break;
				case '-': result = op1 - op2; break;
				default: printf("Invalid expression!\n"); exit(0);
			}
			push(result);
		}
	}
	result = pop();
	if (top != -1) {
		printf("Invalid expression!\n"); exit(0);
	}
	return result;
}

void main() {
	char s[50];
	printf("Evaluation of Postfix Expression\n");
	printf("Enter the postfix expression: ");
	gets(s);
	printf("\nThe result of the evaluation is: %d\n", eval(s));
	return;
}
