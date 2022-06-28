// 2016054011_±èÁö¿¬_508 

#include <stdio.h>
 
int main()
{
   int array[30000], m, n, c, d, position, swap;
 
   // printf("Enter number of elements\n");
   scanf("%d", &n);
   
   // printf("Enter how many steps to take: \n");
   scanf("%d", &m);
 
   //printf("Input: \n", n);
 
    for ( c = 0 ; c < n ; c++ ){
      scanf("%d", &array[c]);
 	}
   
   	for ( c = 0 ; c < m ; c++ ){
      position = c;
 
      	for ( d = c + 1 ; d < n ; d++ )
      	{
         if ( array[position] > array[d] )
            position = d;
      	}
      	if ( position != c )
      	{	
         swap = array[c];
         array[c] = array[position];
         array[position] = swap;
      	}
   }
 
   // printf("Output: ");
 
   for ( c = 0 ; c < n ; c++ )
      printf("%d\n", array[c]);
 
   return 0;
}
