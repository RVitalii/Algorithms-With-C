#include <stdio.h>
#define MAXLINE 1000
#define MAXPATTERN 101

int getLine(char line[], int max);
int strindex(char source[], char searchfor[]);

int main()
{
    char pattern[MAXPATTERN], line[MAXLINE];
    int pos;

    printf("PATTERN:\n");
    scanf("%100s", pattern);
    printf("START\n");
    while (getLine(line, MAXLINE) != 0) {
	pos = strindex(line, pattern);
        if (pos >= 0) {
            printf("RIGHT-MOST PATTERN FOUND AT: %d\n", pos);
	} else {
	    printf("NOT FOUND\n");
	}
    }
    printf("END\n");
    return 0;
}

int getLine(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int strindex(char s[], char t[])
{
    int i, j, k, pos = -1;

    for (i = 0; s[i] != '\0'; i++) {
       k = 0;
       j = i;
       while (t[k] != '\0' && s[j] == t[k]) {
	       j++;
	       k++;
       }
       if(k > 0 && t[k] == '\0')
           pos = i;
    }
    return pos;
}
