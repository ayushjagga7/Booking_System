#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <process.h>
#include <conio.h>
#include <windows.h>
#include "ticket.h"

//Global Declared variables
int veg[10] ={25,90,45,55,40,60,80,85,100,50};
int nonveg[10] ={60,30,90,100,110,165,175,120,140};
double total=0;

char Theatre[16][40] = {
    "Cinepolis Unity One   ",
    "PVR Directors Cut   ",
    "Inox Cinema  ",
    "PVR Logix IMAX  ",
    "IMAX BIG Cinemas ",
    "Inox R-City ",
    "Carnival Cinema ",
    "Liberty Cinema ",
    "New Empire Cinema ",
    "Menoka Cinema ",
    "London Paris Multiplex   ",
    "Crown Cinema  ",
    "Cinepolis Multiplex  ",
    "INOX Leisure  ",
    "PVR : Soul Spirit Bellandur  ",
    "Rockline Cinema  "}; //16 Theatre into dimension of the theatre names

char Movies[64][30]={
"Fast and Furious 9  ","Black Widow ","NO tomb to Die ","WW84 ",
"The Invinsible Man  ","Top Gun: Maverick ","TENENT  ","Onward ",
"Blood Shot ","Black Widow  ","WW84  ","No Tomb to Die ",
"The Invinsible Man ","Harley Quinn: Bird of Prey ","Candy Man ","Artemis Foul ",
"Black Widow  ","TENET ","Top Gun: Maverick ","No Tomb to Die  ",
"My SPY ","Free GUY  ","SCOOB!! ","GHOSTBUSTERS",
"TENET ","No Tomb to Die ","WW84 ","Black Widow ",
"Harley Quinn: Bird of Prey  ","Top Gun: Maverick ","No Tomb to Die  ","Artemis Foul ",
"The Invinsible Man  ","Top Gun: Maverick ","TENENT  ","Onward ",
"The Invinsible Man ","Harley Quinn: Bird of Prey ","Candy Man ","Artemis Foul ",
"TENET ","No Tomb to Die ","WW84 ","Black Widow ",
"Fast and Furious 9  ","Black Widow ","NO tomb to Die ","WW84 ",
"The Invinsible Man  ","Top Gun: Maverick ","TENENT  ","Onward ",
"Fast and Furious  ","Rocky  ","3 idiots  ","1971  ",
"My SPY ","Free GUY  ","SCOOB!! ","GHOSTBUSTERS",
"Avengers  ","Iron man  ","Captain America  ","Thor  ",
};  // 64 Movies  into dimensions of the movie names

char concert[8][20] = { "SUNBURN " , "RANG  " , "NH7 " , "SULA FEST " , "GOMAD FEST ", "HOLY COW " , "FIREFLIES " , "STORM " };
char stand_up[8][50] = {"ZAKIR KHAN", "BASSI","ADITI MITTAL","VIR DAS" ,"ATUL KHATRI","ABHISHEK UPMANYU", "KENNY SEBASTIAN","RAHUL SUBRAMANIAM"};

int travel[16]={0,1415,1532,2177,1415,0,2178,989,1532,2178,0,1889,2177,989,1889,0};


void mainmenu(void)
{
	system("cls");
	printf("\t\t\t\t\t#**************************************************************************#\n");
	printf("\t\t\t\t\t#                     WELCOME TO FOOD ORDER SYSTEM                         #\n");
	printf("\t\t\t\t\t#**************************************************************************#\n\n\n");
	foods();

}
void foods()
{

	system("cls");
	printf("\t\t\t\t\t************************************************\n");
    printf("\t\t\t\t\t                    WELCOME                     \n");
    printf("\t\t\t\t\t************************************************\n");
	printf("\t\t\t\t\tYOU ARE--->\n\t\t\t\t\t1. Vegetarian\n\t\t\t\t\t2. Non Vegetarian\n\n\t\t\t\t\tEnter Your Choice: ");
	int type;
	scanf("%d",&type);
	if(type==1)
	{
		system("cls");
		vegetarian();
	}
	else if(type==2)
	{
		system("cls");
	    nonvegetarian();
	}
	else
	{
		printf("\n\t\t\t\t\tWrong Input !Please Re-enter The Correct Option......\n\n");
		foods();
	}
}
void details(int gt)
{
    printf("\n\t\t\t\t\tEnter your Name: ");
    char n[50];
    fflush(stdin);
    gets(n);
    long long phn;
    printf("\t\t\t\t\tEnter your Mobile Number: ");
    scanf("%lld",&phn);
    char add[500];
    printf("\t\t\t\t\tEnter your Address: ");
    fflush(stdin);
    gets(add);
    FILE *fp1 = fopen("bill.txt","a");
    fprintf(fp1,"Name-> %s\nMobile-> %lld\nAddress-> %s\nGrand Total-> %d\n",n,phn,add,gt);
    fputs("--------------------------------------------------------------------------------------------------\n",fp1);
    fclose(fp1);
}
void vegetarian(void)
{
	int choice;
	int again;
	int quantity;
    printf("\n\t\t\t\t *********************************************\n");
	printf(  "\t\t\t\t                  Veg. Menu\n");
	printf(  "\t\t\t\t *********************************************\n");
	char v;
	FILE *vmenu;

    vmenu=fopen("veg.txt","r");
	while((v=getc(vmenu))!=EOF)
        {
        	printf("%c",v);
		}
         fclose(vmenu);
    printf("\n\n\t\t\t\t\tEnter What You Want :");
	scanf("%d",&choice);
	if(choice>=1&&choice<=10)
	{
		printf("\t\t\t\t\tQuantity :  ");
		scanf("%d",&quantity);
		total=total + veg[choice-1]*(quantity);
		printf("\n\t\t\t\t\tPress 1 To Order Again :\n\t\t\t\t\tPress 2 To Get Your Total:\n\n\t\t\t\t\tEnter Your Choice :");
		scanf("%d",&again);
		printf("\n");
		if(again==1)
		{
			printf("\n\n");
			vegetarian();
		}
		else if(again==2)
		{
			printf("\n\t\t\t\t\tYour Total Amount Is : Rs. %.2lf\n\n",total);
            int z;

            int gtotal = total;
            details(gtotal);
            printf("\n\t\t\t\t\tPRESS any key to proceed: ");
            getch();
            total = 0;
		}
	}
	else if(choice==11)
	{
		//system("cls");
		foods();
	}
	else
	{
		printf("Wrong Input! Re-enter THe Correct Option\n\n");
		vegetarian();
	}
}
void nonvegetarian(void)
{
	int choice;
	int again;
	int quantity;
	printf("\n\t\t\t\t *********************************************\n");
	printf(  "\t\t\t\t               Non Veg. Menu\n");
	printf(  "\t\t\t\t *********************************************\n");
    char n;
	FILE *nmenu;
	nmenu = fopen("nonveg.txt","rt");
	while((n=getc(nmenu))!=EOF)
	{
		printf("%c",n);
	}
	printf("\n\n\t\t\t\t\tEnter What You Want :");
	scanf("%d",&choice);
	if(choice>=1&&choice<=10)
	{
		printf("\n\t\t\t\t\tQuantity : ");
		scanf(" %d",&quantity);
		total=total + nonveg[choice-1]*(quantity);
		printf("\n\t\t\t\t\tPress 1 To Order Again :\n\t\t\t\t\tPress 2 To Get Your Total:\n\n\t\t\t\t\tEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n\t\t\t\t\t");
			nonvegetarian();
		}
		else if(again==2)
		{
			printf("\n\t\t\t\t\tYour Total Amount Is :%.2lf\n\n",total);
			//int totl = total;
            int z;
            int gtotal = total;
			FILE *fp6;

            fp6 = fopen("bill.txt","a");
			fprintf(fp6,"Grand Total : %d\n",gtotal);
			fclose(fp6);
            printf("\n\t\t\t\t\tPress any key to proceed: ");
            getch();

            total = 0;
        }
	}
	else if(choice==11)
	{
		//system("cls");
		foods();
	}
	else
	{
		printf("\n\t\t\t\t\tWrong Input! Re-enter THe Correct Option\n\n");
		nonvegetarian();
	}
}
int Isempty(node **ahead)
{
    if (*ahead == NULL)
        return 1;
    return 0;
}

int isempty(city **ahead)
{
    if (*ahead == NULL)
        return 1;
    return 0;
}

void add_node(node **ahead)
{
    if (!Isempty(ahead))
    {
        node *tmp = (node *)malloc(sizeof(node));
        tmp->next = NULL;
        node *crt = *ahead;
        while (crt->next != NULL)
        {
            crt = crt->next;
        }
        crt->next = tmp;
    }
    else
    {
        node *tmp = (node *)malloc(sizeof(node));
        tmp->next = NULL;
        *ahead = tmp;
    }
}


void add_city(city **ahead)
{
    if (!isempty(ahead))
    {
        city *tmp = (city *)malloc(sizeof(city));
        tmp->next = NULL;
        city *crt = *ahead;
        while (crt->next != NULL)
        {
            crt = crt->next;
        }
        crt->next = tmp;
    }
    else
    {
        city *tmp = (city *)malloc(sizeof(city));
        tmp->next = NULL;
        *ahead = tmp;
    }
}

void display(int st)
{
    FILE *fp1;
    fp1 = fopen("project.txt", "r");
    int i = 0;
    char c[100];
    if (st == 0)
    {
        fscanf(fp1, "%[^\n]", c);
        printf("\t\t\t\t\t\t");
        printf("%s", c);
    }

    else
    {
        while (fgets(c, sizeof(c), fp1))
        {
            if (i == st)
            {
                printf("%s", c);
            }

            i++;
        }
    }
    fclose(fp1);
}

void addcitiesname(city **a_cities)
{
    city *crt = *a_cities;
    FILE *fp1;
    fp1 = fopen("project.txt", "a");

    fputs(strcpy(crt->city, "1. Delhi"), fp1);
    fputs("  ", fp1);
    fputs(strcpy(crt->next->city, "2. Mumbai"), fp1);
    fputs("  ", fp1);
    fputs(strcpy(crt->next->next->city, "3. Kolkata"), fp1);
    fputs("  ", fp1);
    fputs(strcpy(crt->next->next->next->city, "4. Banglore"), fp1);
    fputs("\n", fp1);
    fclose(fp1);
}

//j=0,4,8,12
void addTheatre(node **a_theaters, city *a_city, int j)
{
    FILE *fp1;
    fp1 = fopen("project.txt", "a");

    city *tmp = a_city;
    node *crt = *a_theaters;
    for (int i = 0; i < j / 4; i++)
    {
        tmp = tmp->next;
    }
    tmp->event_1 = (*a_theaters);
    int k=0;
    for (int i = 1 + j; i <= 4 + j; i++)
    {
        fprintf(fp1,"%d. ",++k);
        fputs(strcpy(crt->city, Theatre[i - 1]), fp1);
        crt = crt->next;
    }
    fputs("\n", fp1);
    fclose(fp1);
}
void adddistances()
{
    FILE *fp1;
    fp1 = fopen("distances.txt", "a");
    for(int i=0;i<16;i++)
    {
            fprintf(fp1,"%d\n",travel[i]);
    }
    fclose(fp1);
}

int telldistance(int i,int j)
{
    int t[16];
    int k=0,n,sn;

    FILE *fp2= fopen("distances.txt", "r");
    //fseek(fp2 , 0 , SEEK_SET);
    for(k=0; k<16; k++)
      fscanf(fp2 , "%d" , &t[k]);
    fclose(fp2);
    return t[(i-1)*4+(j-1)];

}

void addMovies(node *theater, node *a_movies[], int num)
{
    FILE *fp1;
    fp1 = fopen("project.txt","a");

    for(int i = 0; i<4; i++)
    {
        node * crt = (node *)malloc(sizeof(node));
        add_node(&crt);add_node(&crt);add_node(&crt);

        a_movies[i] = crt;
        int z;
        if(num==0) z=0;
        else if(num==1) z=16;
        else if(num==2) z=32;
        else z=48;
        int k=0;
        for(int j=4*i+z;j<4*(i+1)+z;j++)
         {
            fprintf(fp1,"%d. ",++k);
            fputs(strcpy(crt->city,Movies[j]),fp1);
            crt=crt->next;
         }
        fputs("\n",fp1);
    }

    theater->down = *a_movies;  //linking
    fclose(fp1);
}

void addconcert(node **a_concert, city *a_city, int j)
{
    FILE *fp1;
    fp1 = fopen("project.txt","a");
    city *tmp = a_city;
    node *crt = *a_concert;

    for(int i = 0; i < j ; i++)
    {
        tmp = tmp->next;
    }

     tmp->event_2 = (*a_concert);

    for(int i = 0; i<2; i++)
    {
        fprintf(fp1,"%d. ",i+1);
        fputs(strcpy(crt->city,concert[j*2 +i]),fp1);
        fputs("  ",fp1);

        crt = crt->next;
    }
    fputs("\n",fp1);
    fclose(fp1);
}

void addstandup(node **a_concert, city *a_city, int j)
{
    FILE *fp1;
    fp1 = fopen("project.txt","a");
    city *tmp = a_city;
    node *crt = *a_concert;

    for(int i = 0; i < j ; i++)
    {
        tmp = tmp->next;
    }

     tmp->event_3 = (*a_concert);

    for(int i = 0; i<2; i++)
    {
        fprintf(fp1,"%d. ",i+1);
        fputs(strcpy(crt->city,stand_up[j*2+i]),fp1);
        fputs("  ",fp1);

        crt = crt->next;
    }
    fputs("\n",fp1);
    fclose(fp1);
}

void display_seats(int a[] , int n)
{
  int j=1;
   printf("\n\t\t\t\t\t");
   printf("    \t\tS\tC\tR\tE\tE\tN\n\n");
   printf("\t\t\t\t\t\t");
   printf("  ---------------------- S I L V E R -------------------------\n");
   printf("\t\t\t\t\t");
    for(int i=1; i <= 30 ; i++)
    {
      if( a[i] == 1)
        printf("NA\t");
      else
        printf("%d\t", i);
      if(i%10 == 0)
        printf("\n\t\t\t\t\t");
    }
    printf("\t  ------------------------ G O L D -----------------------\n");
    printf("\t\t\t\t\t");
    for(int i=31; i <= 70 ; i++)
    {
      if( a[i] == 1)
        printf("NA\t");
      else
        printf("%d\t", i);
      if(i%10 == 0)
        printf("\n\t\t\t\t\t");
    }
    printf("  \t------------------- P L A T I N U M -------------------\n");
    printf("\t\t\t\t\t");
    for(int i=71; i <= 100 ; i++)
    {
      if( a[i] == 1)
        printf("NA\t");
      else
        printf("%d\t", i);
      if(i%10 == 0)
        printf("\n\t\t\t\t\t");
    }
}

void pay_bill(int c , int t , int m , int n, int s[])
{
   system("cls");
   int rate=0, bill=0;
   printf("\n\t\t\t\t\t***********************  %s**************************",Theatre[4*(c-1)+(t-1)]);
   SYSTEMTIME time;
   GetSystemTime(&time);
   printf("\n\t\t\t\t\tDate: %d/%d/%d                                        Time: %d::%d\n",time.wDay,time.wMonth,time.wYear,time.wHour,time.wMinute);
   printf("\n\t\t\t\t\t MOvie:      \t %s                  (U/A)     ",Movies[ 4*(c-1) + 4*(t-1) + (m-1)]);
   printf("\n\t\t\t\t\t                                                        Rate");
   for(int i=0;i<n;i++)
   {
     if(s[i]<=30)
       rate = 100;
     else if(s[i]<=70 && s[i]>30)
       rate = 200;
     else
       rate = 300;
    bill+=rate;
    printf("\n\t\t\t\t\t Seat: %d                                                %d",s[i],rate);
   }
   printf("\n\t\t\t\t\t--------------------------------------------------------------------");
   printf("\n\t\t\t\t\t                                              Total:     %d",bill);
   printf("\n\t\t\t\t\t--------------------------------------------------------------------");
   printf("\n\n\t\t\t\t\t                      Enjoy your Movie                            ");
   printf("\n\t\t\t\t\t***********************  %s**************************",Theatre[4*(c-1)+(t-1)]);
   int a;
   printf("\n\n\t\t\t\t\tPRESS ENTER to Confirm: ");
   getch();
   printf("\n");
}

int book_tickets(int line,int c,int t,int m)
{
    int a[101];
    int i=0,n,sn;
    int count=0;
    FILE *seats = fopen("seats.txt", "r");
    fseek(seats , line , SEEK_SET);
    for(i=1; i<101; i++)
    { fscanf(seats , "%d" , &a[i]); if(a[i] == 0){count++;}}
    fclose(seats);
    if(count == 0)
    { return 0;}
    printf("\n\t\t\t\t\tNo. of Seats Available: %d\n",count);
    printf("\t\t\t\t\tNumber of Seats you want to book : ");
    scanf("%d", &n);
    if( sn > count )
    {
        do{
            printf("\n\t\t\t\t\tSorry!!! We have only %d seats left\n",count);
            printf("\t\t\t\t\tPRESS 1 to continue booking: ");
            scanf("%d",&i);
            if(i==1)
               break;
            else
            {
              printf("\t\t\t\t\tNumber of Seats you want to book : ");
              scanf("%d", &n);
            }
        }while(sn > count);
    }
    system("cls");
    display_seats(a,101);
    printf("\n\t\t\t\t\t\tSilver: Rs. 100      Gold: Rs. 200      Platinum: Rs. 300 ");
    int s[n];
    for(i=0;i<n;i++)
    {
        printf("\n\t\t\t\t\t");
        printf("Enter Seat Number : ");
        scanf("%d", &sn);
        if(a[sn] == 1)
          {
            do
            {
              printf("\n\t\t\t\t\tAlready Booked..you may choose another seat");
              printf("\n\t\t\t\t\tEnter Seat Number : ");
              scanf("%d", &sn);
            }while(a[sn] == 1);
          }
        a[sn] = 1;
        s[i]=sn;
        FILE *seats = fopen("seats.txt", "r+");
        fseek(seats , line + (sn-1)*3 , SEEK_SET);
        fprintf(seats , "1");
        fclose(seats);
    }
   pay_bill(c,t,m,n,s);
   printf("\n\t\t\t\t\t");
   printf("You may confirm your booked seats :: \n");
   display_seats(a,101);
   printf("\n\t\t\t\t\tPress any key to proceed: ");
   getch();
   return 1;
}

void passes(int n, int c , int r , int sl , int line)
{
   int k;
     if(line <= 6408 )
     {
         printf("\n\t\t\t\t\t1 Ticket = Rs.999");
         printf("\n\t\t\t\t\tPayable Amnt: Rs.%d/-",n*999);
         printf("\n\n\t\t\t\t\tPRESS 1 to get your tickets: ");
         scanf("%d",&k);
         k= 5000-sl;
         printf("\n\n\t\t\t\t\tSerial Number of passes are: \n");
         for(int i=0;i<n;i++)
          {printf("\n\t\t\t\t\t2020%c%c%c%d",concert[2*(c-1) + (r-1)][0],concert[2*(c-1) + (r-1)][1],concert[2*(c-1) + (r-1)][2],k++);}
     }
    if(line > 6408)
    {
      printf("\n\n\t\t\t\t\t1 Ticket = Rs.499/-");
      printf("\n\t\t\t\t\tPayable Amnt: Rs. %d/-",n*499);
      printf("\n\t\t\t\t\tPRESS 1 to get your Tickets: ");
      scanf("\n\t\t\t\t\t%d",&k);
      k = 150 - sl;
      for(int i=0;i<n;i++)
      printf("\n\t\t\t\t\t2020%c%c%c%d",stand_up[2*(c-1) + (r-1)][0],stand_up[2*(c-1) + (r-1)][1],stand_up[2*(c-1) + (r-1)][2],k++);
    }
}

int book_pass(int line, int pa ,int city , int m)
{
    FILE *fp1 = fopen("seats.txt", "r");
    FILE *tmp = fopen("temp.txt","w");

    int count = 0;
    char c[100];
    int a = 0;

    while (fgets(c, sizeof(c), fp1))
    {
        count++;

        if (count == line)
            {
                //printf("%s", c);
                a = atoi(c);
                for(int i=0; i<pa; i++)
                {
                    if(a<100)
                    {
                        a++;
                    }
                    else
                    {
                        printf("\n\t\t\t\t\tTickets Sold Out\n");
                    }

                }
               if(a<=100)
                { printf("\t\t\t\t\t\tSeats booked = %d ",a);
                fprintf(tmp,"%d\n",a);
                printf("\n\t\t\t\t\tThanks for booking ");}
            }
        else
        {
            fputs(c,tmp);
        }
    }
    fclose(fp1);
    fclose(tmp);


   remove("seats.txt");
   rename("temp.txt","seats.txt");
    if(a>=100){return 1;}
   else
    passes(pa,city,m,a,line);
}

void edit_movies()
{
   printf("\n\t");
   display(0);
   printf("\n\t\t\t\t\tCity: ");
   int c;
   scanf("%d",&c);

   int t;
   printf("\n\t\t\t\t\t");
   display(c);
   printf("\n\t\t\t\t\tTheater: ");
   scanf("%d",&t);

   int m;
   printf("\n\t\t\t\t\t");
   display(4*c +t);
   printf("\n\t\t\t\t\tMovie: ");
   scanf("%d",&m);

   FILE *fp1 = fopen("seats.txt","r+");
   int line = (c-1)*4800 + (t-1)*1200 + (m-1)*300;
   fseek(fp1,line,SEEK_SET);
   printf("\t\t\t%d",line);

   for(int i=1;i<101;i++)
   {fprintf(fp1,"0\n");fseek(fp1,line+3*i,SEEK_SET);}
   fclose(fp1);

   fp1 = fopen("seat.txt","r");
   int a[101];
   fseek(fp1, line , SEEK_SET);
    for(int i=1; i<101; i++)
      fscanf(fp1 , "%d" , &a[i]);
    fclose(fp1);
   display_seats(a,101);
}

void edit_concert()
{
    printf("\n\t");
   display(0);
   printf("\n\t\t\t\t\tCity: ");
   int ch;
   scanf("%d",&ch);

   int t;
   printf("\n\t\t\t\t\t");
   display(ch+20);
   printf("\n\t\t\t\t\t Concert: ");
   scanf("%d",&t);
   t = 6400+2*(ch-1)+t;

     FILE *fp1 = fopen("seats.txt", "r");
    FILE *tmp = fopen("temp.txt","w");

    int count = 0;
    char c[100];


    while (fgets(c, sizeof(c), fp1))
    {
        count++;

        if (count == t)
            {
                printf("%s", c);
                fputs("0\n",tmp);
            }
        else
        {
            fputs(c,tmp);
        }

    }
    fclose(fp1);
    fclose(tmp);
    remove("seats.txt");
   rename("temp.txt","seats.txt");

}

void edit_standup()
{
    printf("\n\t");
   display(0);
   printf("\n\t\t\t\t\tCity: ");
   int ch;
   scanf("%d",&ch);

   int t;
   printf("\n\t\t\t\t\t");
   display(ch+24);
   printf("\n\t\t\t\t\t Show : ");
   scanf("%d",&t);
   t = 6408 +t+ 2*(ch-1);

     FILE *fp1 = fopen("seats.txt", "r");
    FILE *tmp = fopen("temp.txt","w");

    int count = 0;
    char c[100];


    while (fgets(c, sizeof(c), fp1))
    {
        count++;

        if (count == t)
            {
                printf("%s", c);
                fputs("0\n",tmp);
            }
        else
        {
            fputs(c,tmp);
        }

    }
    fclose(fp1);
    fclose(tmp);
    remove("seats.txt");
   rename("temp.txt","seats.txt");

}


