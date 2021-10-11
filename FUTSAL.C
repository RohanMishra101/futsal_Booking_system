#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>

void menu();
void menu_start();
void booking();

void main()
{
	menu_start();
}
//UI Interface
void menu()
{
       //	int gd = DETECT,gm;
       //	initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
       //	delay(500);
	rectangle(50,80,600,400);
       //	delay(500);
	rectangle(52,82,598,398);
	delay(500);
	settextstyle(10,HORIZ_DIR,3);
	outtextxy(90,90,"Futsal Management System");
	delay(500);
	gotoxy(10,10);
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	gotoxy(10,23);
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
       //	menu_start();
       //	getch();
       //	closegraph();
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
       booking(choice);
      // getch();
       closegraph();
}
//Menu layout 1 end

//Menu of 1 option
void booking(int ch)
{
	int gd = DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	cleardevice();
	gotoxy(25,20);
       //	setbkcolor(BLACK);
	switch(ch)
	{
		case '1':
		{
			menu();
			gotoxy(25,20);
			printf("Holla Peter");
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