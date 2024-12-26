#include<stdio.h>
#include<string.h>

// Enumeration data type for precedence of operators
typedef enum {
	lparen,
	rparen,
	plus,
	minus,
	prod,
	div,
	mod,
	pow,
	eos,
	operand
} precedence;

// In-stack and In-coming Priorities
int isp[] = {0, 19, 12, 12, 13, 13, 13, 14, 0};
int icp[] = {20, 19, 12, 12, 13, 13, 13, 15, 0};


char expression[50], symbol;
precedence stack[50];
int top = 0, n = 0;

precedence readtoken() {
	symbol = expression[n++];
	switch (symbol) {
		case '(': return lparen;
		case ')': return rparen;
		case '+': return plus;
		case '-': return minus;
		case '*': return prod;
		case '/': return div;
		case '%': return mod;
		case '^': return pow;
		case '\0': return eos;
		default: return operand;
	}
}

// Stack operations

void push(precedence item) {
	stack[++top] = item;
}

precedence pop() {
	return stack[top--];
}

void displaytoken(precedence token) {
	switch (token) {
		case plus: printf("+"); break;
		case minus: printf("-"); break;
		case prod: printf("*"); break;
		case div: printf("/"); break;
		case mod: printf("%%"); break;
		case pow: printf("^"); break;
	}
}

void infixToPostfix() {
	precedence currentToken, poppedToken;
	stack[0] = eos;
	currentToken = readtoken();
	while (currentToken != eos) {
		if (currentToken == operand) {
			printf("%c", symbol);
		} else if (currentToken == rparen) {
			while (stack[top] != lparen) {
				poppedToken = pop();
				displaytoken(poppedToken);
			}
			pop();
		} else {
			while (isp[stack[top]] >= icp[currentToken]) {
				poppedToken = pop();
				displaytoken(poppedToken);
			}
			push(currentToken);
		}
		currentToken = readtoken();
	}
	while ((currentToken = pop()) != eos) {
		displaytoken(currentToken);
	}
	printf("\n");
}

void main() {
	printf("Program to convert infix expression to postfix expression\n\n");
	printf("Enter infix expression: ");
	fgets(expression, sizeof(expression), stdin);
	expression[strcspn(expression, "\n")] = '\0';
	printf("Postfix expression: ");
	infixToPostfix();
}


