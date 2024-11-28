#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

struct date {
	int day;
	int month;
	int year;
};

struct calendar {
	char week[7];
	struct date d;
	char activity[25];
};

typedef struct calendar* CALENDAR;
CALENDAR mycal;

void create(), read(), display();

void main() {
	create();
	read();
	display();
}

void create() {
	mycal = (CALENDAR)malloc(sizeof(struct calendar) * 7);
}

void read() {
	for (int i = 0; i < 7; i++) {
		printf("Enter the week activity details for day %d:\n", i+1);
		__fpurge(stdin);
		printf("Enter day name: ");
		scanf("%s", mycal[i].week);
		printf("Enter date (DD MM YYYY): ");
		scanf("%d%d%d", &mycal[i].d.day, &mycal[i].d.month, &mycal[i].d.year);
		printf("Enter day activity: ");
		scanf("%s", mycal[i].activity);
	}
}

void display() {
	printf("\nWeekly Activity Report:\n");
	for (int i = 0; i < 7; i++) {
		printf("Day Name: %s\n", mycal[i].week);
		printf("Date: %02d/%02d/%04d\n", mycal[i].d.day, mycal[i].d.month, mycal[i].d.year);
		printf("Activity: %s\n", mycal[i].activity);
	}
}
