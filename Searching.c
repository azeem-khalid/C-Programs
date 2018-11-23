#include<stdio.h>
#include<conio.h>
#include<string.h>
main()
{
	FILE *fp;
	char A[250],name[100];
	fp = fopen("program.txt","r");
           printf("Enter the name you want to search : ");
           gets(A);
	while(1)
	{
		//fgets(A,250,fp);
        fscanf(fp,"%s",name);
		if(strcmp(A,name)==0)
		{
			printf("Found");
			break;
		}
	}
	fclose(fp);
}

