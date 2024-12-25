#include<stdio.h>
#include<stdlib.h>

struct node {
	char usn[12], name[20], branch[10], phno[15];
	int sem;
	struct node *link;
};
typedef struct node* NODE;

NODE start = NULL;
NODE start1 = NULL;

NODE create_node() {
	NODE ptr;
	ptr = (NODE)malloc(sizeof(struct node));
	if (ptr == NULL) {
		printf("Insufficient memory!\n\n");
		exit(0);
	}
	printf("\nEnter student data (USN, NAME, BRANCH, PHNO, SEM):\n");
	scanf("%s%s%s%s%d", ptr -> usn, ptr -> name, ptr -> branch, ptr -> phno, &ptr -> sem);
	ptr -> link = NULL;
	return ptr;
}

NODE insert_front(NODE start) {
	NODE ptr = create_node();
	if (start == NULL)
		start = ptr;
	else {
		ptr -> link = start;
		start = ptr;
	}
	return start;
}

NODE insert_end(NODE start) {
	NODE ptr, temp;
	ptr = create_node();
	if (start == NULL) {
		start = ptr;
	} else {
		temp = start;
		while (temp -> link != NULL) {
			temp = temp -> link;
		}
		temp -> link = ptr;
	}
	return start;
}

NODE delete_front(NODE start) {
	NODE temp;
	if (start == NULL)
		printf("\nList Empty!\n\n");
	else {
		temp = start;
		start = start -> link;
		printf("\nDeleted node is: ");
		printf("| %s | %s | %s | %s | %d |\n", temp -> usn, temp -> name, temp -> branch, temp -> phno, temp -> sem);
		free(temp);
	}
	return start;
}

NODE delete_end(NODE start) {
	NODE p, temp;
	if (start == NULL) {
		printf("\nList Empty\n\n"); return;
	}
	temp = start;
	if (temp -> link == NULL)
		start = NULL;
	else {
		temp = start;
		while (temp -> link != NULL) {
			p = temp;
			temp = temp -> link;
		}
		p -> link = NULL;
	}
	printf("\nDeleted node is: ");
	printf("| %s | %s | %s | %s | %d |\n", temp -> usn, temp -> name, temp -> branch, temp -> phno, temp -> sem);
	free(temp);
	return start;
}

void display(NODE start) {
	NODE temp;
	if (start == NULL)
		printf("\nList Empty\n\n");
	else {
		int count = 0;
		temp = start;
		printf("\nSingly Linked List:\n");
		while (temp != NULL) {
			printf("| %s | %s | %s | %s | %d |\n", temp -> usn, temp -> name, temp -> branch, temp -> phno, temp -> sem);
			temp = temp -> link;
			count++;
		}
		printf("\nNumber of nodes in the SLL: %d\n", count);
	}
}

NODE list_stack(NODE start1) {
	int choice;
	printf("\nOperations on List as Stack:\n");
	while (1) {
		printf("1.Push\n2.Pop\n3.Display\n4.Back to Main Menu\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1: start1 = insert_front(start1); break;
			case 2: start1 = delete_front(start1); break;
			case 3: display(start1); break;
			case 4: return start1;
			default: printf("Invalid option!\n");
		}
	}
}

void main() {
	int choice, n;
	while (1) {
		printf("\nSLL Operations -\n");
		printf("1. List creation using insert front\n");
		printf("2. Display and count\n");
		printf("3. Insert at end\n");
		printf("4. Delete at end\n");
		printf("5. List as Stack\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1: printf("Enter number of student data to enter: ");
				scanf("%d", &n);
				for (int i = 1; i <= n; i++) {
					printf("Enter data for student %d\n", i);
					start = insert_front(start);
				}
				break;
			case 2: display(start); break;
			case 3: start = insert_end(start); break;
			case 4: start = delete_end(start); break;
			case 5: start1 = list_stack(start1); break;
			case 6: exit(0);
			default: printf("Invalid option!\n");
		}
	}
}

