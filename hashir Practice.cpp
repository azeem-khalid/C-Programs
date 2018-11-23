#include<stdio.h>
#include<string.h>
int main()
{
		struct stud
	{
		char name[100];
		char roll_num[100];
	};
	
	struct student
	{
		int maths;
		int urdu;
		int eng;
		int tot;
		float percentage;
		struct stud x;
	};
	char search[100];
	
	FILE *ptr;
	ptr=fopen("Docs.txt","w");
	struct student S[100];
	int i,j;
	int sum=0;
	for(int i=0;i<2;i++)
	{
		printf("\n\nEnter Student's info:-\n\n");
		printf("Enter Marks of Maths\n");
		scanf("%d",&S[i].maths);
		printf("Enter Marks of Urdu\n");
		scanf("%d",&S[i].urdu);
		printf("Enter Marks of English\n");
		scanf("%d",&S[i].eng);
		S[i].tot=(S[i].urdu)+(S[i].maths)+(S[i].eng);
		
		printf("Enter Name\n");
		scanf("%s",S[i].x.name);
		printf("Enter Roll num\n");
		scoanf("%s",S[i].x.roll_num);
		S[i].percentage=(S[i].tot/300.0)*100;
		
		printf("\n enter roll num of student: ");
        scanf("%s",search);

    for(int k=0;k<1;k++)
    {
    	if(strcmp(S[k].x.roll_num,search)==0)
    	{
   
		printf("\nName: %s",S[k].x.name);
	    printf("\nRoll num: %s",S[k].x.roll_num);
	    printf("\nMarks In Urdu: %d",S[k].urdu);
	    printf("\nMarks In English: %d",S[k].eng);
	    printf("\nMarks In Maths: %d",S[k].maths);
	    printf("\nPERCENTAGE: %f",S[k].percentage);
    
		}
		else
		printf("No Record Found\n");
	}
	}

	for(int k=0;k<2;k++)
	{
		
		fprintf(ptr,"\nName: %s",S[k].x.name);
	    fprintf(ptr,"\nRoll num: %s",S[k].x.roll_num);
	    fprintf(ptr,"\nMarks In Urdu: %d",S[k].urdu);
	    fprintf(ptr,"\nMarks In English: %d",S[k].eng);
	    fprintf(ptr,"\nMarks In Maths: %d",S[k].maths);
	    fprintf(ptr,"\nPERCENTAGE: %f",S[k].percentage);
		
	}	
}
