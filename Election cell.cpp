#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<iostream>
void addcandi();
void addvoter();
void addvotertlc();
void addvotersp();
void addvoterdecs();
void display();	
void exit();
void addtlc();
void addsp();
void adddecs();
void distlc();
void dissp();
void disdecs();
void votingstatus();
void statustlc();
void statussp();
void statusdecs();	
void shashkay();
struct candi{
			char name[20];
			char section;
			char id[20];	
			char batch[20];
			};
struct candi s1;
struct candi2{
	int x;
};
struct candi2 s3;
struct voter{
			char name[30];
			char section;
			char id[20];
			char batch[20];
			char vote[20];
			};
struct voter s2;
char button;
main()
{
	static int x=0;
	if(x<1)
	{
		x++;
		shashkay();
	}
	else
	{
	char choice;
	system("cls");
	printf("\nEnter Choice : ");
	printf("\n\n1)Nominations in elections\n\n");
	printf("2)Voting in elections\n\n");
	printf("3)View the details of the candidates standing in the elections\n\n");
	printf("4)Voting Status\n\n");
	printf("5)Exit\n\n");
	printf("Enter your choice: ");
	fflush(stdin);
	scanf("%c",&choice);
	switch(choice)
	{
		case '1':
			addcandi();
			break;
		case '2':
			addvoter();
			break;
		case '3':
			display();
			break;
		case '4':
			votingstatus();
			break;
		case '5':
			exit();
			break;
		default:
			{
				system("cls");
				printf("\nWrong Choice\n");
				printf("\nEnter any key to continue....\n");
				button=getche();
				system("cls");
				main();
			}
	}
	}
}
void addcandi()
{
	static int x=0,y=0,z=0;
	char choice1;
	system("cls");
	fflush(stdin);
	printf("\n\nIn Which Deparment you want to nominate yourself ( Remember  only 5 persons can stand in elections on each society individually )\n");
	printf("\n1)TLC (The Literacy Club)\n\n");
	printf("2)Sportics\n\n");
	printf("3)DECS\n\n");
	printf("4)Home Screen\n\n");
	printf("5)Exit\n\n");
	printf("Enter your choice\n");
	scanf("%c",&choice1);
	switch(choice1)
	{
		case '1':
			x++;
			if(x<=5)
			{
				addtlc();
			}
			else
			{
			printf("\nNo place for Nominations");
			printf("\nPress any key to continue...\n");
			button=getche();
			system("cls");
			addcandi();
			}
			break;
			case '2':
			y++;
			if(y<=5)
			{
			addsp();
			}
			else
			{	
			printf("\nNo place for Nominations");
			printf("\nPress any key to continue...\n");
			button=getche();
			system("cls");
			addcandi();
			}
			break;
		case '3':
			z++;
			if(z<=5)
			{
			adddecs();
			}
			else
			{
				printf("\nNo place for Nominations");
				printf("\nPress any key to continue...\n");
				button=getche();
				system("cls");
				addcandi();
			}
			break;
		case '4':
			{
				system("cls");
				main();
				break;
			}
		case '5':
			exit();
			break;
		default:
			{
				system("cls");
				printf("\nWrong Choice\n");
				printf("\nEnter any key to continue....\n");
				button=getche();
				system("cls");
				addcandi();
			}
	}	
}
void addtlc()
{
	char ch1;
	system("cls");
	fflush(stdin);
	printf("\n\nNomination for TLC Department\n");
	printf("\nEnter your name: ");
	gets(s1.name );
	printf("\nEnter your section: ");
	s1.section=getche();
	printf("\n\nEnter your ID: ");
	gets(s1.id);
	printf("\nEnter your batch name: ");
	gets(s1.batch);
	printf("\nHave you recieved any warning from the university(Y/N): ");
	ch1=getche();
	if(ch1=='y' || ch1=='Y')
	{
		printf("\n\nYou cannot nominate yourself\n");
	}
	else
	{	
		FILE*ptr2;
		FILE*fp1;
		fp1=fopen("C:\\Users\\Admin\\Desktop\\Candidates For TLC.txt","a");
		fwrite(&s1,1,sizeof(s1),fp1);
		fclose(fp1);
		printf("\n\nYou have been succesfully nominated\n");
		printf("\nPress any key to continue...\n");
		button=getche();
		system("cls");
		addcandi();
	}
}
void addsp()
{
	char ch2;
	system("cls");
	fflush(stdin);
	printf("\n\nNomination for Sportics Department\n");
	printf("\nEnter your name: ");
	gets(s1.name );
	printf("\nEnter your section: ");
	s1.section=getche();
	printf("\n\nEnter your ID: ");
	gets(s1.id);
	printf("\nEnter your batch name: ");
	gets(s1.batch);
	printf("\nHave you recieved any warning from the university(Y/N): ");
	ch2=getche();
	if(ch2=='y' || ch2=='Y')
	{
		printf("\n\nYou cannot nominate yourself\n");
	}
	else
	{
		FILE*fp2;
		fp2=fopen("C:\\Users\\Admin\\Desktop\\Candidates For Sportics.txt","a");
		fwrite(&s1,1,sizeof(s1),fp2);
		fclose(fp2);
		printf("\n\nYou have been succesfully nominated\n");
		printf("\nPress any key to continue...\n");
		button=getche();
		system("cls");
		addcandi();
	}
}
void adddecs()
{
	char ch3;
	system("cls");
	fflush(stdin);
	printf("\n\nNomination for DECS Department\n");
	printf("\nEnter your name: ");
	gets(s1.name );
	printf("\nEnter your section: ");
	s1.section=getche();
	printf("\n\nEnter your ID: ");
	gets(s1.id);
	printf("\nEnter your batch name: ");
	gets(s1.batch);
	printf("\nHave you recieved any warning from the university(Y/N): ");
	ch3=getche();
	if(ch3=='y' || ch3=='Y')
	{
		printf("\n\nYou cannot nominate yourself\n");
	}
	else
	{
		FILE*fp3;
		fp3=fopen("C:\\Users\\Admin\\Desktop\\Candidates For DECS.txt","a");
		fwrite(&s1,1,sizeof(s1),fp3);
		fclose(fp3);
		printf("\n\nYou have been succesfully nominated\n");
		printf("\nPress any key to continue...\n");
		button=getche();
		system("cls");
		addcandi();
	}
}
void addvoter()
{
	char choice2;
	system("cls");
	fflush(stdin);
	printf("\n\nIn Which Deparment you want to vote\n");
	printf("\n1)TLC(The Literacy Club)\n\n");
	printf("2)Sportics\n\n");
	printf("3)DECS\n\n");
	printf("4)Home Screen\n\n");
	printf("5)Exit\n\n");
	printf("Enter your choice:\n");
	scanf("%c",&choice2);
	fflush(stdin);
	switch(choice2)
	{
		case '1':
			addvotertlc();
			break;
		case '2':
			addvotersp();
			break;
		case '3':
			addvoterdecs();
			break;
		case '4':
			{
				system("cls");
				main();
				break;
			}
		case '5':
			exit();
			break;
		default:
			{
				system("cls");
				printf("\nWrong Choice\n");
				printf("\nEnter any key to contiune....\n");
				button=getche();
				system("cls");
				addvoter();
			}
	}	
}
void addvotertlc()
{
	system("cls");
	int p=0,q;
	static int x=0,y=0,z=0,a=0,b=0;
	FILE*fp1;
	FILE*fp2;
	FILE*ptr1;
	FILE*ptr2;
	printf("\nVoting for TLC\n\nCandidates\n\n");
	fp1=fopen("C:\\Users\\Admin\\Desktop\\Candidates For TLC.txt","r");
	while (fread(&s1,sizeof(s1),1,fp1)!=0)
			{	
				p++;
				printf ("%d> Name> %s\n",p,s1.name);
			}
	fclose(fp1);
	fflush(stdin);
	printf("\n\nVOTING\n");
	printf("\nEnter your name: ");
	gets(s2.name );
	printf("\nEnter your section: ");
	s2.section=getche();
	printf("\n\nEnter your ID: ");
	gets(s2.id);
	printf("\nEnter your batch name: ");
	gets(s2.batch);
	printf("\nEnter the name of candidate you want to vote: ");
	gets(s2.vote);
	printf("\nEnter S.NO of candidate you want to vote: ");
	scanf("%d",&q);
	printf("\nYour vote has been casted.Thank you\n");
	ptr1=fopen("C:\\Users\\Admin\\Desktop\\Voting For TLC.txt","a");
	fwrite(&s2,1,sizeof(s2),ptr1);
	fclose(ptr1);
	if(q==1)
	{	
		x++;
		fp2=fopen("C:\\Users\\Admin\\Desktop\\voting for candidates\\No. candidates for TLC1.txt","w");
		fprintf(fp2,"%d",x);
		fclose(fp2);	
	}
	if(q==2)
	{
		y++;
		fp2=fopen("C:\\Users\\Admin\\Desktop\\voting for candidates\\No. candidates for TLC2.txt","w");
		fprintf(fp2,"%d",y);
		fclose(fp2);
	}
	if(q==3)
	{
		z++;
		fp2=fopen("C:\\Users\\Admin\\Desktop\\voting for candidates\\No. candidates for TLC3.txt","w");
		fprintf(fp2,"%d",z);
		fclose(fp2);
	}
	if(q==4)
	{
		a++;
		fp2=fopen("C:\\Users\\Admin\\Desktop\\voting for candidates\\No. candidates for TLC4.txt","w");
		fprintf(fp2,"%d",a);
		fclose(fp2);
	}
	if(q==5)
	{
		b++;
		fp2=fopen("C:\\Users\\Admin\\Desktop\\voting for candidates\\No. candidates for TLC5.txt","w");
		fprintf(fp2,"%d",b);
		fclose(fp2);
	}
	
	printf("\nPress any key to continue...\n");
	button=getche();
	system("cls");
	addvoter();
}
void addvotersp()
{
	system("cls");
	int p=0,q;
	static int x,y,z,a,b;
	FILE*fp2;
	FILE*fp1;
	FILE*ptr1;
	printf("\nVoting for SPORTICS\n\nCandidates\n\n");
	fp1=fopen("C:\\Users\\Admin\\Desktop\\Candidates For Sportics.txt","r");
	while (fread(&s1,sizeof(s1),1,fp1)!=0)
			{	
				p++;
				printf ("%d> Name> %s\n",p,s1.name);
			}
	fclose(fp1);
	fflush(stdin);
	printf("\n\nVOTING\n");
	printf("\nEnter your name: ");
	gets(s2.name );
	printf("\nEnter your section: ");
	s2.section=getche();
	printf("\n\nEnter your ID: ");
	gets(s2.id);
	printf("\nEnter your batch name: ");
	gets(s2.batch);
	printf("\nEnter the name of candidate you want to vote: ");
	gets(s2.vote);
	printf("\nEnter S.NO of candidate you want to vote: ");
	scanf("%d",&q);
	printf("\nYour vote has been casted.Thank you\n");
	ptr1=fopen("C:\\Users\\Admin\\Desktop\\Voting For Sportics.txt","a");
	fwrite(&s2,1,sizeof(s2),ptr1);
	fclose(ptr1);
		if(q==1)
		{	
		x++;
		fp2=fopen("C:\\Users\\Admin\\Desktop\\voting for candidates\\No. candidates for spr1.txt","w");
		fprintf(fp2,"%d",x);
		fclose(fp2);	
		}
	if(q==2)
	{
		y++;
		fp2=fopen("C:\\Users\\Admin\\Desktop\\voting for candidates\\No. candidates for spr2.txt","w");
		fprintf(fp2,"%d",y);
		fclose(fp2);
	}
	if(q==3)
	{
		z++;
		fp2=fopen("C:\\Users\\Admin\\Desktop\\voting for candidates\\No. candidates for spr3.txt","w");
		fprintf(fp2,"%d",z);
		fclose(fp2);
	}
	if(q==4)
	{
		a++;
		fp2=fopen("C:\\Users\\Admin\\Desktop\\voting for candidates\\No. candidates for spr4.txt","w");
		fprintf(fp2,"%d",a);
		fclose(fp2);
	}
	if(q==5)
	{
		b++;
		fp2=fopen("C:\\Users\\Admin\\Desktop\\voting for candidates\\No. candidates for spr5.txt","w");
		fprintf(fp2,"%d",b);
		fclose(fp2);
	}
	printf("\nPress any key to continue...\n");
	button=getche();
	system("cls");
	addvoter();
}
void addvoterdecs()
{
	int p=0,q;
	static int x,y,z,a,b;
	FILE*fp2;
	system("cls");
	FILE*fp1;
	FILE*ptr1;
	printf("\nVoting for DECS\n\nCandidates\n\n");
	fp1=fopen("C:\\Users\\Admin\\Desktop\\Candidates For DECS.txt","r");
	while (fread(&s1,sizeof(s1),1,fp1)!=0)
			{	
				p++;
				printf ("%d> Name> %s\n",p,s1.name);
			}
	fclose(fp1);
	fflush(stdin);
	printf("\n\nVOTING\n");
	printf("\nEnter your name: ");
	gets(s2.name );
	printf("\nEnter your section: ");
	s2.section=getche();
	printf("\n\nEnter your ID: ");
	gets(s2.id);
	printf("\nEnter your batch name: ");
	gets(s2.batch);
	printf("\nEnter the name of candidate you want to vote: ");
	gets(s2.vote);
	printf("\nEnter S.NO of candidate you want to vote: ");
	scanf("%d",&q);
	printf("\nYour vote has been casted.Thank you\n");
	ptr1=fopen("C:\\Users\\Admin\\Desktop\\Voting For DECS.txt","a");
	fwrite(&s2,1,sizeof(s2),ptr1);
	fclose(ptr1);
	if(q==1)
	{	
		x++;
		fp2=fopen("C:\\Users\\Admin\\Desktop\\voting for candidates\\No. candidates for dec1.txt","w");
		fprintf(fp2,"%d",x);
		fclose(fp2);	
	}
	if(q==2)
	{
		y++;
		fp2=fopen("C:\\Users\\Admin\\Desktop\\voting for candidates\\No. candidates for dec2.txt","w");
		fprintf(fp2,"%d",y);
		fclose(fp2);
	}
	if(q==3)
	{
		z++;
		fp2=fopen("C:\\Users\\Admin\\Desktop\\voting for candidates\\No. candidates for dec3.txt","w");
		fprintf(fp2,"%d",z);
		fclose(fp2);
	}
	if(q==4)
	{
		a++;
		fp2=fopen("C:\\Users\\Admin\\Desktop\\voting for candidates\\No. candidates for dec4.txt","w");
		fprintf(fp2,"%d",a);
		fclose(fp2);
	}
	if(q==5)
	{
		b++;
		fp2=fopen("C:\\Users\\Admin\\Desktop\\voting for candidates\\No. candidates for dec5.txt","w");
		fprintf(fp2,"%d",b);
		fclose(fp2);
	}
	printf("\nPress any key to continue...\n");
	button=getche();
	system("cls");
	addvoter();
}
void display()
{
	char ch;
	fflush(stdin);
	system("cls");
	printf("\n\nWhich Deparment Candidates You Want to see\n");
	printf("\n1)TLC\n\n");
	printf("2)Sportics\n\n");
	printf("3)DECS\n\n");
	printf("4)Home Screen\n\n");
	printf("5)Exit\n\n");
	printf("Enter your choice:\n");
	fflush(stdin);
	scanf("%c",&ch);
	switch(ch)
	{
		case'1':
			distlc();
			break;
		case '2':
			dissp();
			break;
		case '3':
			disdecs();
			break;
		case '4':
			{
				system("cls");
				main();
				break;
			}
		case '5':
			exit();
			break;
		default:
			{
				system("cls");
				printf("\nWrong Choice\n");
				printf("\nEnter any key to contiune....\n");
				button=getche();
				system("cls");
				display();
			}
	}
}
void distlc()
{
	FILE*fp1;
	fp1=fopen("C:\\Users\\Admin\\Desktop\\Candidates For TLC.txt","r");
	system("cls");
	printf("Candidates For TLC\n\n");
	while (fread(&s1,sizeof(s1),1,fp1)!=0)
			{
				printf ("\nName> %s\nSection> %c\nID> %s\nBatch> %s\n",s1.name,s1.section,s1.id,s1.batch);
			}
	fclose(fp1);
	printf("\nPress any key to continue...\n");
	button=getche();
	system("cls");
	display();
}
void dissp()
{
	FILE*fp2;
	fp2=fopen("C:\\Users\\Admin\\Desktop\\Candidates For Sportics.txt","r");
	system("cls");
	printf("Candidates For Sportics\n\n");
	while (fread(&s1,sizeof(s1),1,fp2)!=0)
			{
				printf ("\nName> %s\nSection> %c\nID> %s\nBatch> %s\n",s1.name,s1.section,s1.id,s1.batch);
			}
	fclose(fp2);
	printf("\nPress any key to continue...\n");
	button=getche();
	system("cls");
	display();
}
void disdecs()
{
	FILE*fp3;
	fp3=fopen("C:\\Users\\Admin\\Desktop\\Candidates For DECS.txt","r");
	system("cls");
	printf("Candidates For DECS\n\n");
	while (fread(&s1,sizeof(s1),1,fp3)!=0)
			{
				printf ("\nName> %s\nSection> %c\nID> %s\nBatch> %s\n",s1.name,s1.section,s1.id,s1.batch);
			}
	fclose(fp3);
	printf("\nPress any key to continue...\n");
	button=getche();
	system("cls");
	display();
}
void votingstatus()
{
	char choicestatus;
	system("cls");
	fflush(stdin);
	printf("\n\nIn Which Deparment you want to see the voting status\n");
	printf("\n1)TLC(The Literacy Club)\n\n");
	printf("2)Sportics\n\n");
	printf("3)DECS\n\n");
	printf("4)Home Screen\n\n");
	printf("5)Exit\n\n");
	printf("Enter your choice:\n");
	scanf("%c",&choicestatus);
	fflush(stdin);
	switch(choicestatus)
	{
		case '1':
			statustlc();
			break;
		case '2':
			statussp();
			break;
		case '3':
			statusdecs();
			break;
		case '4':
			{
				system("cls");
				main();
				break;
			}
		case '5':
			exit();
			break;
		default:
			{
				system("cls");
				printf("\nWrong Choice\n");
				printf("\nEnter any key to contiune....\n");
				button=getche();
				system("cls");
				votingstatus();
			}
	}	
}
void statustlc()
{
	char ch;
	int x=0,y=0,z=0,c=0,b=0;
	FILE*fp1,*fp2,*fp3,*fp4,*fp5;
	system("cls");
	printf("Which status do you want to see?\n1> Voter's Information.\n2> No. of votes?");
	ch=getche();
	switch(ch)
	{
		case '1':
	
	FILE*fp9;
	fp9=fopen("C:\\Users\\Admin\\Desktop\\Voting For TLC.txt","r");
	system("cls");
	printf("\nVoting status of TLC Department\n\n");
	while (fread(&s2,sizeof(s2),1,fp9)!=0)
			{
				printf ("\nName> %s\nID> %s\nVoted for> %s\n",s2.name,s2.id,s2.vote);
			}
	fclose(fp9);
	printf("\nEnter any key to continue....\n");
	button=getche();
	system("cls");
	votingstatus();
		case '2':
			system("cls");
			fp1=fopen("C:\\Users\\Admin\\Desktop\\voting for candidates\\No. candidates for TLC1.txt","r");
			fscanf(fp1,"%d",&x);
			fclose(fp1);
			printf("\nNo of votes of candidate 1 standing in TLC Elections is : %d",x);
			fp2=fopen("C:\\Users\\Admin\\Desktop\\voting for candidates\\No. candidates for TLC2.txt","r");
			fscanf(fp2,"%d",&y);
			fclose(fp2);
			printf("\nNo of votes of candidate 2 standing in TLC Elections is : %d",y);
			fp3=fopen("C:\\Users\\Admin\\Desktop\\voting for candidates\\No. candidates for TLC3.txt","r");
			fscanf(fp3,"%d",&z);
			fclose(fp3);
			printf("\nNo of votes of candidate 3 standing in TLC Elections is : %d",z);
			fp4=fopen("C:\\Users\\Admin\\Desktop\\voting for candidates\\No. candidates for TLC4.txt","r");
			fscanf(fp4,"%d",&c);
			fclose(fp4);
			printf("\nNo of votes of candidate 4 standing in TLC Elections is : %d",c);
			fp5=fopen("C:\\Users\\Admin\\Desktop\\voting for candidates\\No. candidates for TLC5.txt","r");
			fscanf(fp5,"%d",&b);
			fclose(fp5);
			printf("\nNo of votes of candidate 5 standing in TLC Elections is : %d",b);
			printf("\nEnter any key to continue....\n");
	button=getche();
	system("cls");
	votingstatus();
	}
}
void statussp()
{
	char ch;
	int x=0,y=0,z=0,c=0,b=0;
	FILE*fp1,*fp2,*fp3,*fp4,*fp5;
	FILE*fp8;
	fp8=fopen("C:\\Users\\Admin\\Desktop\\Voting For Sportics.txt","r");
	system("cls");
	printf("Which status do you want to see?\n1> Voter's Information.\n2> No. of votes?");
	ch=getche();
	switch (ch)
		{
		case '1':
	printf("\nVoting status of Sportics Department\n\n");
	while (fread(&s2,sizeof(s2),1,fp8)!=0)
			{
				printf ("\nName> %s\nID> %s\nVoted for> %s\n",s2.name,s2.id,s2.vote);
			}
	fclose(fp8);
	printf("\nEnter any key to continue....\n");
	button=getche();
	system("cls");
	votingstatus();
	case '2':
		system("cls");
			fp1=fopen("C:\\Users\\Admin\\Desktop\\voting for candidates\\No. candidates for spr1.txt","r");
			fscanf(fp1,"%d",&x);
			fclose(fp1);
			printf("\nNo of votes of candidate 1 standing in Sportics Elections is : %d",x);
			fp2=fopen("C:\\Users\\Admin\\Desktop\\voting for candidates\\No. candidates for spr2.txt","r");
			fscanf(fp2,"%d",&y);
			fclose(fp2);
			printf("\nNo of votes of candidate 2 standing in Sportics Elections is : %d",y);
			fp3=fopen("C:\\Users\\Admin\\Desktop\\voting for candidates\\No. candidates for spr3.txt","r");
			fscanf(fp3,"%d",&z);
			fclose(fp3);
			printf("\nNo of votes of candidate 3 standing in Sportics Elections is : %d",z);
			fp4=fopen("C:\\Users\\Admin\\Desktop\\voting for candidates\\No. candidates for spr4.txt","r");
			fscanf(fp4,"%d",&c);
			fclose(fp4);
			printf("\nNo of votes of candidate 4 standing in Sportics Elections is : %d",c);
			fp5=fopen("C:\\Users\\Admin\\Desktop\\voting for candidates\\No. candidates for spr5.txt","r");
			fscanf(fp5,"%d",&b);
			fclose(fp5);
			printf("\nNo of votes of candidate 5 standing in Sportics Elections is : %d",b);
			printf("\nEnter any key to continue....\n");
	button=getche();
	system("cls");
	votingstatus();	
}
}
void statusdecs()
{
	char ch;
	int x=0,y=0,z=0,c=0,b=0;
	FILE*fp1,*fp2,*fp3,*fp4,*fp5;
	FILE*fp7;
	fp7=fopen("C:\\Users\\Admin\\Desktop\\Voting For DECS.txt","r");
	system("cls");
		printf("Which status do you want to see?\n1> Voter's Information.\n2> No. of votes? '");
	ch=getche();
	switch(ch)
	{
		case '1':
	
	printf("\nVoting status of DECS Department\n\n");
	while (fread(&s2,sizeof(s2),1,fp7)!=0)
			{
				printf ("\nName> %s\nID> %s\nVoted for> %s\n",s2.name,s2.id,s2.vote);
			}
	fclose(fp7);
	printf("\nEnter any key to continue....\n");
	button=getche();
	system("cls");
	votingstatus();
	case '2':
			system("cls");
			fp1=fopen("C:\\Users\\Admin\\Desktop\\voting for candidates\\No. candidates for dec1.txt","r");
			fscanf(fp1,"%d",&x);
			fclose(fp1);
			printf("\nNo of votes of candidate 1 standing in DECS Elections is : %d",x);
			fp2=fopen("C:\\Users\\Admin\\Desktop\\voting for candidates\\No. candidates for dec2.txt","r");
			fscanf(fp2,"%d",&y);
			fclose(fp2);
			printf("\nNo of votes of candidate 2 standing in DECS Elections is : %d",y);
			fp3=fopen("C:\\Users\\Admin\\Desktop\\voting for candidates\\No. candidates for dec3.txt","r");
			fscanf(fp3,"%d",&z);
			fclose(fp3);
			printf("\nNo of votes of candidate 3 standing in DECS Elections is : %d",z);
			fp4=fopen("C:\\Users\\Admin\\Desktop\\voting for candidates\\No. candidates for dec4.txt","r");
			fscanf(fp4,"%d",&c);
			fclose(fp4);
			printf("\nNo of votes of candidate 4 standing in DECS Elections is : %d",c);
			fp5=fopen("C:\\Users\\Admin\\Desktop\\voting for candidates\\No. candidates for dec5.txt","r");
			fscanf(fp5,"%d",&b);
			fclose(fp5);
			printf("\nNo of votes of candidate 5 standing in DECS Elections is : %d",b);
			printf("\nEnter any key to continue....\n");
	button=getche();
	system("cls");
	votingstatus();	
}
}
void shashkay()
{
	char button;
	printf("\n\n\t\t(WELCOME TO OUR ELECTION CELL)\n");
	printf("\nProgrammers : \n\nAleem Zulfiqar(k152847)\n\nM.Abdullah (k152255)\n\nHumran(k152882)\n\nBilal Khan(k15----)\n\nPress any key to start Application.\n\n");
	button=getch();
	system("cls");
	main();
}
void exit()
{
	char exi;
	char button;
	system("cls");
	printf("\n\nAre you sure to exit(Y/N)?\n\n");
	exi=getch();
	if(exi=='N'|| exi=='n')
	{
		system("cls");
		main();
	}
	else if(exi =='Y' || exi=='y')
	{
		printf("\n\n(Thanks for using our software)");
	}
	else
	{
		printf("\nWrong choice. Press any key to Enter enter again : ");
		button=getche();
		exit();
	}
}
