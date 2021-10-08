#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main()
{
	int gd = DETECT,gm;
	initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
	rectangle(50,80,600,400);
	rectangle(52,82,598,398);
	getch();
	closegraph();


}