#include<stdio.h>
#include<stdlib.h>
main()
{
	int size , i ;
	int *ptr ;
	printf("\n\nEnter the size of an array: ");
	scanf("%d",&size);
	ptr=(int*)malloc(sizeof(int));
	printf("\n\nEnter the elements of an array\n");
	for(i=0;i<size;i++)
	{
		scanf("%d",&ptr[i]);
	}
	for(i=0;i<size;i++)
	{
		printf("\nptr[%d] = %d \n",i,ptr[i]);
	}
}
