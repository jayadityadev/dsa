#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record {
	int empno, flag;
	char name[10];
} emp[100];

int hash(int m) {
	return m % 100;
}

void main() {
	int m, k, eno, loc, n, j, i;
	char name[10];
	FILE *in;
	printf("Enter number of records to read from file: ");
	scanf("%d", &n);
	in = fopen("input.txt", "r");
	if (n <= 10) {
		for (k = 0; k < 100; k++)
			emp[k].flag = 0;
		for (i = 0; i < n; i++) {
			fscanf(in, "%d%s", &eno, name);
			loc = hash(eno);
			if (emp[loc].flag == 0) {
				printf("\nRecord: %d is mapped to address: %d\n", i, loc);
				emp[loc].empno = eno;
				emp[loc].flag = 1;
				strcpy(emp[loc].name, name);
			} else {
				printf("\nCollision occurred for record: %d. Resolved using linear probing.\n", i);
				for (j = loc + 1; j < 100; j++) {
					if (emp[j].flag == 0) {
						printf("\nRecord: %d is at address: %d\n", i, j);
						strcpy(emp[j].name, name);
						emp[j].empno = eno;
						emp[j].flag = 1;
						break;
					}
				}
				if (j >= 100) {
					printf("Hash Table is full!\n");
				}
			}
		}
		fclose(in);
		printf("\nThe Hash Table contents are:\n");
		for (i = 0; i < 100; i++) {
			if (emp[i].flag == 1)
				printf("%d\t%d\t%s\n", i, emp[i].empno, emp[i].name);
			else
				printf("#\t#\t#\t\n");
		}
	} else {
		printf("\nFile is containing only 10 records.\n");
	}
}
