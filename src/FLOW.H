#include "gu.h"
#include "form.h"
#include "file.h"

//Functions for program flow...

void infobar();

void changetextstyle(int font, int direction, int charsize) {
	int ErrorCode;
	graphresult(); /* clear error code		*/
	settextstyle(font, direction, charsize);
	ErrorCode = graphresult(); /* check result 		*/
	if (ErrorCode != grOk) { /* if error occured		*/
		closegraph();
		printf(" Graphics System Error: %s\n", grapherrormsg(ErrorCode));
		exit(1);
	}
}


void spashscreen() //Splash Screen
{
	setfillstyle(10, 9);
	floodfill(1, 1, 9);
	graph.rectangler(1, 1, 28, 16);
	changetextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	graph.gotoxyr(4, 8);
	graph << "Computer Project";
	graph.gotoxyr(4, 10);
	changetextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
	settextjustify(RIGHT_TEXT, RIGHT_TEXT);
	graph.gotoxyr(4, 11);
	changetextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	graph << "Team Members: " << "Sharun";
	graph.cposy() += graph.getcharsize() * 10;
	graph.cposx() -= graph.getcharsize() * (sizeof("Sharun") - 1) * 8;
	graph << "Akhil";
	graph.cposy() += graph.getcharsize() * 10;
	graph.cposx() -= graph.getcharsize() * (sizeof("Akhil") - 1) * 8;
	graph << "Ajay";
	graph.cposy() += graph.getcharsize() * 10;
	graph.cposx() -= graph.getcharsize() * (sizeof("Ajay") - 1) * 8;
	graph << "Aditya";
	changetextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
	graph.cposy() += 2 * graph.getcharsize() * 10;
	graph.cposx() -= graph.xunit();
	//graph.cposx() += graph.getcharsize() * 8;
	graph << "Class - XII A1";
	getch();
}

//Order form

void ordfrm() {
	graph.init(29, 17);
	int x, y;
	x = getmaxx() / 29;
	y = getmaxy() / 17;

	//Printing the tables
	rectangle(x, y, x * 28, y * 16);
	line(x, y * 4, x * 28, y * 4);
	line(x, y * 8, x * 28, y * 8);
	line(x, y * 9, x * 28, y * 9);
	line(x, y * 12, x * 28, y * 12);
	line(x * 3, y * 8, x * 3, y * 12);
	line(x * 14, y * 4, x * 14, y * 16);
	line(x * 20, y * 8, x * 20, y * 12);
	line(x * 20, y * 10, x * 28, y * 10);
	line(x * 20, y * 11, x * 28, y * 11);


	//Data Fields
	outtextxy(x * 11, (y * 1) + 8, "Infinity Cpmputers");
	outtextxy(x * 1.5, (y * 5) - 9, "Customer's Name:");
	outtextxy(x * 1.5, (y * 6) - 9, "Address:");
	outtextxy(x * 14.5, (y * 5) - 9, "Order No:");
	outtextxy(x * 14.5, (y * 6) - 9, "Order Date:");
	outtextxy(x * 14.5, (y * 7) - 9, "Customer's ref No:");
	outtextxy(x * 14.5, (y * 8) - 9, "Ref Date:");
	outtextxy(x * 1.5, (y * 9) - 9, "Sno.");
	outtextxy(x * 2, (y * 10) - 9, "1.");
	outtextxy(x * 2, (y * 11) - 9, "2.");
	outtextxy(x * 2, (y * 12) - 9, "3.");
	outtextxy(x * 4, (y * 9) - 9, "Description");
	outtextxy(x * 4, (y * 10) - 9, "Personal Computer.");
	outtextxy(x * 4, (y * 11) - 9, "Mini-Frame.");
	outtextxy(x * 4, (y * 12) - 9, "Main-Frame.");
	outtextxy(x * 15, (y * 9) - 9, "Code");
	outtextxy(x * 15, (y * 10) - 9, "PROD-1");
	outtextxy(x * 15, (y * 11) - 9, "PROD-2");
	outtextxy(x * 15, (y * 12) - 9, "PROD-3");
	outtextxy(x * 22, (y * 9) - 9, "Quantity");
	outtextxy(x * 2, (y * 13) - 9, "Customer's Remarks:");
	outtextxy(x * 15, (y * 13) - 9, "Sales Officer's:-");
	outtextxy(x * 15, (y * 14) - 9, "Name:");
	outtextxy(x * 15, (y * 15) - 9, "Code:");

	//Enter Data
	int a, b;
	//Name
	a = (x * 1.5) + 131;
	b = (y * 5) - 9;
	graph.getstrxy(a, b, o.cname);


	//Address
	a = (x * 1.5) + 64;
	b = (y * 6) - 9;
	graph.getstrxy(a, b, o.add1);
	b = (y * 7) - 9;
	graph.getstrxy(a, b, o.add2);
	b = (y * 8) - 9;
	graph.getstrxy(a, b, o.add3);


	//ordernumber
	a = (x * 14.5) + 72;
	b = (y * 5) - 9;
	graph.getintxy(a, b, o.orderno);

	//orderdate
	a = (x * 14.5) + 72 + 16;
	b = (y * 6) - 9;

	graph.getintxy(a, b, o.ordate.day);

	a += 24;
	graph.getintxy(a, b, o.ordate.month);
	a += 24;
	graph.getintxy(a, b, o.ordate.year);





	//reference number
	a = (x * 14.5) + 144;
	b = (y * 7) - 9;
	graph.getintxy(a, b, o.refnum);


	//refdate
	a = (x * 14.5) + 72;
	b = (y * 8) - 9;
	graph.getintxy(a, b, o.refdate.day);

	a += 24;
	graph.getintxy(a, b, o.refdate.month);
	a += 24;
	graph.getintxy(a, b, o.refdate.year);

	//Quantity ordered
	a = (x * 22);
	b = (y * 10) - 9;
	graph.getintxy(a, b, o.quant1);



	a = (x * 22);
	b = (y * 11) - 9;
	graph.getintxy(a, b, o.quant2);



	a = (x * 22);
	b = (y * 12) - 9;
	graph.getintxy(a, b, o.quant3);


	//customer remark
	a = (x * 3);
	b = (y * 14) - 9;
	graph.getstrxy(a, b, o.cremark);

	//sales officer:name
	a = (x * 19);
	b = (y * 14) - 9;
	graph.getstrxy(a, b, o.sname);


	//Sign
	a = (x * 19);
	b = (y * 15) - 9;
	graph.getintxy(a, b, o.scode);


	//cout<<o.ordate.day<<o.ordate.month<<o.ordate.year;
	o.status = 1;
	formwrite(o);
	getch();
}

void targetregister()
{
	graph.init(29, 17);
	int x, y;
	x = graph.xunit();
	y = graph.yunit();

	infobar();

	graph.rectangler(1,1, 28, 16)
	     .line(1,3,28,3)
	     .line(1,5,28,5)
	     .line(11,4,23,4)
	     .line(3,3,3,16)
	     .line(7,3,7,16)
	     .line(11,3,11,16)
	     .line(15,4,15,16)
	     .line(19,4,19,16)
	     .line(23,3,23,16)
	     .puttxt(1.5,1.5, "Region Code:")
	     .puttxt(20.5,1.5, "Year:")
	     .puttxt(1.2, 3.5, "S.No.")
	     .puttxt(3.2,3.5, "Sales Code")
	     .puttxt(7.5,3.5, "Officer")
	     .puttxt(7.5,4, "Name")
	     .puttxt(14.7,3.5, "Computer Code")
	     .puttxt(12,4.5, "PROD-1")
	     .puttxt(16,4.5, "PROD-2")
	     .puttxt(20,4.5, "PROD-3")
	     .puttxt(24,3.5, "Remarks");
}

int homescreen()
{
	infobar();
	graph.init(29, 17);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 5);
	graph.puttxt(9,6, "WELCOME")
	     .setfont(DEFAULT_FONT, HORIZ_DIR, 2)
	     .puttxt(11,9, "Enter Choice")
	     .setdefaultfont()
	     .puttxt(12, 11, "1: Head Office")
	     .puttxt(12, 11.5, "2: Regional Office");
	int choice;
	do
	{
		choice = getch() - '0';
	} while(choice != 1 && choice != 2);
	return choice;
}

void infobar()
{
	graph.init(29, 17);
	graph.line(0,16.5,29,16.5)
		 .puttxt(0.2, 16.7, "Press ESC Key to exit...");
}