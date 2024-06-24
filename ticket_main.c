#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ticket.c"

void main()
{

//	int *seat=(int *)calloc(101,sizeof(int ));
    int source=0;
    int destination=0;
    int distance=0;
    int option=0;;
    FILE *fp;
    int flag = 0;
    fp = fopen("project.txt", "r");
    int choosevehicle=0;
    if (fp == NULL)
        flag = 1;

    if (flag == 1) // first time opening the file
    {
        printf("opening the file first time \n");

        city *cities = NULL;
        node *d_theaters = NULL;
        node *m_theaters = NULL;
        node *k_theaters = NULL;
        node *b_theaters = NULL;

        node *d_concert = NULL;
        node *k_concert = NULL;
        node *m_concert = NULL;
        node *b_concert = NULL;

        node *d_stand = NULL;
        node *m_stand = NULL;
        node *k_stand = NULL;
        node *b_stand = NULL;

        node *d_movies[4];
        node *m_movies[4];
        node *k_movies[4];
        node *b_movies[4];

        for (int j = 0; j < 4; j++)
        {
            add_city(&cities);
            add_node(&d_theaters);
            add_node(&m_theaters);
            add_node(&k_theaters);
            add_node(&b_theaters);
        }

        for(int j=0; j<2; j++)
        {
            add_node(&d_concert);
            add_node(&m_concert);
            add_node(&k_concert);
            add_node(&b_concert);

            add_node(&d_stand);
            add_node(&m_stand);
            add_node(&k_stand);
            add_node(&b_stand);
        }

        addcitiesname(&cities);

        addTheatre(&d_theaters, cities, 0);
        addTheatre(&m_theaters, cities, 4);
        addTheatre(&k_theaters, cities, 8);
        addTheatre(&b_theaters, cities, 12);

        addMovies(d_theaters,d_movies,0);
        addMovies(m_theaters,m_movies,1);
        addMovies(k_theaters,k_movies,2);
        addMovies(b_theaters,b_movies,3);

        addconcert(&d_concert, cities, 0);
        addconcert(&m_concert, cities, 1);
        addconcert(&k_concert, cities, 2);
        addconcert(&b_concert, cities, 3);

        addstandup(&d_stand, cities, 0);
        addstandup(&m_stand, cities, 1);
        addstandup(&k_stand, cities, 2);
        addstandup(&b_stand, cities, 3);

        FILE *seat = fopen("seats.txt", "w");
        for(int i = 0; i<6400; i++)
        fprintf(seat,"0\n");

        for( int i = 6400; i < 6416; i++)
        fprintf(seat, "\n");
        fclose(seat);
        FILE *fp1;
        int flag = 0;
        fp1 = fopen("distances.txt", "r");

        if (fp1 == NULL)
            flag = 1;

        if (flag == 1) // first time opening the file
        {
            adddistances();
        }

    }


   do
{
    int op;
    char id[20], pass[4],ch;
    printf("\n\n\t\t\t\t\t************************ WELCOME to BOOKING SYSTEM  ***********************\n");
    printf("\n\t\t\t\t\t\tYOU ARE?");
    printf("\n\t\t\t\t\t\t1. ADMIN");
    printf("\n\t\t\t\t\t\t2. USER");
    printf("\n\t\t\t\t\t\t3. WANTS TO EXIT");
    printf("\n\n\t\t\t\t\t\t ENTER OPTION : ");
    scanf("%d",&op);
    printf("\n\t\t\t\t\t**************************************************************************");

    if(op == 1)
    {
        printf("\n\t\t\t\t\tADMIN ID    : ");
        scanf("%s",&id);
        if( strcmp(id,"admin") != 0)
        {
            do{
              printf("\t\t\t\t\tUNREGISTERED ID!!!!\n\t\t\t\t\t\n");
              printf("\n\t\t\t\t\tADMIN ID    : ");
              scanf("%s",&id);
            }while(strcmp(id,"admin"));
        }
        if(strcmp(id,"admin")==0)
        {

         char password[55];

         printf("\n\t\t\t\t\tPASSWORD    : ");
         int p=0;
         do{
            password[p]=getch();
            if(password[p] != '\r')
            {
                printf("*");
            }
             p++;
            }while(password[p-1]!='\r');
            password[p-1]='\0';

            if(strcmp(password,"pass") != 0)
            {
                printf("\n\t\t\t\t\tAccess DENIED!!!\n");
                main();
            }

            if(strcmp(password,"pass")==0)
            {
                system("cls");
                printf("\n\t\t\t\t\t*************************  WELCOME ADMIN ************************\n\n");
            }

        }

        // ****************** ADMIN *************** //
        op = 0;
        printf("\n\t\t\t\t\t1. Edit Movies ");
        printf("\n\t\t\t\t\t2. Edit Concert ");
        printf("\n\t\t\t\t\t3. Edit Stand-up ");
        printf("\n\t\t\t\t\t4. Exit the program ");
        printf("\n\n\t\t\t\t\tEnter option : ");
        scanf("%d",&op);
        printf("\n\t\t\t\t\t*************************************************************");
        switch(op)
        {
            case 1 : edit_movies();
                     break;
            case 2 : edit_concert();
                     break;
            case 3 : edit_standup();
                     break;
            case 4 : printf("n\t\t\t\t\tExiting.....");
                     exit(0);
        }

    }



    //***************** USER MENU **************************//
    else if (op== 2)
{
    system("cls");
    do{
            system("cls");
        int searchchoice = 0,choice =0;
        printf("\n\n\t\t\t\t\t************************ WELCOME to ONLINE BOOKING SYSTEM ***********************\n");
        printf("    \t\t\t\t\t@   1. EVENTS BOOKING                                                           @\n");
        printf("    \t\t\t\t\t@   2. INTER - CITY CAB BOOKING                                                 @\n");
        printf("    \t\t\t\t\t@   3. RESTAURANT ORDERING                                                      @\n");
        printf("    \t\t\t\t\t*^*^**^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*\n");
        printf(    "\n\t\t\t\t\t\tENTER - ");
        scanf("%d", &choice);

       if(choice == 1)
     {
        system("cls");
        printf("\n\n\t\t\t\t\t^*^**^*^*^*^*^*^*^*^*^*^*EVENT BOOKING SYSTEM*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*\n");
        printf(    "\t\t\t\t\t@                                                                               @\n");
        printf(    "\t\t\t\t\t@                1. Display all the cities available                            @\n");
        printf(    "\t\t\t\t\t@                2. Exit the program                                            @\n");
        printf(    "\t\t\t\t\t@                                                                               @\n");
        printf(    "\t\t\t\t\t^*^**^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*\n");
        printf(    "\n\t\t\t\t\t\tENTER - ");
        scanf("%d", &searchchoice);

        if( searchchoice == 2)
           {printf("\n\n                                                                    ......exiting");  exit(0);}

        int c;
        int line=0;
        flag = 0;
        if (searchchoice == 1)
        {
            display(0);
            printf("\n\n\t\t\t\t\t");
            printf("Enter city of choice: ");
            scanf("%d",&c);


            if(c>4 || c<0)
            {
                do{
                printf("\n\t\t\t\t\tPlease Enter from cities shown above");
                printf("\n\t\t\t\t\tEnter city Again: ");
                scanf("%d",&c);
                flag = 0;}while(c>4 || c<0);
            }
            else
            {
                printf("\n\t\t\t\t\t\t@   1. Movies");
                printf("\n\t\t\t\t\t\t@   2. Concerts");
                printf("\n\t\t\t\t\t\t@   3. Stand-up Comedy");
                printf("\n\t\t\t\t\tEnter your choice: ");
                scanf("%d",&flag);
            }
        }

                 //************* movies **************//
        if (flag == 1)
        {
              printf("\n\t\t\t\t\tTheaters Available with us ::");
            if (c ==1 )
                {printf("\n\t\t\t\t\t");display(1); line=0; }

            else if (c == 2)
                {printf("\n\t\t\t\t\t");display(2); line=4800; }

            else if (c == 3)
                {printf("\n\t\t\t\t\t");display(3); line=9600; }

            else if (c == 4)
                {printf("\n\t\t\t\t\t");display(4);line=14400;}

            printf("\n\t\t\t\t\t");
            printf("Enter theater number: ");
            int t;
            scanf("%d", &t);
            line+=(t-1)*1200;
            printf("\n\t\t\t\t\t");
            printf("Movies Showing ::");
            printf("\n");

            if (c ==1 )
                {printf("\t\t\t\t\t");display(4 + t);}

            else if (c == 2)
                {printf("\t\t\t\t\t");display(8 + t);}

            else if (c == 3)
                {printf("\t\t\t\t\t");display(12 + t);}

            else if (c == 4)
                {printf("\t\t\t\t\t");display(16 + t);}


            //Booking of Ticket
            printf("\t\t\t\t\t");
            printf("Enter movie ::  ");
            int m;
            scanf("%d",&m);
            line+=(m-1)*300;


            int result = book_tickets(line,c,t,m);
            if(result == 1)
              printf("\n\n\t\t\t\t\t\t\t\t\tTHANK YOU!! for booking\n\n\n\n");
            else
              printf("\n\t\t\t\t\tHousefull!!!");
        }


        //**************** Concert ************************//
        if(flag==2)
        {
            printf("\n\t\t\t\t\tConcert Available with us ::");
             if (c ==1 )
                {  printf("\n\t\t\t\t\t");display(21); line = 6400 ;  }

            else if (c ==2 )
                {  printf("\n\t\t\t\t\t");display(22); line=6402; }
            else if (c ==3 )
                {  printf("\n\t\t\t\t\t");display(23); line=6404;   }

            else if (c==4 )
                {  printf("\n\t\t\t\t\t"); display(24); line=6406;  }

            //Booking of Passes
            printf("\t\t\t\t\t");
            printf("Enter Concert ::  ");
            int m;
            scanf("%d",&m);
            printf("\n\t\t\t\t\tEnter no. of passes you wish to book ::  ");
            int pa = 0;
            scanf("%d",&pa);
            line+=m;
            book_pass(line,pa,c,m);
        }

        //****************  Stand up comedy ************//
        if(flag == 3)
        {
            printf("\n\t\t\t\t\tShows Available ::");
             if (c == 1)
                {  printf("\n\t\t\t\t\t");display(25);  line=6408;
                }

            else if (c ==2)
                {  printf("\n\t\t\t\t\t");display(26);  line=6410;
                 }

            else if (c ==3 )
                {  printf("\n\t\t\t\t\t");display(27);  line=6412;
                   }

            else if ( c == 4)
                {  printf("\n\t\t\t\t\t"); display(28);  line=6414;
                 }

            //Booking of Passes
            printf("\t\t\t\t\t");
            printf("Enter Show ::  ");
            int m;
            scanf("%d",&m);
            int pa = 0;
            printf("\n\t\t\t\t\tEnter no. of passes you wish to book ::  ");
            scanf("%d",&pa);
            line+=m;
            book_pass(line,pa,c,m);
        }

     }
        else if (choice == 2 )
        {
          do
          {
            system("cls");
            printf("\n\t\t\t\t\t*****************INTER-STATE CAB BOOKING SYSTEM *************************");
            printf("\n\n\t\t\t\t\tENTER THE SOURCE AMONG THE FOLLOWING CITIES: \n\t\t\t\t\t1. Delhi 2. Mumbai 3. Kolkata 4. Banglore\n\t\t\t\t\tSOURCE: ");
            scanf("%d",&source);
            printf("\n\n\t\t\t\t\tENTER THE DESTINATION AMONG THE FOLLOWING CITIES: \n\t\t\t\t\t1. Delhi 2. Mumbai 3. Kolkata 4. Banglore\n\t\t\t\t\tDESTINATION: ");
            scanf("%d",&destination);
            distance=telldistance(source,destination);
            //printf("%d",distance);
            char ch = 'n' ;
            if(distance==0)
            {
                printf("\n\t\t\t\t\t ERROR : Source and Destination can't be same");
                printf("\n\t\t\t\t\t Do you wish to enter again (y/n) ");
                scanf("%c",&ch);
                getch();
            }

          }while(ch== 'y');
            if(distance != 0)
            {
                printf("\n\n\t\tCHOOSE VEHILE TO TRAVEL \n\t\t1. Uber X -8 Rs/km (Seats 1-4 people and is curb to curb service)\n\t\t2. Uber XL -12Rs/Km (Seats 1-6 people also curb to curb)\n\t\t3. Uber sedan -16 Rs/km (Seats 1-4 people and is curb to curb service.These are premium rides in higher end cars)\n\t\t4. Uber LUXURY -40 Rs/km (Seats 1-4 people and is curb to curb service.These are lucurious rides in top model cars)\n\t\t5. Uber SUV -25 Rs/km (Seats 1-6 people and is curb to curb service.These are premium rides in higher end cars)\n\t\t\t\t\tCHOOSE: ");
                scanf("%d",&choosevehicle);
                if(choosevehicle==1)
                {
                    printf("\n\t\t\t\t\tYOUR PRICE WILL BE = %d",8*distance);
                    printf("\n\t\t\t\t\tENTER 1 TO BOOK: ");
                    scanf("%d",&option);
                    printf("\n");
                    if (option==1)
                    {
                        printf("\n\t\t\t\t\t YOUR UBER X HAVE BEEN BOOKED FOR DISTANCE = %d AT FARE = 8 Rs/Km",distance);
                        printf("\n\t\t\t\t\t PRICE SUMMARY = 8 X %d = %d",distance,distance*8);
                    }
                    printf("\n\t\t\t\t\tENTER ANYKEY TO RETURN TO MAIN MENU: ");
                    getch();
                }
                if(choosevehicle==2)
                {
                    printf("\n\t\t\t\t\tYOUR PRICE WILL BE = %d",12*distance);
                    printf("\n\t\t\t\t\tENTER 1 TO BOOK: ");
                    scanf("%d",&option);
                    if (option==1)
                    {
                        printf("\n\t\t\t\t\tYOUR UBER XL HAVE BEEN BOOKED FOR DISTANCE = %d AT FARE = 12 Rs/Km",distance);
                        printf("\n\t\t\t\t\tPRICE SUMMARY = 12 X %d = %d",distance,distance*12);
                    }
                    printf("\n\t\t\t\t\tENTER ANY KEY TO RETURN TO MAIN MENU: ");
                    getch();
                }
                if(choosevehicle==3)
                {
                    printf("\n\t\t\t\t\tYOUR PRICE WILL BE = %d",16*distance);
                    printf("\n\t\t\t\t\tENTER 1 TO BOOK: ");
                    scanf("%d",&option);
                    if (option==1)
                    {
                        printf("\n\t\t\t\t\tYOUR UBER SEDAN HAVE BEEN BOOKED FOR DISTANCE = %d AT FARE = 16 Rs/Km",distance);
                        printf("\n\t\t\t\t\tPRICE SUMMARY = 16 X %d = %d",distance,distance*16);
                    }
                    printf("\n\t\t\t\t\tENTER ANY KEY TO RETURN TO MAIN MENU: ");
                    getch();
                }
                if(choosevehicle==4)
                {
                    printf("\n\t\t\t\t\tYOUR PRICE WILL BE = %d",40*distance);
                    printf("\n\t\t\t\t\tENTER 1 TO BOOK: ");
                    scanf("%d",&option);
                    if (option==1)
                    {
                        printf("\n\t\t\t\t\tYOUR UBER LUXURY HAVE BEEN BOOKED FOR DISTANCE = %d AT FARE = 40 Rs/Km",distance);
                        printf("\n\t\t\t\t\tPRICE SUMMARY = 40 X %d = %d",distance,distance*40);
                    }
                    printf("\n\t\t\t\t\tENTER ANY KEY TO RETURN TO MAIN MENU: ");
                    getch();
                }
                if(choosevehicle==5)
                {
                    printf("\n\t\t\t\t\tYOUR PRICE WILL BE = %d",25*distance);
                    printf("\n\t\t\t\t\tENTER 1 TO BOOK: ");
                    scanf("%d",&option);
                    if (option==1)
                    {
                        printf("\n\t\t\t\t\tYOUR UBER SUV HAVE BEEN BOOKED FOR DISTANCE = %d AT FARE = 25 Rs/Km",distance);
                        printf("\n\t\t\t\t\tPRICE SUMMARY = 25 X %d = %d",distance,distance*25);
                    }
                    printf("\n\t\t\t\t\tENTER ANY KEY TO RETURN TO MAIN MENU: ");
                    getch();
                }

            }

        }
        else if(choice == 3)
        {
            mainmenu();
        }

    }while(flag==0);

}

else
{
    printf("\t\t\tEXITING....");
    exit(0);
}
printf("\n\t\t\t\t\tPRESS Any Key to Proceed ");
getch();
system("cls");
}while(1);
}
