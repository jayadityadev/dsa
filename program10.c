#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *lchild;
	int data;
	struct node *rchild;
};
typedef struct node* NODE;

NODE root = NULL;

NODE create_node() {
	NODE ptr;
	ptr = (NODE)malloc(sizeof(struct node));
	if (ptr == NULL) {
		printf("Memory allocation failed!\n");
		exit(0);
	}
	printf("Enter data: ");
	scanf("%d", &ptr->data);
	ptr->rchild = ptr->lchild = NULL;
	return ptr;
}

NODE create_bst(NODE root) {
	NODE ptr, temp, p;
	ptr = create_node();
	if (root == NULL) {
		root = ptr;
		return root;
	}
	p = NULL;
	temp = root;
	while (temp != NULL) {
		p = temp;
		if (ptr->data == temp->data) {
			printf("Duplicate items are not allowed.\n");
			free(ptr);
			return root;
		}
		if (ptr->data < temp->data)
			temp = temp->lchild;
		else
			temp = temp->rchild;
	}
	if (ptr->data < p->data)
		p->lchild = ptr;
	else
		p->rchild = ptr;
	return root;
}

void inorder(NODE rt) {
	if (rt != NULL) {
		inorder(rt->lchild);
		printf("%d ", rt->data);
		inorder(rt->rchild);
	}
}

void preorder(NODE root) {
	if (root != NULL) {
		printf("%d ", root->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}

void postorder(NODE root) {
	if (root != NULL) {
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%d ", root->data);
	}
}

void traverse(NODE root) {
	if (root == NULL)
		printf("BST is empty!\n");
	else {
		printf("\nPreorder traversal: "); preorder(root);
		printf("\nPostorder traversal: "); postorder(root);
		printf("\nInorder traversal: "); inorder(root);
	}
	printf("\n");
}

void search_bst(NODE root) {
	int key, flag = 0;
	printf("Enter the element to search: ");
	scanf("%d", &key);
	if (root == NULL) {
		printf("BST is empty!\n");
		return;
	} else {
		NODE temp = root;
		while (temp != NULL) {
			if (key == temp->data) {
				printf("Element is present in the BST.\n");
				flag = 1;
				break;
			} else if (key < temp->data)
				temp = temp->lchild;
			else
				temp = temp->rchild;
		}
	}
	if (flag == 0)
		printf("Element not found in the BST!\n");
}

void main() {
	int choice;
	printf("\nOperations on Binary Search Tree:\n");
	printf("1. Create BST\n2. Traverse BST\n3. Search in BST\n4. Exit\n");
	while (1) {
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1: root = create_bst(root); break;
			case 2: traverse(root); break;
			case 3: search_bst(root); break;
			case 4: printf("\nExiting...\n"); return;
			default: printf("Invalid choice!\n");
		}
	}
}
