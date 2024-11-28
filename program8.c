#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *llink;
	int ssn;
	char name[20], dept[20], desgn[20], phno[12];
	float salary;
	struct node *rlink;
};

typedef struct node* NODE;

NODE start = NULL;
NODE create_node() {
	NODE ptr;
	ptr = (NODE)malloc(sizeof(struct node));
	if (ptr == NULL) {
		printf("Insufficient Memory!\n"); exit(0);
	}
	printf("\nEnter the employee data (SSN, Name, Department, Designation, PhoneNo, Salary):\n");
	scanf("%d %s %s %s %s %f", &ptr->ssn, ptr->name, ptr->dept, ptr->desgn, ptr->phno, &ptr->salary);
	ptr -> llink = NULL;
	ptr -> rlink = NULL;
	return ptr;
}

NODE insert_front(NODE start) {
	NODE ptr;
	ptr = create_node();
	if (start == NULL) start = ptr;
	else {
		ptr -> rlink = start;
		start -> llink = ptr;
		start = ptr;
	}
	return start;
}

NODE insert_end(NODE start) {
	NODE ptr, temp;
	ptr = create_node();
	if (start == NULL) start = ptr;
	else {
		temp = start;
		while (temp -> rlink != NULL) temp = temp -> rlink;
		temp -> rlink = ptr;
		ptr -> llink = temp;
	}
	return start;
}

NODE delete_front(NODE start) {
	NODE temp;
	if (start == NULL) printf("\nDouble linked list is empty!\n");
	else {
		temp = start;
		start = start -> rlink;
		if (start != NULL) start -> llink = NULL;
		printf("\nDeleted node is:\n");
		printf("%d, %s, %s, %s, %s, %.2f\n", temp -> ssn, temp -> name, temp -> dept, temp -> desgn, temp -> phno, temp -> salary);
		free(temp);
	}
	return start;
}

NODE delete_end(NODE start) {
	NODE temp, p;
	if (start == NULL) printf("\nDouble linked list is empty!\n");
	else {
		temp = start;
		if (temp -> rlink == NULL) start = NULL;
		else {
			while (temp -> rlink != NULL) temp = temp -> rlink;
			p = temp -> llink;
			p -> rlink = NULL;
		}
		printf("\nDeleted node is:\n");
		printf("%d, %s, %s, %s, %s, %.2f\n", temp -> ssn, temp -> name, temp -> dept, temp -> desgn, temp -> phno, temp -> salary);
                free(temp);
	}
	return start;
}

void display(NODE start) {
	NODE temp;
	int count = 0;
	if (start == NULL) { printf("\nDoubly linked list is empty!\n"); return; }
	temp = start;
	printf("\nThe nodes of the doubly linked list are:\n");
	while (temp != NULL) {
		printf("%d, %s, %s, %s, %s, %.2f <-> ", temp -> ssn, temp -> name, temp -> dept, temp -> desgn, temp -> phno, temp -> salary);
		temp = temp -> rlink;
		count++;
	}
	printf("NULL\n");
}

void dll_dequeue(NODE start) {
	printf("\nDequeue operations:\n");
	printf("\nInsertion at front:\n");
	start = insert_front(start);
	display(start);
	printf("\nInsertion at end:\n");
	start = insert_end(start);
	display(start);
	printf("\nDeletion at front:\n");
	start = delete_front(start);
	display(start);
	printf("\nDeletion at end:\n");
	start = delete_end(start);
	display(start);
}

void main() {
	int choice, n;
	NODE start = NULL;
 	printf("\nDouble linked list operations:\n");
	printf("\nMenu:\n1. Create DLL of N employee using Insert End\n2. Dispaly and Count\n3. Insert End\n4. Delete end\n5. Insert Front\n6. Delete Front\n7. DLL as Dequeue\n8. Exit\n");
	while (1) {
//		printf("\nMenu:\n1. Create DLL of N employee using Insert End\n2. Dispaly and Count\n3. Insert End\n4. Delete end\n5. Insert Front\n6. Delete Front\n7. DLL as Dequeue\n8. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				printf("Enter number of employees: ");
				scanf("%d", &n);
				for (int i = 1; i <= n; i++) {printf("Employee %d:\n", i); start = insert_end(start);}
				break;
			case 2:
				display(start); break;
			case 3:
				start = insert_end(start); break;
			case 4:
				start = delete_end(start); break;
			case 5:
				start = insert_front(start); break;
			case 6:
				start = delete_front(start); break;
			case 7:
				dll_dequeue(start); break;
			case 8:
				printf("\nExiting...\n"); exit(0);
			default:
				printf("Invalid choice!\n");
		}
	}
}
