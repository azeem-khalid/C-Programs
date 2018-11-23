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
struct info{
	int date,date1,month,month1,year,year1,guest,rooms;
	long int contact_no;
	char first_name[50],last_name[50];
};
int total_amount=0;
main()
{
	char choice;
	Label :
	printf("Enter your choice : \n");
	printf("1 - Administrator\n2 - Customer\n");					// options for user
	choice = getche();
	printf("\n");
	switch(choice)
	{
		case '1' : 
			administrator();
			break;
		case '2' : 
			customer();
			break;
		default : 
			printf("Wrong choice");
			goto Label;
			break;
	}
}
void administrator()
{
	printf("");
}
void customer()
{
	char cust_choice;
	printf("\t\t\tWelcome To Diamond Hotel\n");
	Label1 :
	printf("What do you want to do :");
	printf("1 - CHECK IN\n2 - RESTAURANT");
	cust_choice = getche();
	printf("\n");
	switch(cust_choice)
	{
		case '1' : 
			checkin();
			break;
		case '2' : 
			restaurant();
			break;
		default : 
			printf("Wrong choice");
			goto Label1;
			break;
	}
	
}
void checkin()
{
	char a,c,b;
	int total_amout;
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
	gets(&user.first_name);
	printf("Last Name : ");
	gets(&user.last_name);
	printf("Contact Number : ");
	scanf("%ld",&user.contact_no);
	printf("Guests : ");
	scanf("%d",&user.guest);
	printf("Rooms : ");
	scanf("%d",&user.rooms);
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
printf("\n%d\n%d days\n",temp,count);
start :
printf("Did you use any thing in the room which was not complementry 1-Y 2-N");
	a=getche;
	
    switch(a)
	{
		case '1':
			printf("\t\t-----------------------------------------\n");
			printf("\t\t|\t      Room Stuff\t\t |\n");
			printf("\t\t|\tItems\t\t      Price\t |\n");
			printf("\t\t|  1. Mineral Water......Rs 50/-   |\n");
			printf("\t\t|  2. Chocloate..........Rs 70/-   |\n");
			printf("\t\t|  3. Biscuit............Rs 40/-   |\n");
			printf("\t\t|  4. Chips..............Rs 70/-   |\n");
			printf("\t\t|  5. Juice..............Rs 100/-  |\n");
			printf("\t\t|  6. Eggs...............Rs 20/-   |\n");
			printf("\t\t|  7. Bread..............Rs 55/-   |\n");
			printf("\t\t|  8. Cheese.............Rs 250/-   |\n");
			printf("\t\t|  9. Butter.............Rs 80/-   |\n");
			printf("\t\t-----------------------------------------\n");
			printf("Enter your choice : ");
			b=getche();
			switch(b)
			{
				case '1':
					total_amout=total_amout+50;
					break;
				case '2':
					total_amout=total_amout+70;
					break;
				case '3':
					total_amout=total_amout+40;
					break;
				case '4':
					total_amout=total_amout+70;
					break;
				case '5':
					total_amout=total_amout+100;
					break;
				case '6':
					total_amout=total_amout+20;
					break;
				case '7':
					total_amout=total_amout+55;
					break;
				case '8':
					total_amout=total_amout+250;
					break;
				case '9':
					total_amout=total_amout+80;
					break;
				
				default:
					printf("Enter correct number");
					break;
			}	printf("\nDo you want to order more?(Y/N)");
			c=getche();
			if(c == 'Y' || c == 'y')
			{
				goto start;
			}
			else
			{
				break;
			}
			default :
				break;
			}
		scanf("%d",&total_amout);
		
	
	fwrite(&user,sizeof(user),1,fp);
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
	printf("\t\t|OTHER STUFF                                RS %d/-     \n\n",total_amout);
	printf("\t\t|TOTAL CHARGES                              RS %d/-     \n\n",charges_per_room_per_day*count+total_amout);
	printf("\t\t--------------------------------------------------------\n");
	printf("\t\t|                HAVE A NICE DAY                        \n");
    printf("\t\t--------------------------------------------------------\n");
}
void restaurant()
{
	char rest_choice;
	int tot_guest;
	printf("\t\t WELCOME TO DIAMOND RESTAURANT");
	printf("1 - Dine In\n 2 - Take away\n");
	printf("Enter your choice : ");
	rest_choice=getche();
	printf("\n");
	switch(rest_choice)
	{
		case '1' :
			menu();
	//	case '2' :
				
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
	start:
	system("cls");
	printf("\n\t\t\t MENU\n");
	printf("1 - Pakistani Food\n2 - Italian\n3 - Chinese & Soups\n4 - Fast Food\n5 - Snacks & Salad\n6 - Beverges\n");
	printf("Enter your choice : ");
	food_choice = getche();
	printf("\n");
	system("cls");
	switch(food_choice)
	{
		case '1' :
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
			pak_choice=getche();
			switch(pak_choice)
			{
				case '1':
					total_amount=total_amount+300;
					break;
				case '2':
					total_amount=total_amount+550;
					break;
				case '3':
					total_amount=total_amount+800;
					break;
				case '4':
					total_amount=total_amount+850;
					break;
				case '5':
					total_amount=total_amount+1050;
					break;
				case '6':
					total_amount=total_amount+750;
					break;
				case '7':
					total_amount=total_amount+250;
					break;
				case '8':
					total_amount=total_amount+300;
					break;
				case '9':
					total_amount=total_amount+350;
					break;
				case '10':
					total_amount=total_amount+50;
					break;
				default:
					printf("Enter correct number");
					break;
			}
			printf("\nDo you want to order more?(Y/N)");
			another=getche();
			if(another == 'Y' || another == 'y')
			{
				goto start;
			}
			else
			{
				break;
			}
		case '2' :
			printf("\t\t----------------------------------------------------------\n");
			printf("\t\t|\t\t\tItalian Food\t\t\t |\n");
			printf("\t\t|\tItems\t\t\t\t\tPrice\t |\n");
			printf("\t\t|  1. Panzenella..............................Rs 300/-   |\n");
			printf("\t\t|  2. Bruschetta..............................Rs 550/-   |\n");
			printf("\t\t|  3. Pasta Carbonara.........................Rs 500/-   |\n");
			printf("\t\t|  4. Margherita Pizza........................Rs 850/-   |\n");
			printf("\t\t|  5. Mushroom Risotto........................Rs 700/-  |\n");
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
					total_amount=total_amount+300;
					break;
				case '2':
					total_amount=total_amount+550;
					break;
				case '3':
					total_amount=total_amount+500;
					break;
				case '4':
					total_amount=total_amount+850;
					break;
				case '5':
					total_amount=total_amount+700;
					break;
				case '6':
					total_amount=total_amount+450;
					break;
				case '7':
					total_amount=total_amount+350;
					break;
				case '8':
					total_amount=total_amount+300;
					break;
				case '9':
					total_amount=total_amount+350;
					break;
				default:
					printf("Enter correct number");
					break;
			}
			printf("\nDo you want to order more?(Y/N)");
			another=getche();
			if(another == 'Y' || another == 'y')
			{
				goto start;
			}
			else
			{
				break;
			}
		case '3' :
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
					total_amount=total_amount+700;
					break;
				case '2':
					total_amount=total_amount+550;
					break;
				case '3':
					total_amount=total_amount+500;
					break;
				case '4':
					total_amount=total_amount+850;
					break;
				case '5':
					total_amount=total_amount+400;
					break;
				case '6':
					total_amount=total_amount+450;
					break;
				case '7':
					total_amount=total_amount+350;
					break;
				case '8':
					total_amount=total_amount+300;
					break;
				default:
					printf("Enter correct number");
					break;
			}
			printf("\nDo you want to order more?(Y/N)");
			another=getche();
			if(another == 'Y' || another == 'y')
			{
				goto start;
			}
			else
			{
				break;
			}
		case '4' :
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
					total_amount=total_amount+300;
					break;
				case '2':
					total_amount=total_amount+350;
					break;
				case '3':
					total_amount=total_amount+400;
					break;
				case '4':
					total_amount=total_amount+600;
					break;
				case '5':
					total_amount=total_amount+200;
					break;
				case '6':
					total_amount=total_amount+300;
					break;
				case '7':
					total_amount=total_amount+300;
					break;
				case '8':
					total_amount=total_amount+300;
					break;
				default:
					printf("Enter correct number");
					break;
			}
			printf("\nDo you want to order more?(Y/N)");
			another=getche();
			if(another == 'Y' || another == 'y')
			{
				goto start;
			}
			else
			{
				break;
			}
		case '5':
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
			salad_choice=getche();
			switch(salad_choice)
			{
				case '1':
					total_amount=total_amount+250;
					break;
				case '2':
					total_amount=total_amount+300;
					break;
				case '3':
					total_amount=total_amount+300;
					break;
				case '4':
					total_amount=total_amount+350;
					break;
				case '5':
					total_amount=total_amount+350;
					break;
				case '6':
					total_amount=total_amount+400;
					break;
				case '7':
					total_amount=total_amount+400;
					break;
				case '8':
					total_amount=total_amount+200;
					break;
				case '9':
					total_amount=total_amount+500;
					break;
				case '10':
					total_amount=total_amount+150;
					break;
				default:
					printf("Enter correct number");
					break;
	
			}
			printf("\nDo you want to order more?(Y/N)");
			another=getche();
			if(another == 'Y' || another == 'y')
			{
				goto start;
			}
			else
			{
				break;
			}
		case '6' :
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
			beverges_choice=getche();
			switch(beverges_choice)
			{
				case '1':
					total_amount=total_amount+120;
					break;
				case '2':
					total_amount=total_amount+130;
					break;
				case '3':
					total_amount=total_amount+100;
					break;
				case '4':
					total_amount=total_amount+100;
					break;
				case '5':
					total_amount=total_amount+90;
					break;
				case '6':
					total_amount=total_amount+110;
					break;
				case '7':
					total_amount=total_amount+50;
					break;
				case '8':
					total_amount=total_amount+50;
					break;
				case '9':
					total_amount=total_amount+40;
					break;
				case '10':
					total_amount=total_amount+60;
					break;
				default:
					printf("Enter correct number");
					break;
			}
			printf("\nDo you want to order more?(Y/N)");
			another=getche();
			if(another == 'Y' || another == 'y')
			{
				goto start;
			}
			else
			{
				break;
			}		
	}
	printf("\nTotal Bill = %d",total_amount);
}
