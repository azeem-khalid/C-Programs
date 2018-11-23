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
	int date,date1,month,mont1,year,year1,guest,rooms;
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
	printf("")
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
	switch(choice)
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
	
	fwrite(&user,sizeof(user),1,fp);
	system("cls");
	printf("\t\t\tBILL\n");
	else

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
			printf("Total Guests : ");
			scanf("%d\n",tot_guest);
			menu();
		case '2' :		
	}
}
void menu()
{
	char another;
	int pak_choice;
	int italian_choice;
	int chinese_choice;
	int fastfood_choice;
	char food_choice ;
	start:
	printf("\n\t\t\t MENU\n");
	printf("1 - Pakistani Food\n2 - Italian\n3 - Chinese & Soups\n4 - Fast Food\n5 - Snacks & Salad\n6 - Beverges\n");
	printf("Enter your choice : ");
	food_choice = getche();
	printf("\n");
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
			
	}
	
}
