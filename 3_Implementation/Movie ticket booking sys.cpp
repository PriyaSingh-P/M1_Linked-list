/*
Movie ticket bokking


*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct book
{
	char code[20];
	char name[20];
	char date[20];
	int cost;
	

}b;

int seat = 60 ;

void insertDetails();//for inserting movie details
void view_all(); // for view all data 
void Find(); // for finding data
void bookTicket(); //for booking tickets
void oldRecord(); //for view old recorrds of users,booked tickets

int main()
{

	 int p;
 	do{
	printf("\n====================================================================");
	printf("\n");	
	printf("\t Moive Ticket booking ");
	printf("\n");
	printf("\n====================================================================");
	
	printf("\nPress <1> Insert Movie");
   	printf("\nPress <2> View All Movie");
	printf("\nPress <3> Find Movie ");
	printf("\nPress <4> Book Ticket");
	printf("\nPress <5> View All Transections");
   	printf("\nPress <0> Exit ");

   	printf("\nEnter your Choice ::");
   	scanf("%d",&p); 	

   	switch (p)
   	{
    		case 1 :
    		insertDetails();
   		break;
		case 2:
    		view_all();
   		break;
    		
		case 3:
    		Find();
   		break;

		case 4:
		bookTicket();
		break;
		
		case 5:
		oldRecord();
		break;

    		case 0:
    		exit(0);
    		break;

    		default:
    		printf("Wrong choice !");
    		break;
   	}
 }while(p!=0);

	


}


void insertDetails()
{
	
	FILE *fl;
	struct book b;
	printf("Enetr movie code :- ");	
	scanf("%s",b.code);
	printf("Enetr  name :- ");	
	scanf("%s",b.name);
	printf("Enetr Relice Date:- ");	
	scanf("%s",b.date);
	printf("Enetr Ticket Price:- ");	
	scanf("%d",&b.cost);
	
	fl=fopen("data.txt","a");

	if(fl == NULL)
	{
		printf("FIle not Found");
	}
	else
	{
		fprintf(fl,"%s %s %s %d \n",b.code,b.name,b.date,b.cost);
		printf("Record insert Sucessfull");
	}
		printf("\n");
	fclose(fl);
}
void Find() //find details
{
	struct book b;
	FILE *fl;
	
	char p[20];
	printf("Enter movie code :");
	scanf("%s",p);
	//system("clear");
	fl = fopen("data.txt","r");
	if(fl == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{	
		while(getc(fl) != EOF)
		{
			fscanf(fl,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
			if(strcmp(b.code,p) == 0)
			{	
				//printf("%s / %s / %s / %d\n",b.code,b.name,b.date,b.cost);
				printf("\n Record Found\n");
				printf("\n\t\tCode ::%s",b.code);
				printf("\n\t\tmovie name ::%s",b.name);
				printf("\n\t\tmovie date ::%s",b.date);
				printf("\n\t\tprice of ticket ::%d",b.cost);
			}
		}
		
	}

	fclose(fl);
}
void view_all()
{
	char p;
	FILE *fl;

	fl = fopen("data.txt","r");
	if(fl == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{	
		system("clear");
		while( ( p = fgetc(fl) ) != EOF )
      		printf("%c",p);
		
	
	fclose(fl);
}
//for ticket booking 
void bookTicket();
{
 struct book b;
	FILE *fl;

	FILE *ufp;

	int total_seat,mobile,total_amount;
	char name[20];

	
	char p; //used in display all movies
	char movie_code[20]; //for searching

	// disply all moives by default for movie code
	fl = fopen("data.txt","r");
	if(fl == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{	
		system("clear");
		while( ( p = fgetc(fl) ) != EOF )
      		printf("%c",p);
		
	}
	fclose(fl);
	
	//display ends
	printf("\n For Book ticket Choise Movie(Enter Movie Code First Latter Of Movie)\n");
	printf("\n Enter movie code :");
	scanf("%s",movie_code);
	//system("clear");
	fl = fopen("data.txt","r");
	if(fl == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{	
		while(getc(fl) != EOF)
		{
			fscanf(fl,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
			if(strcmp(b.code,movie_code) == 0)
			{	
				//printf("%s / %s / %s / %d\n",b.code,b.name,b.date,b.cost);
				printf("\n Record Found\n");
				printf("\n\t\tCode ::%s",b.code);
				printf("\n\t\tMovie name ::%s",b.name);
				printf("\n\t\tdate name ::%s",b.date);
				printf("\n\t\tPrice of ticket::%d",b.cost);
			}
		}
		
	}
	printf("\n* Fill Deatails  *");
	printf("\n your name :");
	scanf("%s",name);
	printf("\n mobile number :");
	scanf("%d",&mobile);
	printf("\n Total number of tickets :");
	scanf("%d",&total_seat);
	
	
	total_amount = b.cost * total_seat;
	
	printf("\n ENJOY MOVIE \n");
	printf("\n\t\tname : %s",name);
	printf("\n\t\tmobile Number : %d",mobile);
	printf("\n\t\tmovie name : %s",b.name);
	printf("\n\t\tTotal seats : %d",total_seat);
	printf("\n\t\tcost per ticket : %d",b.cost);
	printf("\n\t\tTotal Amount : %d",total_amount);
	
	
	ufp=fopen("oldTransaction.txt","a");
	if(ufp == NULL)
	{
		printf("FIle not Found");
	}
	else
	{
		fprintf(ufp,"%s %d %d %d %s %d \n",name,mobile,total_seat,total_amount,b.name,b.cost);
		printf("\n Record insert Sucessfull to the old record file");
	}
		printf("\n");
	fclose(ufp);
	fclose(fl);

};
//for view all user transections
void oldRecord()
{
	char p;
	FILE *fl;

	//system("clear");s
	
	fl = fopen("oldTransection.txt","r");
	if(fl == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{	
		system("clear");
		while( ( p = fgetc(fl) ) != EOF )
      		printf("%c",p);
		
	}
	fclose(fl);


}

