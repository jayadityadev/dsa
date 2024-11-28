#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
	int cf, px, py, pz, flag;
	struct node *link;
};

typedef struct node* NODE;

NODE create_node() {
	NODE ptr = (NODE)malloc(sizeof(struct node));
	if (ptr == NULL) {
		printf("Insufficient memory!\n");
		exit(0);
	}
	return ptr;
}

NODE insert_end(int cf, int x, int y, int z, NODE head) {
	NODE ptr = create_node();
	ptr -> cf = cf;
	ptr -> px = x;
	ptr -> py = y;
	ptr -> pz = z;
	ptr -> flag = 0;
	if (head -> link == head) {
		head -> link = ptr;
		ptr -> link = head;
	} else {
		NODE temp = head -> link;
		while (temp -> link != head)
			temp = temp -> link;
		temp -> link = ptr;
		ptr -> link = head;
	}
	return head;
}

void display(NODE head) {
	if (head -> link == head)
		printf("\nEmpty polynomial.\n");
	else {
		NODE temp = head -> link;
		while (temp != head) {
			if (temp -> cf < 0)
				printf(" %dx^%dy^%dz^%d", temp->cf, temp->px, temp->py, temp->pz);
			else
				printf(" +%dx^%dy^%dz^%d", temp->cf, temp->px, temp->py, temp->pz);
			temp = temp -> link;
		}
	}
}

NODE add_polynomial(NODE h1, NODE h2, NODE h3) {
	NODE p1, p2;
	int cof;
	p1 = h1 -> link;
	while (p1 != h1) {
		p2 = h2 -> link;
		while (p2 != h2) {
			if (p1->px == p2->px && p1->py == p2->py && p1->pz == p2->pz)
				break;
			p2 = p2 -> link;
		}
		if (p2 != h2) {
			cof = p1->cf + p2->cf;
			p2 -> flag = 1;
			if (cof != 0)
				h3 = insert_end(cof, p1->px, p1->py, p1->pz, h3);
		} else
			h3 = insert_end(p1->cf, p1->px, p1->py, p1->pz, h3);
		p1 = p1 -> link;
	}
	p2 = h2 -> link;
	while (p2 != h2) {
		if (p2->flag == 0)
			h3 = insert_end(p2->cf, p2->px, p2->py, p2->pz, h3);
		p2 = p2 -> link;
	}
	return h3;
}

NODE read_polynomial(NODE head) {
	int i, cf, x, y, z;
	printf("Enter the coefficient and exponents (to stop, enter '-999'): ");
	for (i = 1;  ; i++) {
		printf("\nEnter the %d term:\n", i);
		printf("Coeff: "); scanf("%d", &cf);
		if (cf == -999) break;
		printf("pow(x): "); scanf("%d", &x);
		printf("pow(y): "); scanf("%d", &y);
		printf("pow(z): "); scanf("%d", &z);
		head = insert_end(cf, x, y, z, head);
	}
	return head;
}

void polysum() {
	NODE h1, h2, h3;
	h1 = create_node();
	h2 = create_node();
	h3 = create_node();
	h1 -> link = h1;
	h2 -> link = h2;
	h3 -> link = h3;
	printf("\n\nEnter the first polynomial:\n"); h1 = read_polynomial(h1);
        printf("\n\nEnter the second polynomial:\n"); h2 = read_polynomial(h2);
	h3 = add_polynomial(h1, h2, h3);
	printf("\nFirst polynomial: "); display(h1);
	printf("\nSecond polynomial: "); display(h2);
	printf("\nSum of the two polynomials: ");
	display(h3);
	printf("\n");
}

void eval() {
	NODE h, temp;
	int x, y, z, sum = 0;
	h = create_node();
	h -> link = h;
	printf("\nEnter the polynomial:\n");
	h = read_polynomial(h);
	printf("\nPolynomial: ");
	display(h);
	printf("\nEnter the values of variables x, y, z: ");
	scanf("%d%d%d", &x, &y, &z);
	temp = h -> link;
	while (temp != h) {
		sum += temp->cf * pow(x, temp->px) * pow(y, temp->py) * pow(z, temp->pz);
		temp = temp -> link;
	}
	printf("The total sum is: %d\n", sum);
}

void main() {
	int choice;
	while (1) {
		printf("\n1. Represent and Evaluate\n2. Add Two Polynomials\n3. Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1: eval(); break;
			case 2: polysum(); break;
			case 3: printf("Exiting...\n"); exit(0);
			default: printf("Invalid choice!\n");
		}
	}
}
