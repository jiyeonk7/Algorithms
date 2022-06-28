//2016054011_±èÁö¿¬_508

#include <stdio.h>

int partition(int a[], int l, int r) {
    int pivot, i, j, t;
    pivot = a[l];
    i = l; j = r+1;
    
    while(1) {
        
        do ++i; while( a[i] <= pivot && i <= r );
        do --j; while( a[j] > pivot );
        if( i >= j ) break;
        t = a[i]; a[i] = a[j]; a[j] = t;
    }
    t = a[l]; a[l] = a[j]; a[j] = t;
    return j;
}


void quickSort( int a[], int l, int r) {
    int j;
    
    if( l < r ) {

        j = partition( a, l, r);
        quickSort( a, l, j-1);
        quickSort( a, j+1, r);
    }
    
}

int main() {
    int N = 0, M = 0, count = 0;
    
    while (N < 1 || N > 100000 || M < 1 || M > 100000)
        scanf("%d %d", &N, &M);
    int A[N], B[M];
    
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    
    
    for (int i = 0; i < M; i++) {
        scanf("%d", &B[i]);
    }
    
    int i = 0, j = 0;
    
    quickSort(A, 0, N-1);
    quickSort(B, 0, M-1);
    
    while (i < N && j < M) {
        if (A[i] == B[j]) {
            count++;
            i++;
            j++;
        }
        else if (A[i] < B[j])
            i++;
        else
            j++;
    }
    
    printf("%d\n", count);
    
    return 0;
}
