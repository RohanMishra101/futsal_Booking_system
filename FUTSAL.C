#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<string.h>

struct booking_Details{
	char name[40];
	long int num;
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
void find_booking(void);
void view_booking(void);
void cancel_booking(void);
void modify_booking(void);

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
       gotoxy(30,12);
       printf("1) Book a Match.\n");
       gotoxy(30,14);
       printf("2) View Bookings.\n");
       gotoxy(30,16);
       printf("3) Modify Booking");
       gotoxy(30,18);
       printf("4) Cancel your Booking.\n");
       gotoxy(30,20);
       printf("5) Exit.");
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



void booking(ch)
{


	char another;
	int option,i;
	int gd = DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");


	switch(ch)
	{
		case '1':
		{
			FILE *fp1;
			int i,recsize,year1,month1,day1,time1,time2,stime,flag=0;
			char name[50],c;
			long int num;
			fp1 = fopen("c:\\TURBOC3\\BIN\\futsal\\dat.txt","rb+");
			if(fp1 == NULL)
			{
				fp1 = fopen("c:\\TURBOC3\\BIN\\futsal\\dat.txt","wb+");
				if(fp1 == NULL)
				{
					printf("File not found!!");
				}
			}
			recsize = sizeof(detail);
			fseek(fp1,0, SEEK_END);
			another = 'y';
			while(another == 'y')
			{
				flag:
				cleardevice();
				menu();
				fflush(stdin);
				gotoxy(15,12);
				printf("Name             : ");
				gets(name);
				fflush(stdin);
				gotoxy(15,13);
				printf("Contact no.      : ");
				scanf("%ld",&num);
				fflush(stdin);
				gotoxy(15,14);
				printf("Date(yyyy/mm/dd) : \t");
				printf("Year : ");
				scanf("%d",&year1);
				fflush(stdin);
				gotoxy(39,15);
				printf(" Month: ");
				fflush(stdin);
				scanf("%d",&month1);
				gotoxy(39,16);
				printf("   Day: ");
				fflush(stdin);
				scanf("%d",&day1);
				if(year1 <=2021 || month1 < 1 || month1 > 12 || day1 < 1 || day1 > 30){
					printf("Invalid Date!!, Refill the Form.");
					goto flag;
				}
				time:
				cleardevice();
				menu();
				gotoxy(13,12);
				printf("Provided time should be in 24 Hour Format");
				gotoxy(16,13);
//				year1 = detail.d.year;
//				month1 = detail.d.month;
//				day1 = detail.d.day;
				printf("Date : %d/%d/%d",year1,month1,day1);
				gotoxy(17,14);
				printf("Starting Time : ");
				scanf("%d",&time1);
				fflush(stdin);
				gotoxy(17,15);
				printf("Ending Time : ");
				scanf("%d",&time2);
				fflush(stdin);
				if(time1 < 8 || time1 > 19 || time2 < time1 || time2 > 19 || time2 < 8)
				{
					gotoxy(15,16);
					printf("Invalid Time!! Refill the Form.");
					i = getche();
					goto time;
				}

//				fwrite(&detail,recsize,1,fp1);
				rewind(fp1);
				while(fread(&detail,recsize,1,fp1)>0);
				{
					flag = 0;
					if(detail.d.year == year1 && detail.d.month == month1 && detail.d.day == day1 && time1 >= detail.stime && time1 < detail.etime && time2 > detail.stime && time2 <= detail.etime )
					{
						flag = 1;
						gotoxy(15,20);
						printf("Booking not avilable at provided time.");
						gotoxy(15,21);
						printf("Do you want check for booking again(y/n) : ");
						c = getche();
						if(c=='y' || c=='Y')
						{
							goto time;
						}
						else
						{
							fclose(fp1);
							menu_start();
						}
					}
				}
				if(flag == 0)
				{
					strcpy(detail.name,name);
					detail.num = num;
					detail.d.year = year1;
					detail.d.month = month1;
					detail.d.day = day1;
					detail.stime = time1;
					detail.etime = time2;
					fwrite(&detail,recsize,1,fp1);
					gotoxy(20,20);
					printf("Booking Complete!!");
					fclose(fp1);
					gotoxy(20,22);
					printf("DO you want to Book another Game (Y/N)");
					another = getche();
					tolower(another);
				}
			}
			menu_start();

		break;
		}
		case '2':
		{
			search_menu:
			cleardevice();
			menu();
			gotoxy(30,13);
			printf("1) View Booking");
			gotoxy(30,15);
			printf("2) Find your booking");
			gotoxy(30,17);
			printf("3) Exit");
			option = getche();
			switch(option)
			{
				case '1':
				{
					view_booking();
				break;
				}
				case '2':
				{
					find_booking();

				break;
				}
				case '3':
				{
					menu_start();
				break;
				}
				default:
				{
					gotoxy(28,20);
					printf("Invalid choice!!");
					i = getche();
					goto search_menu;
				}
			}

		}
		break;

		case '3':
			modify_booking();
		break;
		case '4':
			cancel_booking();
		break;

		case '5':
			exit(0);
		break;
		default:
		{
			menu_start();
		}
	}
	getch();
	closegraph();
}



//------------------Find Booking------------------

void find_booking()
{

	FILE *fp2;
	int flag=0,i;
	long int unum;
	char uname[50],c;
	again2:
	fp2 = fopen("c:\\TURBOC3\\BIN\\futsal\\dat.txt","rb");
	if(fp2 == NULL)
	{
		printf("File not found!!");
		exit(0);
	}
	cleardevice();
	menu();
	gotoxy(12,12);
	printf("Enter your Booking Name : ");
	gets(uname);
	fflush(stdin);
	gotoxy(12,13);
	printf("Enter your Booking Contact No. : ");
	scanf("%ld",&unum);
	fflush(stdin);
	while(fread(&detail,sizeof(detail),1,fp2) >0)
	{
		if(strcmp(uname,detail.name)==0 && unum == detail.num)
		{
			flag = 1;
			gotoxy(16,15);
			printf("Name : %s",detail.name);
			gotoxy(16,16);
			printf("Contact No. : %ld",unum);
			gotoxy(16,17);
			printf("Date : %d/%d/%d",detail.d.year,detail.d.month,detail.d.day);
			gotoxy(16,18);
			printf("Starting Time : %d",detail.stime);
			gotoxy(16,19);
			printf("Ending Time : %d",detail.etime);
			gotoxy(20,21);
			printf("Do you want check for booking again(y/n)");
			c = getche();
			if(c=='y' || c=='Y')
			{
				fclose(fp2);
				goto again2;
			}
			else
			{
				fclose(fp2);
				menu_start();
			}
		}
	}
	if(flag == 0)
	{
		gotoxy(20,20);
		printf("There is no Booking..");
		fclose(fp2);
		gotoxy(20,21);
		printf("Do you want check for booking again(y/n)");
		c = getche();
		if(c=='y' || c=='Y')
		{
			fclose(fp2);
			goto again2;
		}
		else
		{
			fclose(fp2);
			menu_start();
		}
	}

}



//--------------------View Booking-------------------


void view_booking()
{
	FILE *fp3;
	int flag3=0,time,i;
	int year2,month2,day2;
	char c;
	again:
	fp3 = fopen("c:\\TURBOC3\\BIN\\futsal\\dat.txt","rb");
	if(fp3 == NULL)
	{
		printf("File not found!!");
		exit(0);
	}

	cleardevice();
	menu();
	gotoxy(10,13);
	printf("Date(yyyy/mm/dd) : ");
	gotoxy(10,14);
	printf(" Year : ");
	scanf("%d",&year2);
	gotoxy(25,14);
	printf("Month : ");
	scanf("%d",&month2);
	gotoxy(35,14);
	printf("  Day : ");
	scanf("%d",&day2);
	gotoxy(14,15);
	printf("-------------------------------------------------------");
	gotoxy(12,16);
	printf("Time : ");
	scanf("%d",&time);
	while(fread(&detail,sizeof(detail),1,fp3)>0);
	{

		if(detail.d.year == year2 && detail.d.month == month2 && detail.d.day == day2 && time >= detail.stime && time <=detail.etime)
		{
			flag3 = 1;
			gotoxy(15,20);
			printf("Booking not avilable at provided time.");
			gotoxy(15,21);
			printf("Do you want check for booking again(y/n) : ");
			c = getche();
			if(c=='y' || c=='Y')
			{
				fclose(fp3);
				goto again;
			}
			else
			{
				fclose(fp3);
				menu_start();
			}
		}
	}
	if(flag3 == 0)
	{
		gotoxy(15,20);
		printf("Booking avilable at provided Time.");
		gotoxy(15,21);
		printf("Do you want check for booking again(y/n) : ");
		c = getche();
		if(c=='y' || c=='Y')
		{
			fclose(fp3);
			goto again;
		}
		else
		{
			fclose(fp3);
			menu_start();
		}
	}
	fclose(fp3);
}



//-----------------Cancel Booking-------------------


void cancel_booking()
{
	FILE *fp4,*fp5;
	int flag9 = 0;
	long int unum1;
	char uname1[50],i;
	c_again:
	fp4 = fopen("c:\\TURBOC3\\BIN\\futsal\\dat.txt","rb+");
	if(fp4 == NULL)
	{
		fp4 = fopen("c:\\TURBOC3\\BIN\\futsal\\dat.txt","wb+");
		if(fp4 == NULL)
		{
			printf("File not found!!");
		}
	}
	fp5 = fopen("c:\\TURBOC3\\BIN\\futsal\\tmp.txt","rb+");
	if(fp5 == NULL)
	{
		fp5 = fopen("c:\\TURBOC3\\BIN\\futsal\\tmp.txt","wb+");
		if(fp5 == NULL)
		{
			printf("File not found!!");
		}
	}
	cleardevice();
	menu();
	gotoxy(15,12);
	printf("Enter your booking name : ");
	gets(uname1);
	fflush(stdin);
	gotoxy(15,13);
	printf("Enetr your booking Contact No. : ");
	scanf("%ld",&unum1);
	fflush(stdin);
	while(fread(&detail,sizeof(detail),1,fp4)>0)
	{
		if(strcmp(uname1,detail.name)!=0 && unum1 != detail.num)
		{
			flag9 = 1;
			fwrite(&detail,sizeof(detail),1,fp5);


		}
	}
	fclose(fp4);
	fclose(fp5);
	remove("c:\\TURBOC3\\BIN\\futsal\\dat.txt");
	rename("c:\\TURBOC3\\BIN\\futsal\\tmp.txt","c:\\TURBOC3\\BIN\\futsal\\dat.txt");
	gotoxy(20,17);
	printf("Your booking is now canceled!!");
	gotoxy(20,18);
	printf("Do you want cancel another booking(y/n) : ");
	i = getche();
	if(i=='y' || i=='Y')
	{
		goto c_again;
	}
	else
	{
		menu_start();
	}
}




//---------------Modify Booking-------------------

void modify_booking()
{

	FILE *fp6;
	int recsize,year3,month3,day3,i,mflag = 0,stime1,etime1;
	long int unum2,num2;
	char uname2[50],name2[50],c;
	c_again2:
	fp6 = fopen("c:\\TURBOC3\\BIN\\futsal\\dat.txt","rb+");
	if(fp6 == NULL)
	{
		fp6 = fopen("c:\\TURBOC3\\BIN\\futsal\\dat.txt","wb+");
		if(fp6 == NULL)
		{
			printf("File not found!!");
		}
	}
	cleardevice();
	menu();
	recsize = sizeof(detail);
	gotoxy(15,12);
	printf("Enter your booking name : ");
	gets(uname2);
	fflush(stdin);
	gotoxy(15,13);
	printf("Enter your booking Contact No. : ");
	scanf("%ld",&unum2);
	fflush(stdin);
	while(fread(&detail,sizeof(detail),1,fp6)>0)
	{
		if(strcmp(uname2,detail.name)==0 && unum2 == detail.num)
		{
			mflag = 1;
			flag:
			cleardevice();
			menu();
			fflush(stdin);
			gotoxy(15,12);
			printf("Name             : ");
			gets(name2);
			fflush(stdin);
			gotoxy(15,13);
			printf("Contact no.      : ");
			scanf("%ld",&num2);
			gotoxy(15,14);
			printf("Date(yyyy/mm/dd) : \t");
			printf("Year : ");
			scanf("%d",&year3);
			gotoxy(39,15);
			printf(" Month: ");
			scanf("%d",&month3);
			gotoxy(39,16);
			printf("   Day: ");
			scanf("%d",&day3);
			if(year3 <=2021 || month3 < 1 || month3 > 12 || day3 < 1 || day3 > 30)
			{
				printf("Invalid Date!!, Refill the Form.");
				goto flag;
			}
			time:
			cleardevice();
			menu();
			gotoxy(12,12);
			printf("Provided time should be in 24 Hour Format");
			gotoxy(15,13);
			printf("Date : %d/%d/%d",year3,month3,day3);
			gotoxy(16,14);
			printf("Starting Time : ");
			scanf("%d",&stime1);
			fflush(stdin);
			gotoxy(16,15);
			printf("Ending Time : ");
			scanf("%d",&etime1);
			fflush(stdin);
			if(stime1 < 8 || stime1 > 19 || etime1 < stime1 || etime1 > 19 || etime1 < 8)
			{
				printf("Invalid Time!! Refill the Form.");
				i = getche();
				goto time;
			}
			while(fread(&detail,recsize,1,fp6)>0);
				{
					mflag = 0;
					if(detail.d.year == year3 && detail.d.month == month3 && detail.d.day == day3 && stime1 >= detail.stime && stime1 < detail.etime && etime1 > detail.stime && etime1 <= detail.etime )
					{
						mflag = 1;
						gotoxy(15,20);
						printf("Booking not avilable at provided time.");
						gotoxy(15,21);
						printf("Do you want check for booking again(y/n) : ");
						c = getche();
						if(c=='y' || c=='Y')
						{
							goto time;
						}
						else
						{
							fclose(fp6);
							menu_start();
						}
					}
				}
				if(mflag == 0)
				{
					strcpy(detail.name,name2);
					detail.num = num2;
					detail.d.year = year3;
					detail.d.month = month3;
					detail.d.day = day3;
					detail.stime = stime1;
					detail.etime = etime1;

					fseek(fp6,-recsize,SEEK_CUR);
					fwrite(&detail,recsize,1,fp6);
					gotoxy(20,20);
					printf("Booking Complete!!");
					fclose(fp6);
					gotoxy(20,22);
					printf("DO you want to modify another Booking(y/n)");
					c = getche();
					if(c=='y' || c=='Y')
					{
						goto c_again2;
					}
					else
					{
						menu_start();
					}
				}
			}
	}
//			fwrite(&detail,recsize,1,fp6);
}
