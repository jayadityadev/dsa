#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

struct record {
    int empno;
    int flag;
    char name[10];
} emp[TABLE_SIZE];

int hash(int empno) {
    return empno % TABLE_SIZE;
}

void initialize_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        emp[i].flag = 0;
    }
}

void insert_record(int empno, char *empName) {
    int hashIndex = hash(empno);
    if (emp[hashIndex].flag == 0) {
        emp[hashIndex].empno = empno;
        emp[hashIndex].flag = 1;
        strcpy(emp[hashIndex].name, empName);
        printf("\nRecord with empno %d is mapped to address: %d\n", empno, hashIndex);
    } else {
        printf("\nCollision occurred for empno %d. Resolved using linear probing.\n", empno);
        int probeIndex;
        for (probeIndex = hashIndex + 1; probeIndex < TABLE_SIZE; probeIndex++) {
            if (emp[probeIndex].flag == 0) {
                emp[probeIndex].empno = empno;
                emp[probeIndex].flag = 1;
                strcpy(emp[probeIndex].name, empName);
                printf("\nRecord with empno %d is mapped to address: %d\n", empno, probeIndex);
                break;
            }
        }
        if (probeIndex >= TABLE_SIZE) {
            printf("Hash Table is full!\n");
        }
    }
}

void display_table() {
    printf("\nThe Hash Table contents are:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (emp[i].flag == 1) {
            printf("%d\t%d\t%s\n", i, emp[i].empno, emp[i].name);
        } else {
            printf("%d\t#\t#\n", i);
        }
    }
}

int main() {
    int numRecords, empno, numRecordsToRead;
    char empName[10];
    FILE *inputFile;

    printf("Enter number of records to read from file: ");
    scanf("%d", &numRecordsToRead);

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fscanf(inputFile, "%d", &numRecords);
    if (numRecordsToRead > numRecords) {
        printf("\nFile contains only %d records.\n", numRecords);
        fclose(inputFile);
        return 1;
    }

    initialize_table();

    for (int i = 0; i < numRecordsToRead; i++) {
        fscanf(inputFile, "%d%s", &empno, empName);
        insert_record(empno, empName);
    }

    fclose(inputFile);
    display_table();

    return 0;
}