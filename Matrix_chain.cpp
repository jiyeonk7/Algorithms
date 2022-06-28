//2016054011_±èÁö¿¬_508 

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void Matrixchain(int N, int* p);

void printMatrixchain(int** s, int start, int end);

int main() {
    int N;  
    int* p; 
    int i;

    scanf("%d", &N);
    p = (int*) malloc(sizeof(int) * (N+1));
    for (i = 0; i <= N; i++)
        scanf("%d", &p[i]);

    Matrixchain(N, p);

    free(p);

    return 0;
}

void Matrixchain(int N, int* p) {
    int **m, **s;
    int *result;
    int min;
    int i, j, k;

    m = (int**)malloc(sizeof(int*) * N);
    for (i = 0; i < N; i++) {
        m[i] = (int*)malloc(sizeof(int) * N);

        m[i][i] = 0;  
    }

    s = (int**)malloc(sizeof(int*) * (N-1));
    for (i = 0; i < N-1; i++) {
        s[i] = (int*)malloc(sizeof(int) * (N-1));
        s[i][i] = i;  
    }


    i = 0; j = 1;
    while (1) {
        if (j == N)
            break;

        result = (int*)malloc(sizeof(int) * (j - i));
        for (k = 0; k < j-i; k++) {
            result[k] = m[i][i + k] + m[i + k + 1][j] + p[i]*p[i+k+1]*p[j+1];
        }
        
        min = INT_MAX;
        for (k = 0; k < j-i; k++)
            if (min > result[k]) {
                min = result[k];
                s[i][j-1] = i + k;
            }
        m[i++][j++] = min;

        if (j == N) {
            j = j - i + 1;
            i = 0;
        }
        free(result);
    }

    printf("%d\n", m[0][N-1]);
    printMatrixchain(s, 0, N-1);
}

void printMatrixchain(int** s, int start, int end) {
    if (start == end)
        printf("%d ", start+1);
    else if (start + 1 == end) {
        printf("( ");
        printf("%d %d ", start+1, end+1);
        printf(") ");
    }
    else {
        printf("( ");
        printMatrixchain(s, start, s[start][end-1]);
        printMatrixchain(s, s[start][end-1]+1, end);
        printf(") ");
    }
}
