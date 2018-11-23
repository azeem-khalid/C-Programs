#include<stdio.h>
#include<conio.h>
int rm = 3, rc = 3, i, j, m = 0, c = 0, stat = 0, jeet = 0 , z=0;
void display(char pass1, char pass2)
{
  printf("\n");
  
  for (int i = 0; i < m; i++) 
  { 
  printf("M"); 
  } 
  for (int i = 0; i < c; i++) 
  {
      printf("C"); 
  }  
  printf("     _______<BOAT>______");
  for (int i = 0; i < rm; i++) 
  { 
      printf("M");
  } 
  for (int i = 0; i < rc; i++) 
  
  { 
       printf("C");
  }
}
int checkin()
{
	if(c>m && m!=0)
	{
		printf("\nLost\n");
		jeet=-1;
		return jeet;
	}
	if(rc>rm && rm!=0)
	{
		printf("\nlost\n");
		jeet=-1;
		return jeet;
	}
	if(m==3 && c==3)
	{
		printf("\nwon");
		jeet =-1;
		return jeet;
	}
}
void GP(char pass1,char pass2)
{
  if(stat==0)
  {
  	printf("     _______WATER_______<B0AT>(%c,%c)",pass1,pass2);
  if(pass1=='M' && pass2=='M' && rm!=0)
  {rm=rm-2;
  m=m+2;}
  if(pass1=='C' && pass2=='C' && rc!=0)
  {
  rc=rc-2;
  c=c+2;
  }
  if(pass1=='M'&& pass2=='C' && rc!=0 && rm!=0)
  {
  rm=rm-1;
  rc=rc-1;
  m=m+1;
  c=c+1;
  } 
  if(pass1=='C' && pass2==' ' && rc!=0)
  {
  	rc=rc-1;
  	c=c+1;
  }
  if( pass1==' ' && pass2=='C' && rc!=0)
  {
  	rc=rc-1;
  	c=c+1;
  }
  if( pass1=='C' && rc==0)
  {
  	printf("Invalid choice\n");
  	z--;
  }
  if(pass2=='C' && rc==0)
  {
  	printf("Invalid choice\n");
  z--;}
  if(pass1=='M' && rm==0)
  {
  	printf("Invalid choice\n");
  	z--;
  }
  if( pass2=='M' && rm==0)
  {
  	printf("Invalid choice\n");
  	z--;
  }
}
  if(stat==1)
  {
  	printf("     <BOAT>(%c,%c)_______WATER________  ",pass1,pass2);
  if(pass1=='M' && pass2=='M' && m!=0 )
  {m=m-2;
  rm=rm+2;}
  if(pass1=='C' && pass2=='C' && c!=0 )
  {c=c-2;
  rc=rc+2;}
  if(pass1=='M'&& pass2=='C' && c!=0 && m!=0)
  {m=m-1;
  c=c-1;
  rm=rm+1;
  rc=rc+1;}
  if(pass1=='M' && pass2==' ' && m!=0)
  {
  	m=m-1;
  	rm=rm+1;
}
  if(pass1==' ' && pass2=='M' && m!=0)
  {
  	m=m-1;
  	rm=rm+1;
  }
  if(pass1=='C' && pass2==' ' && c!=0)
  {
  	c=c-1;
  	rc=rc+1;
  }
  if( pass1==' ' && pass2=='C' && c!=0)
  {
  	c=c-1;
  	rc=rc+1;
  }
  if( pass1=='C' && c==0)
  {
  	printf("Invalid choice\n");
	z--;
  }
  if( pass2=='C' && c==0)
  {
  	printf("Invalid choice\n");
  z--;}
  if( pass1=='M'  && m==0)
  {
  	printf("Invalid choice\n");
  	z--;
  }
  if(pass2=='M' && m==0)
  {
  printf("Invalid choice\n");
  z--;
  }
}
  printf("\nPress Enter\n");
  getch();
  }
void Game()
{
	do
	{
	if(z%2==0)
	stat=0;
	if(z%2!=0)
	stat=1;
	z++;
	char ch,ch1;
	printf("\nFor missionary= 'M' \nFor cannibal= 'C'\nFor choosing one= 'space'\n");
	fflush(stdin);
	scanf("%c",&ch);
	fflush(stdin);
	scanf("%c",&ch1);
	if(ch==32&& ch1==32)
	z--;
	else
	{
	   GP(ch,ch1);
	   display(ch,ch1);
	}
	jeet=checkin();
    }while(jeet!=-1);	
}
main()
{
	Game();
}

