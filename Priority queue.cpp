// 2016054011_±èÁö¿¬_508 

#include <stdio.h> 
#include <stdlib.h> 

#define minus_inf -32767 

int PARENT(int index){ return index/2; } 
int LCHILD(int index){ return index*2; } 
int RCHILD(int index){ return index*2+1; } 

void array_swap(int arr[], int a, int b) {
	int temp;
	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
} 

void Heapify(int arr[], int current, int length) {
	int left, right, largest;
	left=LCHILD(current);
	right=RCHILD(current);
	if((right<=length) && (arr[right]>arr[current]))
		largest = right; 
	else
		largest = current;
	if((left<=length) && (arr[left]>arr[largest]))
		largest = left;
	if(largest != current) {
		array_swap(arr, current, largest); 
		Heapify(arr, largest, length); 
	} 
} 

void PRINT(int arr[], int length) {
	int i=0;
	for(i=1; i<=length; i++) 
		printf("%d ", arr[i]); 
}

int EXTRACT_MAX(int arr[], int length) {
	if(length < 1)	
		return minus_inf;
	int max = arr[1];
	arr[1] = arr[length];
	length --;
	Heapify(arr, 1, length);
	return max;
} 

void INCREASE_KEY(int arr[], int index, int key) {
	int tmp=0;
	if(key < arr[index])	
		return;
	arr[index] = key;
	while(index>1 && arr[PARENT(index)]<arr[index]) { 
		tmp = arr[index];
		arr[index] = arr[index/2];
		arr[index/2] = tmp; 
		index = PARENT(index);
	}
} 

void INSERT(int arr[], int length, int key) {
	arr[length] = minus_inf;
	INCREASE_KEY(arr, length, key);
} 

int main(void) {
	int arr[100000];
	int ext[100000];
	int length=0, extlength=0; 
	
	int op, tmp, i;
	int index, num;
	int quit=0; 
	
	while(quit==0) {
		scanf("%d", &op);
		switch(op) {
			case 0:
				quit=1;	
				break;
			
			case 1:
				scanf("%d", &num);
				length++;
				arr[length] = num;
				INCREASE_KEY(arr, length, num);
				break;
			
			case 2:
				extlength++;
				ext[extlength] = arr[1];
				tmp = arr[1];
				arr[1] = arr[length];
				arr[length] = tmp;
				length--;
				Heapify(arr, 1, length);
				break;
			
			case 3:
				scanf("%d %d", &index, &num);
				arr[index] = num;
				if(index != 1 && arr[index] > arr[PARENT(index)])
					INCREASE_KEY(arr, index, num);
				else
					Heapify(arr, index, length);
				break;
				
			default:
				break;
			}
	}
	
	for(i=1; i<=extlength; i++)
		printf("%d ", ext[i]);
	
	printf("\n");
	
	for(i=1; i<=length; i++)
		printf("%d ", arr[i]);
		return 0;
}


