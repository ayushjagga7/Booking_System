typedef struct node
{
    char city[40];
    struct node *next;
    struct node *down;
} node;


typedef struct city
{
    char city[40];
    struct city *next;
    struct node *event_1;
    struct node *event_2;
    struct node *event_3;
}city;

void details();
void mainmenu(void);
void foods();
void vegetarian(void);
void nonvegetarian(void);
void add_node(node **ahead);
void add_city(city **ahead);
void display(int st);
void addcitiesname(city **a_cities);
void addTheatre(node **a_theaters, city *a_city, int j);
void adddistances();
int telldistance(int i,int j);
void addMovies(node *theater, node *a_movies[], int num);
void addconcert(node **a_concert, city *a_city, int j);
void addstandup(node **a_concert, city *a_city, int j);
void display_seats(int a[] , int n);
void pay_bill(int c , int t , int m , int n, int s[]);
int book_tickets(int line,int c,int t,int m);
void passes(int n, int c , int r , int sl , int line);
int book_pass(int line, int pa ,int city , int m);
void edit_movies();
void edit_concert();
void edit_standup();



