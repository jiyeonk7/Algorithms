//2016054011_±èÁö¿¬_508 

#include <stdio.h>
#include <stdlib.h>

void Rodcutting(int N, int *p);

int main() {
    int N;  //  means the length of Rod
    int* p; //  means the value when the length of Rod is index
    int i;

    scanf("%d", &N);
    p = (int*)malloc(sizeof(int) * (N + 1));
    p[0] = 0;
    for (i = 1; i <= N; i++)
        scanf("%d", &p[i]);

    Rodcutting(N, p);

    free(p);

    return 0;
}

void Rodcutting(int N, int *p) {
    int* r = (int*)malloc(sizeof(int) * (N + 1));
    int* s = (int*)malloc(sizeof(int) * (N + 1));
    int max, index;
    int i, j;

    r[0] = 0;
    for (i = 1; i <= N; i++) {
        max = -1;
        for (j = 1; j <= i; j++) {
            if (max < p[j] + r[i - j]) {
                max = p[j] + r[i - j];
                s[i] = j;
            }
        }
        r[i] = max;
    }

    max = -1;
    for (i = 0; i <= N; i++) {
        if (max < r[i]) {
            max = r[i];
            index = i;
        }
    }

    printf("%d\n", r[index]);
    for (i = index; i > 0; ) {
        printf("%d ", s[i]);
        i = i - s[i];
    }

    free(r);
    free(s);
}
