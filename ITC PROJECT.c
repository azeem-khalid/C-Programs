#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
void administrator();												// function for administrator choices
void customer();													// function for customer choices
void checkin();														// function for checking in
void restaurant();
void menu();														// function for food menu 
void rooms_count();
void search(char *);
struct info{
	int date,date1,month,month1,year,year1,guest,rooms;
	char contact_no[30];
	char first_name[50],last_name[50];
};
int count_empty = 0;
int count_filled = 0;
int rooms = 20;
int total_amount=0;
int m=0;
struct bill
{
	char food[30];
	int price;
}b[100];
void main()
{
	system("COLOR F2");
	char choice;
	Label :
	system("cls");
	printf("Enter your choice : \n");
	printf("1 - Administrator\n2 - Customer\n3 - Exit");					// options for user
	printf("\nEnter your choice:");
	choice = getche();
	printf("\n");
	switch(choice)
	{
		case '1' :
			system("COLOR B0");
			administrator();
			break;
		case '2' :
			system("COLOR B0"); 
			customer();
			break;
		case '3' :
			exit(0);
			break;
		default : 
			printf("Wrong choice");
			goto Label;
			break;
	}
}
void administrator()
{
	system("cls");
	int choice;
	char sname[20];
	printf("Enter Your ID : ");
	printf("Enter Your Password : ");
	label4:
	printf("What do you want to do : \n");
	printf("1 - Rooms count\n2 - Retrieve Data\n3 - Logout\n");
	printf("Enter choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1 :
			rooms_count();
			break;
		case 2 : 
			printf("Enter the name: ");
			scanf("%s" , &sname);
			printf("\n");
			search(sname); 
			break;
		case 3 : 
			main();
			break;
		default :
			printf("Wrong choice\n");
			goto label4;
			break;
	}
	goto label4;
}
void search(char sname[])
{
	char first_name[20] , last_name[20] , phone_number[20];
	int guest , rooms;
	FILE *ptr;
	ptr=fopen("checkin.txt" , "r");
	while(fscanf(ptr,"%s %s %s %d %d" , first_name , last_name , phone_number , &guest , &rooms)!=EOF)
	{
		if(strcmp(first_name , sname)==0)
		{
			printf("First Name: %s\nLast Name: %s\nPhone Number: %s\nTotal Guest: %d\nTotal Rooms: %d\n\n\n" , first_name , last_name , phone_number , guest , rooms);
		}
	}
}
void customer()
{
	char cust_choice;
	printf("\t\t\tWelcome To Diamond Hotel\n");
	label1:
	printf("What do you want to do :");
	printf("\n1 -CHECK IN\n2 - RESTAURANT\n3 - Logout\n");
	printf("Enter choice : ");
	cust_choice = getche();
	printf("\n");                                                                             
		switch(cust_choice)
		{
			case '1' : 
				system("COLOR 74");
				checkin();
				goto label1;
				break;
			case '2' : 
				system("COLOR 87");
				restaurant();
				goto label1;
				break;
			case '3' :
				 main(); 
				break;
			default : 
				printf("\nWrong choice\n\n");
				goto label1;
				break;
		}
}
void checkin()
{
	count_filled++;
	if(count_filled>20)
	{
		printf("Sorry all the rooms are filled\n");
		return;
	}
	else
	{
	char comp_choice,more_choice,in_comp_choice;
	int comp_amount;
	int date_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int date_month1[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int charges_per_room_per_day = 5000,bill;
	struct info user;
	system("cls");
	printf("\t\tCHECK IN FORM\n");
	printf("Please Fill Following Information\n");
	FILE *fp;
	fp = fopen("checkin.txt","a");
	time_t t;
	time(&t);
	printf("First Name : ");
	fflush(stdin);
	gets(user.first_name);
	printf("Last Name : ");
	fflush(stdin);
	gets(user.last_name);
	fflush(stdin);
	printf("Contact Number : ");
	gets(user.contact_no);
	fflush(stdin);
	printf("Guests : ");
	scanf("%d",&user.guest);
	printf("Rooms : ");
	scanf("%d",&user.rooms);
	fprintf(fp,"%s %s %s %d %d\n",user.first_name,user.last_name,user.contact_no,user.guest,user.rooms);
	Label2:
	printf("Today date and time is %s\n",ctime(&t));
	printf("Check In  date (DD-MM-YYYY) : ");
	scanf("%d %d %d",&user.date,&user.month,&user.year);
	printf("Check out  date (DD-MM-YYYY) : ");
	scanf("%d %d %d",&user.date1,&user.month1,&user.year1);
	
		                    /////////////  Date count starts /////////////////////
	int count = 0,temp = 0,temp1 = 0,i,temp2 = 0, temp3 = 0;
	int year_diff,days_diff,months_total,date_year = 365;                   
	temp2 = date_month[user.month-1];
	temp3 = date_month1[user.month1-1];
	if(temp2==31)
	user.date-=1;
	else if(temp2==28)
	user.date-=2;
	if(user.date1>user.date)
	{
		if(user.month==user.month1)
		{
			if(user.year==user.year1)
			{
				for(i=user.date ; i<user.date1 ; i++)
				count++;
			}
			else if(user.year1>user.year)
			{
				for(i=user.date;i<user.date1+365;i++)
				count++;
			}
		}
		else if(user.month1>user.month)
		{
			temp = user.month1-user.month;
			if(user.year==user.year1)
			{
				for(i=user.date ; i<user.date1+(temp*temp3) ; i++)
				count++;
			}
			else if(user.year1>user.year)
			{
				for(i=user.date;i<user.date1+(temp*temp3)+365;i++)
				count++;
			}
		}
		else if(user.month1<user.month)
		{
			temp = (12-user.month)+user.month1;
			temp1 = (user.month-user.month1)*30;			
			if(user.year1==user.year)
			{
				printf("Error");
				goto Label2;
			}
			else if(user.year1>user.year)
			{
				for(i=user.date;i<user.date1+(temp*temp3);i++)
				count++;
			}
	}
}
	else if(user.date>user.date1)
	{
		if(user.month==user.month1)
		{
			if(user.year==user.year1)
			{
				printf("Error");
				goto Label2;
			}
			else if(user.year1>user.year)
			{
				for(i=user.date;i<user.date1+365;i++)
				count++;
			}
		}
		else if(user.month1>user.month)
		{
			temp = user.month1-user.month;
			if(user.year1==user.year)
			{
				for(i=user.date;i<=user.date1+(temp*temp3);i++)
				count++;
			}
			else if(user.year1>user.year)
			{
				for(i=user.date;i<user.date1+(temp*temp3)+365;i++)
				count++;
			}
		}
		else if(user.month1<user.month)
		{
			temp = (12-user.month)+user.month1;
			temp1 = (user.month-user.month1)*30;
			if(user.year1==user.year)
			{
				printf("Error");
				goto Label2;
			}
			else if(user.year1>user.year)
			{
				for(i=user.date;i<user.date1+(temp*temp3);i++)
				count++;
			}
	}
	}
	else if(user.date1==user.date)
	{
		if(user.month==user.month1)
		{
			if(user.year1==user.year)
			{
				count = 1;
			}
			else if(user.year1>user.year)
			{
				for(i=user.date;i<user.date1+365;i++)
				count++;
			}
		}
		else if(user.month1>user.month)
		{
			temp = user.month1-user.month;
			if(user.year1==user.year)
			{
				for(i=user.date;i<user.date1+(temp*temp3);i++)
				count++;
			}
			else if(user.year1>user.year)
			{
				for(i=user.date;i<user.date1+(temp*temp3)+365;i++)
				count++;
			}
		}
		else if(user.month1<user.month)
		{
			temp = (12-user.month)+user.month1;
			temp1 = (user.month-user.month1)*30;
			if(user.year1==user.year)
			{
				printf("Error");
				goto Label2;
			}
			else if(user.year1>user.year)
			{
				for(i=user.date;i<user.date1+(temp*temp3);i++)
				count++;
			}
		}
	}
	printf("%d days\n",count);
	printf("Do You want to use any thing which is not complementry 1-Y 2-N\n");
	comp_choice = getche();
	printf("\n");
    switch(comp_choice)
	{
		case '1' :
			system("COLOR 80");
			start :
			printf("\t\t-----------------------------------------\n");
			printf("\t\t|\t      Room Stuff |\n");
			printf("\t\t|\tItems\t\t      Price |\n");
			printf("\t\t|  1. Mineral Water......Rs 50/-   |\n");
			printf("\t\t|  2. Chocloate..........Rs 70/-   |\n");
			printf("\t\t|  3. Biscuit............Rs 40/-   |\n");
			printf("\t\t|  4. Chips..............Rs 70/-   |\n");
			printf("\t\t|  5. Juice..............Rs 100/-  |\n");
			printf("\t\t|  6. Eggs...............Rs 20/-   |\n");
			printf("\t\t|  7. Bread..............Rs 55/-   |\n");
			printf("\t\t|  8. Cheese.............Rs 250/-  |\n");
			printf("\t\t|  9. Butter.............Rs 80/-   |\n");
			printf("\t\t-----------------------------------------\n");
			printf("Enter your choice : ");
			in_comp_choice=getche();
			switch(in_comp_choice)
			{
				case '1':
					comp_amount=comp_amount+50;
					break;
				case '2':
					comp_amount=comp_amount+70;
					break;
				case '3':
					comp_amount=comp_amount+40;
					break;
				case '4':
					comp_amount=comp_amount+70;
					break;
				case '5':
					comp_amount=comp_amount+100;
					break;
				case '6':
					comp_amount=comp_amount+20;
					break;
				case '7':
					comp_amount=comp_amount+55;
					break;
				case '8':
					comp_amount=comp_amount+250;
					break;
				case '9':
					comp_amount=comp_amount+80;
					break;
				
				default:
					printf("Enter correct number");
					break;
			}
			printf("\nDo you want to order more?(1-Y 2-N)");
			more_choice=getche();
			if(more_choice == '1')
				goto start;
			else
				goto start1;
		case '2' :
			goto label4;
			break;
		default :
			printf("Enter correct number");
			break;
		}
		//scanf("%d",&comp_amount);
	start1 :
		label4:
	system("COLOR F0");
	system("cls");
	printf("\n");
	printf("\t\t--------------------------------------------------------\n");
	printf("\t\t|                 %s                                    \n\n",ctime(&t));
	printf("\t\t|  ****************DIAMOND HOTEL********************    \n\n");
	printf("\t\t|                        BILL                           \n\n");
	printf("\t\t|           MOBILE=+92-3323561745                       \n\n");
	printf("\t\t--------------------------------------------------------\n");
	printf("\t\t|CUSTOMER NAME: %s %s                                   \n\n",user.first_name,user.last_name);
	printf("\t\t|ROOMS: %d                                              \n\n",user.rooms);
	printf("\t\t|CHARGES PER ROOM                           RS %d/-     \n\n",charges_per_room_per_day);
	printf("\t\t|OTHER STUFF                                RS %d/-     \n\n",comp_amount);
	printf("\t\t|TOTAL CHARGES                              RS %d/-     \n\n",charges_per_room_per_day*count+comp_amount);
	printf("\t\t--------------------------------------------------------\n");
	printf("\t\t|                HAVE A NICE DAY                        \n");
    printf("\t\t--------------------------------------------------------\n");
	}
}
void restaurant()
{
	char rest_choice;
	int tot_guest;
	printf("\t\t WELCOME TO DIAMOND RESTAURANT");
	printf("\n1 - Dine In\n 2 - Take away\n");
	printf("Enter your choice : ");
	rest_choice=getche();
	printf("\n");
	switch(rest_choice)
	{
		case '1' :
			system("COLOR F0");
			menu();
		case '2' :
			system("COLOR B0");
			menu();
		default :
			printf("Enter correct number");
			break;
			
				
	}
}
void menu()
{
	char another;
	int pak_choice;
	int italian_choice;
	int chinese_choice;
	int fastfood_choice;
	int salad_choice;
	int beverges_choice;
	char food_choice ;
	int k;
	start:
	system("cls");
	printf("\n\t\t\t MENU\n");
	printf("1 - Pakistani Food\n2 - Italian\n3 - Chinese & Soups\n4 - Fast Food\n5 - Snacks & Salad\n6 - Beverges\n7- Bill\n8- Exit\n");
	printf("Enter your choice : ");
	food_choice = getche();
	printf("\n");
	system("cls");
	switch(food_choice)
	{
		case '1' :
			system("COLOR A0");
			pak :
			system("cls");
			printf("\t\t-----------------------------------------\n");
			printf("\t\t|\t      Pakistani Food\t\t |\n");
			printf("\t\t|\tItems\t\t      Price\t |\n");
			printf("\t\t|  1. Chicken Biryani.........Rs 300/-   |\n");
			printf("\t\t|  2. Chicken Tandori.........Rs 550/-   |\n");
			printf("\t\t|  3. Chicken Karahi..........Rs 800/-   |\n");
			printf("\t\t|  4. Chicken Chargha.........Rs 850/-   |\n");
			printf("\t\t|  5. Mutton Karahi...........Rs 1050/-  |\n");
			printf("\t\t|  6. Mutton Korma............Rs 750/-   |\n");
			printf("\t\t|  7. Plain Rice..............Rs 250/-   |\n");
			printf("\t\t|  8. Daal Chawal.............Rs 300/-   |\n");
			printf("\t\t|  9. Palak Paneer............Rs 350/-   |\n");
			printf("\t\t|  10. Paratha................Rs 50/-    |\n");
			printf("\t\t-----------------------------------------\n");
			printf("Enter your choice : ");
			scanf("%d",&pak_choice);
			switch(pak_choice)
			{
				case 1:
					strcpy(b[m].food , "Chicken biryani");
					b[m].price=300;
					total_amount=total_amount+300;
					m++;
					break;
				case 2:
					strcpy(b[m].food , "Chicken Tandori");
					total_amount=total_amount+550;
					b[m].price=550;
					m++;
					break;
				case 3:
					strcpy(b[m].food , "Chicken Karahi");
					total_amount=total_amount+800;
					b[m].price=800;
					m++;
					break;
				case 4:
					strcpy(b[m].food , "Chicken Chargha");
					total_amount=total_amount+850;
					b[m].price=850;
					m++;
					break;
				case 5:
					strcpy(b[m].food , "Mutton Karahi");
					total_amount=total_amount+1050;
					b[m].price=1050;
					m++;
					break;
				case 6:
					strcpy(b[m].food , "Chicken Korma");
					total_amount=total_amount+750;
					b[m].price=750;
					m++;
					break;
				case 7:
					strcpy(b[m].food , "Plain Rice");
					total_amount=total_amount+250;
					b[m].price=250;
					m++;
					break;
				case 8:
					strcpy(b[m].food , "Daal Chawal");
					total_amount=total_amount+300;
					b[m].price=300;
					m++;
					break;
				case 9:
					strcpy(b[m].food , "Palak Paneer");
					total_amount=total_amount+350;
					b[m].price=350;
					m++;
					break;
				case 10:
					strcpy(b[m].food , "Paratha");
					total_amount=total_amount+50;
					b[m].price=50;
					m++;
					break;
				default:
					printf("Enter correct number");
					break;
			}
			printf("\nDo you want to order more in Pakistani Food?(Y/N)");
			another=getche();
			if(another == 'Y' || another == 'y')
			{
				goto pak;
			}
			else
			{
				goto start;
			}
			break;
		case '2' :
			system("COLOR D0");
			italian :
			system("cls");
			printf("\t\t----------------------------------------------------------\n");
			printf("\t\t|\t\t\tItalian Food\t\t\t |\n");
			printf("\t\t|\tItems\t\t\t\t\tPrice\t |\n");
			printf("\t\t|  1. Panzenella..............................Rs 300/-   |\n");
			printf("\t\t|  2. Bruschetta..............................Rs 550/-   |\n");
			printf("\t\t|  3. Pasta Carbonara.........................Rs 500/-   |\n");
			printf("\t\t|  4. Margherita Pizza........................Rs 850/-   |\n");
			printf("\t\t|  5. Mushroom Risotto........................Rs 700/-   |\n");
			printf("\t\t|  6. Panna Cotta With Raspberry Coulis.......Rs 450/-   |\n");
			printf("\t\t|  7. Tiramisu - The 'pick-me-up' cake........Rs 350/-   |\n");
			printf("\t\t|  8. Focaccia Bread..........................Rs 300/-   |\n");
			printf("\t\t|  9. Caprese Salad with Pesto Sauce..........Rs 350/-   |\n");
			printf("\t\t----------------------------------------------------------\n");
			printf("Enter your choice : ");
			italian_choice=getche();
			switch(italian_choice)
			{
				case '1':
					strcpy(b[m].food , "Panzenella");
					total_amount=total_amount+300;
					b[m].price=300;
					m++;
					break;
				case '2':
					strcpy(b[m].food , "Bruschette");
					total_amount=total_amount+550;
					b[m].price=550;
					m++;
					break;
				case '3':
					strcpy(b[m].food , "Pasta Carbonara");
					total_amount=total_amount+500;
					b[m].price=550;
					m++;
					break;
				case '4':
					strcpy(b[m].food , "Margherita Pizza");
					total_amount=total_amount+850;
					b[m].price=850;
					m++;
					break;
				case '5':
					strcpy(b[m].food , "Mushroom Risotto");
					total_amount=total_amount+700;
					b[m].price=700;
					m++;
					break;
				case '6':
					strcpy(b[m].food , "Panna Cotta with Raspberry Coulis");
					total_amount=total_amount+450;
					b[m].price=450;
					m++;
					break;
				case '7':
					strcpy(b[m].food , "Tiramisu- The 'Pick me up' cake");
					total_amount=total_amount+350;
					b[m].price=350;
					m++;
					break;
				case '8':
					strcpy(b[m].food , "Facoccia Bread");
					total_amount=total_amount+300;
					b[m].price=300;
					m++;
					break;
				case '9':
					strcpy(b[m].food , "Caprese salad with pesto sause");
					total_amount=total_amount+350;
					b[m].price=350;
					m++;
					break;
				default:
					printf("Enter correct number");
					break;
			}
			printf("\nDo you want to order more in Italian Food?(Y/N)");
			another=getche();
			if(another == 'Y' || another == 'y')
			{
				goto italian;
			}
			else
			{
				goto start;
			}
			break;
		case '3' :
			system("COLOR F0");
			chinese :
			system("cls");
			printf("\t\t---------------------------------------------------------------\n");
			printf("\t\t|\t\t\tChinese Food\t\t\t     |\n");
			printf("\t\t|\tItems\t\t\t\t\t  Price\t     |\n");
			printf("\t\t|  1. Sweet and Sour Pork/Chicken.................Rs 700/-   |\n");
			printf("\t\t|  2. Kung Pao (Gong Bao) Chicken.................Rs 550/-   |\n");
			printf("\t\t|  3. Egg-fried rice..............................Rs 500/-   |\n");
			printf("\t\t|  4. Spicy Tofu (Mapo doufu).....................Rs 850/-   |\n");
			printf("\t\t|  5. Dumplings...................................Rs 400/-   |\n");
			printf("\t\t|  6. Won Ton Soup................................Rs 450/-   |\n");
			printf("\t\t|  7. Chow Mein...................................Rs 350/-   |\n");
			printf("\t\t|  8. Fried Shrimps with Cashews..................Rs 300/-   |\n");
			printf("\t\t---------------------------------------------------------------\n");
			printf("Enter your choice : ");
			chinese_choice=getche();
			switch(chinese_choice)
			{
				case '1':
					strcpy(b[m].food , "Sweet and sour pork/chicken");
					total_amount=total_amount+700;
					b[m].price=700;
					m++;
					break;
				case '2':
					strcpy(b[m].food , "Kung pao (Gong bao) Chicken");
					total_amount=total_amount+550;
					b[m].price=550;
					m++;
					break;
				case '3':
					strcpy(b[m].food , "Egg fried rice");
					total_amount=total_amount+500;
					b[m].price=500;
					m++;
					break;
				case '4':
					strcpy(b[m].food , "Spicy Tofu");
					total_amount=total_amount+850;
					b[m].price=850;
					m++;
					break;
				case '5':
					strcpy(b[m].food , "Dumplings");
					total_amount=total_amount+400;
					b[m].price=400;
					m++;
					break;
				case '6':
					strcpy(b[m].food , "Won Ton Soup");
					total_amount=total_amount+450;
					b[m].price=450;
					m++;
					break;
				case '7':
					strcpy(b[m].food , "Chow mein");
					total_amount=total_amount+350;
					b[m].price=350;
					m++;
					break;
				case '8':
					strcpy(b[m].food , "Fried Shrimps with Cashews");
					total_amount=total_amount+300;
					b[m].price=300;
					m++;
					break;
				default:
					printf("Enter correct number");
					break;
			}
			printf("\nDo you want to order more in Chinese Food?(Y/N)");
			another=getche();
			if(another == 'Y' || another == 'y')
			{
				goto chinese;
			}
			else
			{
				goto start;
			}
			break;
		case '4' :
			system("COLOR 85");
			fast :
			system("cls");
			printf("\t\t--------------------------------------------------------\n");
			printf("\t\t|\t\t\tFast Food\t\t       |\n");
			printf("\t\t|\tItems\t\t\t\t     Price     |\n");
			printf("\t\t|  1. Thick burger ( Combo).................Rs 300/-   |\n");
			printf("\t\t|  2. Cheese Burger (Combo).................Rs 350/-   |\n");
			printf("\t\t|  3. Jalapeno Burger (Combo)...............Rs 400/-   |\n");
			printf("\t\t|  4. Grilled Chicken (Combo)...............Rs 600/-   |\n");
			printf("\t\t|  5. Natural Cut Fries.....................Rs 200/-   |\n");
			printf("\t\t|  6. Zinger burger.........................Rs 300/-   |\n");
			printf("\t\t|  7. Chicken broast........................Rs 300/-   |\n");
			printf("\t\t|  8. Chicken Sandwitch.....................Rs 300/-   |\n");
			printf("\t\t--------------------------------------------------------\n");
			printf("Enter your choice : ");
			fastfood_choice=getche();
			switch(fastfood_choice)
			{
				case '1':
					strcpy(b[m].food , "Thick Burger(Combo)");
					total_amount=total_amount+300;
					b[m].price=300;
					m++;
					break;
				case '2':
					strcpy(b[m].food , "Cheese Burger(Combo)");
					total_amount=total_amount+350;
					b[m].price=350;
					m++;
					break;
				case '3':
					strcpy(b[m].food , "Jalapeno Burger(Combo)");
					total_amount=total_amount+400;
					b[m].price=400;
					m++;
					break;
				case '4':
					strcpy(b[m].food , "Grilled Chicken(Combo)");
					total_amount=total_amount+600;
					b[m].price=600;
					m++;
					break;
				case '5':
					strcpy(b[m].food , "Natural cut fries");
					total_amount=total_amount+200;
					b[m].price=200;
					m++;
					break;
				case '6':
					strcpy(b[m].food , "Zinger Burger");
					total_amount=total_amount+300;
					b[m].price=300;
					m++;
					break;
				case '7':
					strcpy(b[m].food , "Chicken Broast");
					total_amount=total_amount+300;
					b[m].price=300;
					m++;
					break;
				case '8':
					strcpy(b[m].food , "Chicken Sandwitch");
					total_amount=total_amount+300;
					b[m].price=300;
					m++;
					break;
				default:
					printf("Enter correct number");
					break;
			}
			printf("\nDo you want to order more in Fast Food?(Y/N)");
			another=getche();
			if(another == 'Y' || another == 'y')
			{
				goto fast;
			}
			else
			{
				goto start;
			}
			break;
		case '5':
			system("COLOR 80");
			snack :
			system("cls");
			printf("\t\t--------------------------------------------------------\n");
			printf("\t\t|\t      Snacks & Salad\t\t |\n");
			printf("\t\t|\tItems\t\t      Price\t |\n");
			printf("\t\t|  1. Russian Salad.........................Rs 250/-   |\n");
			printf("\t\t|  2. Arabian Salad.........................Rs 300/-   |\n");
			printf("\t\t|  3. Tomato-Peach Salad....................Rs 300/-   |\n");
			printf("\t\t|  4. Creole Green Beans Salad..............Rs 350/-   |\n");
			printf("\t\t|  5. Squash & Orzo Salad...................Rs 350/-   |\n");
			printf("\t\t|  6. Caesar Salad..........................Rs 400/-   |\n");
			printf("\t\t|  7. Dilled Egg Salad......................Rs 400/-   |\n");
			printf("\t\t|  8. Greek Cucumber Salad..................Rs 200/-   |\n");
			printf("\t\t|  9. Mix Bean Salad........................Rs 500/-   |\n");
			printf("\t\t|  10. Fruit Chat...........................Rs 150/-   |\n");
			printf("\t\t--------------------------------------------------------\n");
			printf("Enter your choice : ");
			scanf("%d",&salad_choice);
			switch(salad_choice)
			{
				case 1:
					strcpy(b[m].food , "Russian Salad");
					total_amount=total_amount+250;
					b[m].price=250;
					m++;
					break;
				case 2:
					strcpy(b[m].food , "Arabian Salad");
					total_amount=total_amount+300;
					b[m].price=300;
					m++;
					break;
				case 3:
					strcpy(b[m].food , "Tomato-peach Salad");
					total_amount=total_amount+300;
					b[m].price=300;
					m++;
					break;
				case 4:
					strcpy(b[m].food , "Creole Green Bean Salad");
					total_amount=total_amount+350;
					b[m].price=350;
					m++;
					break;
				case 5:
					strcpy(b[m].food , "Squash and orzo Salad");
					total_amount=total_amount+350;
					b[m].price=350;
					m++;
					break;
				case 6:
					strcpy(b[m].food , "Caesar Salad");
					total_amount=total_amount+400;
					b[m].price=400;
					m++;
					break;
				case 7:
					strcpy(b[m].food , "Dilled Egg Salad");
					total_amount=total_amount+400;
					b[m].price=400;
					m++;
					break;
				case 8:
					strcpy(b[m].food , "Greek Cucumber Salad");
					total_amount=total_amount+200;
					b[m].price=200;
					m++;
					break;
				case 9:
					strcpy(b[m].food , "Mix bean Salad");
					total_amount=total_amount+500;
					b[m].price=500;
					m++;
					break;
				case 10:
					strcpy(b[m].food , "Fruit Chat");
					total_amount=total_amount+150;
					b[m].price=150;
					m++;
					break;
				default:
					printf("\nEnter correct number");
					break;
	
			}
			printf("\nDo you want to order more Snacks & Salad?(Y/N)");
			another=getche();
			if(another == 'Y' || another == 'y')
			{
				goto snack;
			}
			else
			{
				goto start;
			}
			break;
		case '6' :
			system("COLOR B0");
			beverges :
			system("cls");
			printf("\t\t--------------------------------------------------------\n");
			printf("\t\t|\t\t\tBeverges\t\t       |\n");
			printf("\t\t|\tItems\t\t\t\t     Price     |\n");
			printf("\t\t|  1. Aloe Vera Juice.......................Rs 120/-   |\n");
			printf("\t\t|  2. Apple Juice...........................Rs 130/-   |\n");
			printf("\t\t|  3. Coconut Water.........................Rs 100/-   |\n");
			printf("\t\t|  4. Sugarcane Juice.......................Rs 100/-   |\n");
			printf("\t\t|  5. Pomegranate Juice.....................Rs 90/-    |\n");
			printf("\t\t|  6. Cucumber Juice........................Rs 110/-   |\n");
			printf("\t\t|  7. Lemonade..............................Rs 50/-    |\n");
			printf("\t\t|  8. Winter Melon Punch....................Rs 50/-    |\n");
			printf("\t\t|  9. Cold Drink............................Rs 40/-    |\n");
			printf("\t\t| 10. Mineral Water.........................Rs 60/-    |\n");
			printf("\t\t--------------------------------------------------------\n");
			printf("Enter your choice : ");
			scanf("%d",&beverges_choice);
			switch(beverges_choice)
			{
				case 1:
					strcpy(b[m].food , "Aloe Vera Juice");
					total_amount=total_amount+120;
					b[m].price=120;
					m++;
					break;
				case 2:
					strcpy(b[m].food , "Apple Juice");
					total_amount=total_amount+130;
					b[m].price=130;
					m++;
					break;
				case 3:
					strcpy(b[m].food , "Coconut Water");
					total_amount=total_amount+100;
					b[m].price=100;
					m++;
					break;
				case 4:
					strcpy(b[m].food , "Sugarcane Juice");
					total_amount=total_amount+100;
					b[m].price=100;
					m++;
					break;
				case 5:
					strcpy(b[m].food , "Pomegranate Juice");
					total_amount=total_amount+90;
					b[m].price=90;
					m++;
					break;
				case 6:
					strcpy(b[m].food , "Cucumber Juice");
					total_amount=total_amount+110;
					b[m].price=110;
					m++;
					break;
				case 7:
					strcpy(b[m].food , "Lemonade");
					total_amount=total_amount+50;
					b[m].price=50;
					m++;
					break;
				case 8:
					strcpy(b[m].food , "Winter melon punch");
					total_amount=total_amount+50;
					b[m].price=50;
					m++;
					break;
				case 9:
					strcpy(b[m].food , "Cold Drinks");
					total_amount=total_amount+40;
					b[m].price=40;
					m++;
					break;
				case 10:
					strcpy(b[m].food , "Mineral Water");
					total_amount=total_amount+60;
					b[m].price=60;
					m++;
					break;
				default:
					printf("Enter correct number");
					break;
			}
			printf("\nDo you want to order more?(Y/N)");
			another=getche();
			if(another == 'Y' || another == 'y')
			{
				goto beverges;
			}
			else
			{
				goto start;
			}
			break;
		case '7' :
			printf("\t\t---------------------------------------------");
			printf("\t\t\t\t\t\t\t\tBILL\n\n");
			printf("\t\t\tItem\t\t\t\tPrice\n");
			for(k=0;k<m;k++)
			{
				printf("\t\t\t%s\t\t\t%d\n" , b[k].food , b[k].price);
			}
			printf("\n\n\t\t\tTotal Bill= %d\n\n" , total_amount);
			printf("\n\t\t\t\tTHANK YOU\n");
			printf("\t\t---------------------------------------------");
			printf("\n\nDo you want to continue(Y/N):");
			another=getche();
			if(another == 'Y' || another == 'y')
			{
				goto start;
			}
			else
			{
				goto exit;
			}
			break;
		case '8':
			{
				exit:
				customer();
				break;	
			}	
		default :
			printf("\nEnter correct number");
			goto start;
			break;	
	}
}
void rooms_count()
{
	count_empty = 20-count_filled;
	printf("There are %d rooms empty.\n",count_empty);
	printf("There are %d rooms filled.\n",count_filled);
}
