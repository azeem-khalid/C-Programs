#include <stdio.h>
#include<stdlib.h>


void push ();
void pop();
void display ();
void search();

int stack[1];
int top = -1;

int main(){

	int element, choice, size;
	printf("enter the element you want to enter: ");
	scanf("%d", &size);
	int *stack = (int*)malloc(sizeof(int)*size);
	system("cls");
	
	while (1)
	    {
	        printf ("-----------------------------------------\n");
	        printf ("1. PUSH\n");
	        printf ("2. POP\n");
	        printf ("3. DISPLAY\n");
	        printf ("4. SEARCH\n");
	        printf ("5. EXIT\n");
	        printf ("------------------------------------------\n");
	
	        printf ("Enter your choice\n");
	        scanf   ("%d", &choice);
	
	        switch (choice)
	        {
	            case 1: push(size);
	                break;
	            case 2: pop();
	                break;
	            case 3: display();
	                getch();
	            case 4: return;
	        }
	        printf("enter any key to continue: ");
	        getch();
			system("cls");	
	}

}

/*Function to add an element to the stack*/
void push(size) {
    int num;

    if (top == (size-1))
    {
        printf ("Error: Overflow\n");
    }
    else
    {
        printf ("Enter the element to be pushed\n");
        scanf ("%d", &num);
        top = top + 1;
        stack[top] = num;
    }
}


/*Function to delete an element from the stack*/
void pop ()
{
    int num;
    if (top == - 1)
    {
        printf ("Error: Stack Empty\n");
    }
    else
    {
        num = stack[top];
        printf ("poped element is = %d\n", num);
        top = top - 1;
    }
}



/*Function to display the status of the stack*/
void display()
{
    int i;
    if (top == -1)
    {
        printf ("Error: Stack Empty\n");
    }
    else
    {
        printf ("\nItems in Stack\n");
        for (i = top; i >= 0; i--)
        {
            printf ("%d\n", stack[i]);
        }
    }
    printf ("\n");
}


