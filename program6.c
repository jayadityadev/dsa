#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#define MAX 5

int front = 0, rear = -1, count = 0;
char cq[MAX];

void insert(), delete(), display();

void main() {
	int choice;
	while (1) {
		printf("\nIMPLEMENTATION OF CIRCULAR QUEUE\n");
		printf("Menu -\n");
		printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		__fpurge(stdin);
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1: insert(); break;
			case 2: delete(); break;
			case 3: display(); break;
			case 4: exit(0);
			default: printf("Invalid input!\n");
		}
	}
}

void insert() {
	char item;
	if (count == MAX)
		printf("Circular queue is full\n");
	else {
		printf("Enter the element to be inserted: ");
		__fpurge(stdin);
		scanf("%c", &item);
		rear = (rear + 1) % MAX;
		cq[rear] = item;
		count++;
	}
}

void delete() {
	char item;
	if (count == 0)
		printf("Circular queue is empty\n");
	else {
		item = cq[front];
		front = (front + 1) % MAX;
		count--;
		printf("The deleted element is: %c\n", item);
	}
}

void display() {
	if (count == 0) {
		printf("Circular queue is empty\n");
	} else {
		printf("Contents of the circular queue are:\n");
		int j = front;
		for (int i = 1; i <= count; i++) {
			printf("%c\t", cq[j]);
			j = (j + 1) % MAX;
		}
		printf("\n");
	}
}
