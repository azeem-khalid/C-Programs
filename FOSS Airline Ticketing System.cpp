#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

FILE *reservations, *flights , *crew , *tmpf;

struct flight //flight management
	{
		char fnumber[10];
		char date[10];
		char time[10];
		char destination[20];
		char crew[30];
		char pilot[10];
		int fare;
	}f1;
struct res //reservation management
	{
		char name[20];
		char fname[20];
		char passno[20];
		char nation[15];
		char contact[20];
		char dest[20];
		char fnum[10];
		char res_time[50];
	}e1;
struct crew //passenger record management
	{
		char name[100];
		char fathername[100];
		char CNIC[15];
		char DOB[50];
		char phone[50];
		char license[50];
	}c1;




void reservation(void); 
void new_flight(void);
void view_flight(void);
void cancel_flight(void);
void cancel_res(void);
void view_res(void);


main()
{
	system("COLOR F2");
	{
		system("CLS");
		//reservations=fopen("reservation.txt","a+");
		char action;
		int user;
		char temp;
		int i,j,k;
	
	for(i=0;i<=2;i++)
	{
		printf("\t\t\t\t");
			for(j=i;j<=2;j++) //loop for start_1
			printf("  ");
			for(k=2*i;k>=0;k--)
			printf(" *");
			for(j=i;j<=2;j++) //loop for start_2
			printf(" ");
			
			
		printf("\n");	
	}
	printf(" \t\t\tFOSS Airline Ticketing System\n");
	for(i=2;i>=0;i--)
	{
			printf("\t\t\t\t");
			for(j=i;j<=2;j++) //loop for start_1
			printf("  ");
			for(k=2*i;k>=0;k--)
			printf(" *");
			for(j=i;j<=2;j++) //loop for start_2
			printf(" ");
			
			
		printf("\n");	
	}
		char timee[30];
		printf("\n\n\n\n");
		printf("Press 1 to add new reservation\n\nPress 2 to manage flights\n\nPress 3 to manage reservation.");
		system("COLOR F2");
		
		time_t t;
			time(&t);
			strncpy(timee , ctime(&t) , 15);
		printf("\n\n\n\n\nCurrent Date & Time: %s" , timee);
		
		action=getch();
		
		switch (action)
		{
		case '1': //add reservation
			{
		 		system("CLS");
				reservation();		
				main();
				break;
		    }
		
			
		case '2': //manage flights
		{
			system("CLS");
			//flights=fopen("flights.txt","a+");
			printf("Press 1 to add a new flight\nPress 2 to view flights\nPress 3 to cancel a flight\n\nTo go back to main menu press 0");
				char temp=getch();
			if(temp=='1')
				{
				new_flight();
				break;
				}	
			
			else if(temp=='2')
			{
				view_flight();
				printf("Press any key to go back to main menu");
				getch();
				main();
				break;	
			}
			
			else if(temp=='3')
			{
			cancel_flight();
			printf("\t\t\nFlight Cancelled");
			printf("\nPress any key to continue");
			main();
			break;
			}
			
			else if(temp=='0')
			main();
			else
			{
			
			printf("\n\n\tInvalid Option!");
			getch();
			main();
			}
			
		}
			
		case'3': //manage reservation
		{
			system("CLS");
			printf("Enter 1 to cancel a reservation\nEnter 2 to view reservation\n");
			temp=getch();
			if(temp=='1')
			{
				cancel_res();
				main();
			}
			
			else if(temp=='2')
			view_res();
			printf("\n\nPress any key to go back to main menu");
			getche();
			main();
		}break;
		
		default:
			{
			printf("\n\n\t*INVALID OPTION*");
			getch();
			main();
			}
	

}
}
}


void view_res(void)
{
		char action;
	char search[20];
	system("CLS");
	reservations=fopen("reservations.txt" , "a+");
	printf("To view all reservations press 1\nTo search for specific reservation press 2\n\nTo go back to main menu press 0");
	action=getch();
	switch(action)
	{
		case '1':
			{
				system("CLS");
				while(fread(&e1 , sizeof(e1) , 1 , reservations) ==1)
				printf("Name: %s\nFather Name: %s\nPassport Number: %s\nDestination: %s\nFlight Number: %s\nTime of booking: %sNationality: %s\nContact Number: %s\n\n" , e1.name,e1.fname,e1.passno,e1.dest,e1.fnum,e1.res_time,e1.nation,e1.contact);
				
			}break;
		case '2':
			{
				system("CLS");
				printf("To search via name press 1\nTo search via passport number press 2");
				char chhoice=getch();
				if (chhoice=='1')
				{
					system("CLS");
					printf("Enter name: ");
					gets(search);
					system("CLS");
					while((fread(&e1 , sizeof(e1) , 1 , reservations) ==1))
					{
						if(strcmpi(e1.name , search)==0)
						printf("Name: %s\nFather Name: %s\nPassport Number: %s\nDestination: %s\nFlight Number: %s\nTime of booking: %sNationality: %s\nContact Number: %s\n\n" , e1.name,e1.fname,e1.passno,e1.dest,e1.fnum,e1.res_time,e1.nation,e1.contact);
					}
				}
				else if(chhoice=='2')
				{
					system("CLS");
					printf("Enter passport: ");
					gets(search);
					system("CLS");
					while((fread(&e1 , sizeof(e1) , 1 , reservations) ==1))
					{
						if(strcmpi(e1.passno , search)==0)
						printf("Name: %s\nFather Name: %s\nPassport Number: %s\nDestination: %s\nFlight Number: %s\nTime of booking: %sNationality: %s\nContact Number: %s\n\n" , e1.name,e1.fname,e1.passno,e1.dest,e1.fnum,e1.res_time,e1.nation,e1.contact);
					}			
				}
			}break;
		
		case'0':
		{
			main();
			break;
		}
		
		default:
		{
			printf("\n\n\t\tInvalid Option");
			getch();	
			view_res();
		}		
	}
	
}

void cancel_res(void)
{
	FILE *tmp_res;
	system("CLS");
	char cancel_reser[20];
	reservations = fopen("reservations.txt" , "a+");
	tmp_res = fopen("temp_res.txt" , "a+");
	printf("Enter the name of the reservation which you want to cancel");
	
	gets(cancel_reser);
	while(fread(&f1, sizeof(f1),1,reservations)==1)
	{
		if(strcmpi(e1.passno,cancel_reser)!=0)
		fwrite(&f1, sizeof(f1),1,tmp_res);
	}
	fclose(reservations);
	fclose(tmp_res);
	remove("reservations.txt");
	rename("temp_res.txt","reservations.txt");
	
	printf("\nPress y to cancel another reservation, or press any key to go back to main menu.");
	if(getch()=='y' || getch()=='Y')
	cancel_res();
	
}

void cancel_flight(void)
{
	FILE *temp_flights;
	flights=fopen("flights.txt","a+");
	char cancelflight[20];
	rewind(flights);
	printf("Enter the number of the flight which you want to cancel: ");
	temp_flights=fopen("temp_flights.txt","a+");
	gets(cancelflight);
	while(fread(&f1, sizeof(f1),1, flights)==1)
	{
		if(strcmpi(f1.fnumber,cancelflight)!=0)
		fwrite(&f1, sizeof(f1),1,temp_flights);
	}
	fclose(flights);
	fclose(temp_flights);
	strcat(cancelflight, ".txt");
	remove("flights.txt");
	remove(cancelflight);
	rename("temp_flights.txt","flights.txt");
}
void view_flight(void)
{
	flights=fopen("flights.txt" , "a+");
	system("CLS");
	rewind(flights);
	while(fread(&f1,sizeof(f1),1,flights)==1)
	printf("Flight Number= %s\nDate= %s\nTime= %s\nDestination=%s\nCrew=%s\nPilot=%s\nFare= %d\n\n\n",f1.fnumber,f1.date,f1.time,f1.destination,f1.crew,f1.pilot,f1.fare);
	fflush(stdin);
	fclose(flights);
}
void new_flight(void)
{			char file_name[10];
			char ch[50];
			flights=fopen("flights.txt" , "a+");
			system("CLS");
			printf("Enter flight Number:");
			fflush(stdin);
			scanf("%s",ch);

			int r = strlen(ch);
			ch[r] = '.';
			ch[r+1] = 't';
			ch[r+2] = 'x';
			ch[r+3] = 't';
			memset(f1.fnumber, '\0', sizeof(f1.fnumber));
    		strncpy(f1.fnumber, ch , 5 );
	
	
//			FILE *file_ptr;
//			file_ptr = fopen(ch,"w");
	
	
			fflush(stdin);
			
			printf("Enter the date: ");
			scanf("%s",&f1.date);
			fflush(stdin);
			printf("Enter the time: ");
			scanf("%s",&f1.time);
			fflush(stdin);
			printf("Enter the destination: ");
			scanf("%s",&f1.destination);
			fflush(stdin);
			printf("Enter the crew: ");
			scanf("%s",&f1.crew);
			fflush(stdin);
			printf("Enter the name of pilot: ");
			scanf("%s",&f1.pilot);
			fflush(stdin);
			printf("Enter the fare: ");
			scanf("%d",&f1.fare);
			fflush(stdin);
			fwrite(&f1, sizeof(f1),1,flights);
			printf("\n\t\tRecord Added!");
			printf("\n\t\t============");
			printf("\nPress 1 to enter another flight\nPress 2 to go back to the main menu");
			char action=getch();
			if(action=='1')
			new_flight();
			else if(action=='2')
			{
			fclose(flights);
			main();
			}
			
}
void reservation(void) //add new reservation
	{
	char flight_choice[10];
	char dest[20];
	flights=fopen("flights.txt" , "a+");
	printf("Enter your destination: ");
	gets(dest);
	system("CLS");
	rewind(flights);
	
	while(fread(&f1,sizeof(f1),1,flights)==1)
	{
	if(strcmpi(f1.destination , dest)==0)
	printf("\n| Flight Number= %s |\n| Date= %s |\n| Time= %s |\n| Destination=%s |\nFare= %d |\n",f1.fnumber,f1.date,f1.time,f1.destination,f1.fare);
	}
	rewind(flights);
	printf("Enter flight number to select the flight: ");
	gets(flight_choice);
//	toupper(flight_choice);
	while(fread(&f1,sizeof(f1),1,flights)==1)
	{
	if(strnicmp(f1.fnumber , flight_choice , 5)==0)
	{
			printf("%s",f1.fnumber);
			strcat(flight_choice , ".txt");
			FILE *flight_file=fopen(flight_choice , "a+");
			
			reservations=fopen("reservations.txt" , "a+");
			system("CLS");
			printf("Enter your name: \n");
			gets(e1.name);
			fflush(stdin);
			printf("Enter your father's name /husband's name: \n");
			gets(e1.fname);
			fflush(stdin);
			printf("Enter your passport's number: \n");
			gets(e1.passno);
			fflush(stdin);
			printf("Enter your contact number:\n");
			gets(e1.contact);
			printf("Enter your nationality: \n");
			gets(e1.nation);
			strcpy(e1.dest , dest);
			strcpy(e1.fnum , f1.fnumber);
			
			time_t curtime;
			time(&curtime);
			strcpy(e1.res_time , ctime(&curtime));
			
			fwrite(&e1, sizeof(e1),1,reservations);
			fwrite(&e1, sizeof(e1),1,flight_file);
			printf("\n\t\tRecord Added!");
			fflush(stdin);
			fclose(flight_file);
			break;
		}
		else 
		printf("\nFlight doesn't exists!");
					fclose(reservations);	
			fclose(flights);
	}
	
			printf("\n\nPress y to enter another record or press any other key to back to the main menu\n");
			char temp=getch();
			if(temp=='y' || temp=='Y')
			reservation();
			else
			{

			main();
			}
	}
