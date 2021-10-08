#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main()
{
	int gd = DETECT,gm;
	initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
	delay(500);
	rectangle(50,80,600,400);
	delay(500);
	rectangle(52,82,598,398);
	delay(500);
	settextstyle(10,HORIZ_DIR,3);
	outtextxy(90,90,"Futsal Management System");
	getch();
	closegraph();


}