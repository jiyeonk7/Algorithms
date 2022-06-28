// 2016054011_±èÁö¿¬_508 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(x, y) ((x < y)? x: y);

#define MAX_SIZE 501

char* LCS(char* str1, char* str2);

int main() {
    char str1[MAX_SIZE], str2[MAX_SIZE];

    scanf("%s %s", str1, str2);

    if (strlen(str1) < strlen(str2))
        printf("%s", LCS(str2, str1));
    else
        printf("%s", LCS(str1, str2));

    return 0;
}

char* LCS(char* str1, char* str2) {
    char* retStr;
    int **table, **arrow_table;
    int len1 = strlen(str1), len2 = strlen(str2);
    int left, top;
    int i, j, index;

    table = (int**)malloc(sizeof(int*) * (len2 + 1));
    arrow_table = (int**)malloc(sizeof(int*) * (len2 + 1));
    for (i = 0; i <= len2; i++) {
        table[i] = (int*)malloc(sizeof(int) * 2);
        arrow_table[i] = (int*)malloc(sizeof(int) * (len1 + 1));
    }

    for (i = 0; i <= len2; i++)
        table[i][0] = 0;

    for (i = 1; i <= len1; i++) {
        table[0][i%2] = 0;
        for (j = 1; j <= len2; j++) {
            if (str2[j-1] == str1[i-1]) {
                table[j][i%2] = table[j-1][(i-1)%2] + 1;
                arrow_table[j][i] = 1;
            }

            else {
                left = table[j][(i-1)%2];
                top = table[j-1][i%2];

                if(left > top) {
                    table[j][i%2] = left;
                    arrow_table[j][i] = 0;
                }

                else {
                    table[j][i%2] = top;
                    arrow_table[j][i] = 2;
                }
            }
        }
    }

    index = table[len2][len1%2];
    retStr = (char*)malloc(sizeof(char) * (index + 1));
    retStr[index--] = '\0';

    i = len2;
    j = len1;
    while (i > 0 && j > 0) {
        if (arrow_table[i][j] == 1) {
            retStr[index--] = str2[i-1];
            i--; j--;
        }
        else if (arrow_table[i][j] == 0) {
            j--;
        }
        else {
            i--;
        }
    }

    return retStr;
}
