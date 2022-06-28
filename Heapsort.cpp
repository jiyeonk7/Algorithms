//2016054011_김지연_508 

#include<stdio.h>
#include <stdlib.h>

void  max_heapify(int arr[], int i, int heapsize);

void max_heap(int arr[], int heapsize);

void heap_sort(int arr[], int heapsize);

int main()
{
    int i, r, heapsize,N,k;
    int arr[100000];
    scanf("%d %d", &N, &k);
    for (i = 0; i < N; i++)
        scanf("%d",&arr[i]);//숫자 받 
    heapsize = N - 1;
    heap_sort(arr, heapsize);
    for (i = N-1; i >= k; i--)
        printf("%d ", arr[i]);
    printf("\n");
    for (i=k-1; i>=0; i--)
       printf("%d ", arr[i]);
    return 0;
} 

void  max_heapify(int arr[], int i, int heapsize)
{
    int tmp, big;
    int l = (2 * i) + 1;
    int r = (2 * i) + 2;
    if ((l <= heapsize) && (arr[l] > arr[i]))
         big = l;
    else
         big = i;
    if ((r <= heapsize) && (arr[r] > arr[big]))
         big = r ;
    if (big != i) 
    {
         tmp = arr[i];
         arr[i] = arr[big];
         arr[big] = tmp;
         max_heapify(arr, big, heapsize);
    }
 
}

void max_heap(int arr[], int heapsize)
{
    int i;
    for (i = heapsize/2; i >= 0; i--)
    {
         max_heapify(arr, i, heapsize);
    }
 
}

void heap_sort(int arr[], int heapsize)
{
    int i, tmp;
    max_heap(arr, heapsize);
    for (i = heapsize; i > 0; i--) 
    {
        tmp = arr[i];
        arr[i] = arr[0];
        arr[0] = tmp;
        heapsize--;
        max_heapify(arr, 0, heapsize);
    }
}
