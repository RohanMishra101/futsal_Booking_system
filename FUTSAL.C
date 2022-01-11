#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<string.h>

struct booking_Details{
	char name[40];
	int num;
	int stime;
	int etime;

	struct booking_date{
		int year;
		int month;
		int day;
	}d;

}detail;


void menu();
void menu_start();
void booking();


void main()
{
	menu_start();
}


//Menu layout 1
void menu_start()
{
       int choice;
       int gd = DETECT,gm;
       initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
       menu();
       settextstyle(1,HORIZ_DIR,4);
       delay(500);
       gotoxy(30,13);
       printf("1) Book a Match.\n");
       gotoxy(30,15);
       printf("2) Cancel your Booking.\n");
       gotoxy(30,17);
       printf("3) View Bookings.\n");
       gotoxy(30,19);
       printf("4) Exit.");
       choice = getche();
       booking(choice);
       //getch();
       closegraph();
}
//Menu layout end


//UI Interface
void menu()
{
	rectangle(50,80,600,400);
	rectangle(52,82,598,398);
	delay(500);
	settextstyle(10,HORIZ_DIR,3);
	outtextxy(90,90,"  Futsal Booking System");
	delay(500);
	gotoxy(10,10);
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	gotoxy(40,24);
	printf("    Opeaning/Closing Time: 8am-19pm");
	gotoxy(10,23);
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
}
//UI Interface end



void booking(choice)
{

	FILE *fp;
	char another;
	int i,recsize,year,month,day,stime,etime;
	int gd = DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	fp = fopen("c:\\TURBOC3\\BIN\\futsal\\dat.txt","rb+");
	if(fp == NULL)
	{
		fp = fopen("c:\\TURBOC3\\BIN\\futsal\\dat.txt","wb+");
		if(fp == NULL)
		{
			printf("File not found!!");
		}
	}
	recsize = sizeof(detail);
	switch(choice)
	{
		case '1':
		{
			another = 'y';
			fseek(fp,0, SEEK_END);
			while(another == 'y')
			{
				flag:
				cleardevice();
				menu();
				fflush(stdin);
				gotoxy(15,12);
				printf("Name             : ");
				gets(detail.name);
				fflush(stdin);
				gotoxy(15,13);
				printf("Contact no.      : ");
				scanf("%d",&detail.num);
				fflush(stdin);
				gotoxy(15,14);
				printf("Date(yyyy/mm/dd) : \t");
				printf("Year : ");
				scanf("%d",&detail.d.year);
				fflush(stdin);

				if(detail.d.year <= 2021)
				{
					gotoxy(15,15);
					printf("Invalid year!! Year should not be lessthen 2022.");
					gotoxy(15,16);
					printf("Date(yyyy/mm/dd) : \t");
					printf("Year : ");
					scanf("%d",&detail.d.year);
					if(detail.d.year <= 2021)
					{
						gotoxy(20,18);
						printf("To many errors!! Please refill the form.");
						i = getche();
						goto flag;
					}
					fflush(stdin);
					gotoxy(39,17);
					printf(" Month : ");
					scanf("%d",&detail.d.month);
					fflush(stdin);
					if(detail.d.month > 12 || detail.d.month < 1)
					{
						gotoxy(15,18);
						printf("Invalid Month!! Month should be between 1 to 12.");
						gotoxy(39,19);
						printf(" Month : ");
						scanf("%d",&detail.d.month);
						fflush(stdin);
						if(detail.d.month >12 || detail.d.month < 1)
						{
							gotoxy(20,20);
							printf("To many errors!! Please refill the form.");
							i = getche();
							goto flag;
						}
					}
					gotoxy(39,20);
					printf("   Day : ");
					scanf("%d",&detail.d.day);
					fflush(stdin);
					if(detail.d.day < 1 || detail.d.day >30)
					{
						gotoxy(15,21);
						printf("Invalid Day!! Day should be between 1 to 30");
						gotoxy(15,22);
						printf("   Day : ");
						scanf("%d",&detail.d.day);
						fflush(stdin);
						if(detail.d.day < 1 || detail.d.day >30)
						{
							gotoxy(20,21);
							printf("To many errors!! Please refill the form.");
							i = getche();
							goto flag;
						}

					}

				}
				else
				{
					gotoxy(39,15);
					printf(" Month : ");
					scanf("%d",&detail.d.month);
					fflush(stdin);
					if(detail.d.month < 1 || detail.d.month > 12)
					{
						fflush(stdin);
						gotoxy(15,16);
						printf("Invalid Month!! Month should be between 1 to 12.");
						gotoxy(39,17);
						printf(" Month : ");
						scanf("%d",&detail.d.month);
						fflush(stdin);
						if(detail.d.month < 1 || detail.d.month > 12)
						{
							gotoxy(20,18);
							printf("To many Errors!! Please refill the Form");
							i = getche();
							goto flag;
						}
						gotoxy(39,18);
						printf("   Day : ");
						scanf("%d",&detail.d.day);
						fflush(stdin);
						if(detail.d.day < 1 || detail.d.day > 30)
						{
							gotoxy(15,19);
							printf("Invalid Day!! Day should be between 1 to 30");
							gotoxy(39,20);
							printf("   Day : ");
							scanf("%d",&detail.d.day);
							if(detail.d.day < 1 || detail.d.day > 30)
							{
								gotoxy(20,21);
								printf("To many Errors!! Please refill the Form");
								i = getche();
							goto flag;
							}
						}
					}
				}
				gotoxy(39,16);
				printf("   Day : ");
				scanf("%d",&detail.d.day);
				fflush(stdin);
				if(detail.d.day < 1 || detail.d.day > 30)
				{
					gotoxy(15,17);
					printf("Invalid Day!! Day should be between 1 to 30");
					gotoxy(39,18);
					printf("   Day : ");
					scanf("%d",&detail.d.day);
					fflush(stdin);
					if(detail.d.day < 1 || detail.d.day > 30)
					{
						gotoxy(20,19);
						printf("To many Errors!! Please refill the Form");
						i = getche();
						goto flag;
					}
				}
				time:
				cleardevice();
				menu();
				gotoxy(12,12);
				printf("Provided time should be in 24 Hour Format");
				gotoxy(16,13);
				year = detail.d.year;
				month = detail.d.month;
				day = detail.d.day;
				printf("%d,%d,%d",year,month,day);
				gotoxy(16,14);
				printf("Starting Time : ");
				scanf("%d",&detail.stime);
				gotoxy(16,15);
				printf("Ending Time : ");
				scanf("%d",&detail.etime);
				stime = detail.stime;
				etime = detail.etime;
				rewind(fp);
				while(fread(&detail,recsize,1,fp)>0)
				{
					if(year==detail.d.year  && month == detail.d.month  &&  day  == detail.d.day )
					{
							if(stime >= detail.stime  && etime <= detail.etime  )
							{
								gotoxy(12,17);
								printf("The given time is already been booked.");
								gotoxy(12,18);
								printf("Please provide different time for booking!!");
								gotoxy(12,19);
								printf("Press any key to continue..");
								i = getche();
								goto time;
							}
							else{
								printf("Your Booking is succesfully Booked!!");
								fwrite(&detail,recsize,1,fp);	
							}
										
					}
//					else
//					{
//						printf("Your Booking is succesfully Booked!!");
//						fwrite(&detail,recsize,1,fp);
//					}
				}
				gotoxy(14,17);
				printf("Your Booking is Sucessfully Booked!!");
				fwrite(&detail,recsize,1,fp);
				gotoxy(36,22);
				printf("DO you want to Book another Game (Y/N)");
				another = getche();
				tolower(another);
			}
			fclose(fp);
			menu_start();
		}
		break;
		case '2':
		{
			menu();
			gotoxy(10,20);
			printf("TO be added");
		}
		break;
		case '3':
		{
			menu();
			gotoxy(10,15);
			printf("TO be added");
		}
		break;
		case '4':
		{
			exit(0);
		}
		break;
		default:
		{
			menu_start();
		}
	}
	getch();
	closegraph();
}
