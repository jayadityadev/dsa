#include<stdio.h>

char str[100], pat[50], rep[50], ans[100];
int i, j, c, m, flag = 0;

void stringReplace() {
	i = j = c = m = 0;
	while (str[c] != '\0') {
		if (str[m] == pat[i]) {
			i++; m++;
			if (pat[i] == '\0') {
				flag = 1;
				for (int k = 0; rep[k] != '\0'; k++, j++) ans[j] = rep[k];
				i = 0; c = m;
			}
		} else {
			ans[j] = str[c];
			j++; c++; m = c; i = 0;
		}
	}
	ans [j] = '\0';
}

int main() {
	printf("Enter a string: "); gets(str);
	printf("Enter the patter to be replaced: "); gets(pat);
	printf("Enter the replacement string: "); gets(rep);
	stringReplace();
	if (flag)
		printf("The resultant string is: %s\n", ans);
	else
		printf("Pattern not found\n");
	return 0;
}
