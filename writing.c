#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
   char ch;
   int n;
   FILE *fptr;
   char name[100];
 do
 {
   if ((fptr=fopen("program.txt","a"))==NULL)   // OPENING THE FILE.
   {
       printf("Error! opening file");
       exit(1);         		// Program exits if file pointer returns NULL. 
   } 

   printf("Enter name : ");
     gets(name);
   //  fputs(name,fptr);
   fprintf(fptr,"%s\n",name);
   fclose(fptr);
   printf("Do you want to enter again : ");
   ch = getche();
}while(ch == 'Y' ||ch == 'y');
}

