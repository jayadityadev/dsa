#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record {
	int empno, flag;
	char name[10];
} emp[100];

int hash(int empno) {
	return empno % 100;
}

void main() {
	int numRecords, index, empno, hashIndex, numRecordsToRead, probeIndex, i;
	char empName[10];
	FILE *inputFile;
	printf("Enter number of records to read from file: ");
	scanf("%d", &numRecordsToRead);
	inputFile = fopen("input.txt", "r");
	fscanf(inputFile, "%d", &numRecords);
	if (numRecordsToRead <= numRecords) {
		for (index = 0; index < 100; index++)
			emp[index].flag = 0;
		for (i = 0; i < numRecordsToRead; i++) {
			fscanf(inputFile, "%d%s", &empno, empName);
			hashIndex = hash(empno);
			if (emp[hashIndex].flag == 0) {
				printf("\nRecord: %d is mapped to address: %d\n", i, hashIndex);
				emp[hashIndex].empno = empno;
				emp[hashIndex].flag = 1;
				strcpy(emp[hashIndex].name, empName);
			} else {
				printf("\nCollision occurred for record: %d. Resolved using linear probing.\n", i);
				for (probeIndex = hashIndex + 1; probeIndex < 100; probeIndex++) {
					if (emp[probeIndex].flag == 0) {
						printf("\nRecord: %d is at address: %d\n", i, probeIndex);
						strcpy(emp[probeIndex].name, empName);
						emp[probeIndex].empno = empno;
						emp[probeIndex].flag = 1;
						break;
					}
				}
				if (probeIndex >= 100) {
					printf("Hash Table is full!\n");
				}
			}
		}
		fclose(inputFile);
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
