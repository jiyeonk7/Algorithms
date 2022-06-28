#include <stdio.h>


void countingSort(int C[], int A[],int M, int N) {
    
    for (int i=0; i<=M; i++){
        C[i] = 0;
    }
    //initialize the C array
    
    for (int j=0; j<N; j++){
        C[A[j]] = C[A[j]] + 1;
    }
    
    //C[i] contains the number of elements equal to i
    
    for(int i=1; i<=M; i++){
        C[i] = C[i] + C[i-1];
    }
    
    //C[i] contains the number of elements less than or equal to i
}

int main()  {
    
    int N, M, K;
    int count;
    
    //printf("Number of input keys N M K: ");
    scanf("%d %d %d", &N, &M, &K);
    
    
    int A[K], B[K], C[M];
    int Keys[N];
    
    for(int i = 0 ; i < K; i++){
        //printf("A[i] and B[i]: ");
        scanf("%d %d", &A[i] ,&B[i]);
    }
    
    for(int i = 0 ; i < N ; i++){
        scanf("%d", &Keys[i]);
    }
    
    countingSort(C, Keys,M, N);
    
    for(int i=0; i<K; i++){
		if(A[i] != 0){
			count = C[B[i]] - C[A[i]-1];
		}
		
		else {
			count = C[B[i]];
		}
		printf("%d\n", count);
	}
    
    
    return 0;
}
