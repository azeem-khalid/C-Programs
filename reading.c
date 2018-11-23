#include<stdio.h>
#include<conio.h>
#include<string.h>
main()       {
	FILE *fp;
	char ch;
	fp=fopen("program.txt","r");
	while (1) {
        ch=fgetc(fp);
		if(ch==EOF)
		{
			break;
			}
		else 
		printf("%c",ch);
		}
	printf("\n");
	fclose (fp);
	getch();
}

