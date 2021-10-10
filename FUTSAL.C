#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void menu();
void menu_start();

void main()
{
	menu();
}
//UI Interface
void menu()
{
	int gd = DETECT,gm;
	initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
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
	menu_start();
	getch();
	closegraph();
}
//UI Interface end

//Menu outions
void menu_start()
{
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
}
