# include <stdio.h>

int tower(int n, char s, char t, char d) {
	if (n == 0) return 0;
	tower(n-1, s, d, t);
	printf("Move disk %d from %c to %c\n", n, s, d);
	tower(n-1, t, s, d);
	return 0;
}

void main() {
	char A, B, C;
	int n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	printf("Sequence of disk:\n");
	tower(n, 'A', 'B', 'C');
	printf("\n");
}
