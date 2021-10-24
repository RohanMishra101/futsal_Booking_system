#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>

void menu();
void menu_start();
void option();

void main()
{
	menu_start();
}
//UI Interface
void menu()
{
	rectangle(50,80,600,400);
	rectangle(52,82,598,398);
	delay(500);
	settextstyle(10,HORIZ_DIR,3);
	outtextxy(90,90,"Futsal Management System");
	delay(500);
	gotoxy(10,10);
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	gotoxy(40,24);
	printf("    Opeaning/Closing Time: 8am-7pm");
	gotoxy(10,23);
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
}
//UI Interface end

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
       option(choice);
      // getch();
       closegraph();
}
//Menu layout end

//Menu of Booking
void option(int ch)
{
	int gd = DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	cleardevice();
	gotoxy(25,20);
	switch(ch)
	{
		case '1':
		{
			menu();
			gotoxy(25,20);
			printf("Holla Peter");
		}
		break;
		case '2':
		{
			menu();
			gotoxy(10,20);
			printf("Nameste Puter");
		}
		break;
		case '3':
		{
			menu();
			gotoxy(10,15);
			printf("Meow meow NIGGA");
		}
		break;
		default:
		{
			exit (0);
		}
	}
	getch();
	closegraph();
}