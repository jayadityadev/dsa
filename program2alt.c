#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For strcspn

void read(char str[], char pat[], char rep_pat[]);
void replace(char str[], char pat[], char rep_pat[], char new_str[]);

int main() {
    char str[100], pat[20], rep_pat[20], new_str[100];
    read(str, pat, rep_pat);
    replace(str, pat, rep_pat, new_str);
    return 0;
}

void read(char str[], char pat[], char rep_pat[]) {
    printf("Enter the string: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';  // Remove trailing newline

    printf("Enter the pattern to be replaced: ");
    fgets(pat, 20, stdin);
    pat[strcspn(pat, "\n")] = '\0';  // Remove trailing newline

    printf("Enter the replacement string: ");
    fgets(rep_pat, 20, stdin);
    rep_pat[strcspn(rep_pat, "\n")] = '\0';  // Remove trailing newline
}

void replace(char str[], char pat[], char rep_pat[], char new_str[]) {
    int i = 0, j = 0, k, rep_ind, flag = 0, mflag = 0, n = 0;

    while (str[i] != '\0') {
        j = 0, k = i, rep_ind = 0;

        // Check if the pattern matches at the current position
        while (str[k] == pat[j] && pat[j] != '\0') {
            k++; 
            j++;
        }

        if (pat[j] == '\0') { // Pattern matched
            flag = 1;
            mflag = 1;
            // Copy the replacement string to the new string
            while (rep_pat[rep_ind] != '\0') {
                new_str[n++] = rep_pat[rep_ind++];
            }
        } else {
            flag = 0;
        }

        if (flag == 1) { // Skip the matched pattern
            i = k;
        } else { // Copy the current character from original string
            new_str[n++] = str[i++];
        }
    }

    if (mflag != 1) {
        printf("Pattern not found in the string!\n");
    } else {
        new_str[n] = '\0'; // Null-terminate the new string
        printf("New string: %s\n", new_str);
    }
}
