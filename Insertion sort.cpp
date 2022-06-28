// 2016054011_±èÁö¿¬_508 

#include <stdio.h>
#include <time.h>

int main()
{
	int N[30000];
	int key, i, j, num;
	
	//printf("Enter the number of elements: ");
	scanf("%d",&num);
	
	//printf ("Input: \n");
	
	for(j=0; j<num; j++){
		scanf("%d", &N[j]);
	}
	
	for (j=1; j<num; j++){
		key = N[j];
		i = j-1;
		
		while (i>=0 && N[i]<key){
			N[i+1] = N[i];
			i = i-1;
		}
		N[i+1] = key;
	}
	
	//printf("Output: \n");
	
	for (j=0; j<num; j++){
		printf("%d\n", N[j]);
	}
	return 0;
}
