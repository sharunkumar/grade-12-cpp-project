#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fstream.h>
#include "bitmap.h"
#define BGI_DIR "..\\BGI"

//Graphics Utility

//To do: cpos in all functions...

struct coor //Structure for co-ordinate
{
	int x, y;
};

class gutility {
	int x, y;
	char block[2], cursor[2];
	coor cpos; //Current Position
		
	public:

	int getcharsize()
	{
		textsettingstype sett;
		gettextsettings( &sett);
		return sett.charsize;	
	}

	int &cposx()
	{
		return cpos.x;
	}

	int &cposy()
	{
		return cpos.y;
	}

	int initialized; //Safety Purposes

	gutility &setcposxy(int x1, int y1)
	{
	 cpos.x = x1;
	 cpos.y = y1;
	 return *this;
	}

	gutility &setcpos(float x1, float y1)
	{
	 cpos.x = x * x1;
	 cpos.y = y * y1;
	 return *this;
	}

	gutility() //Default Constructor
	{
		block[0] = 219;
		block[1] = '\0';
		cursor[0] = '_';
		cursor[1] = '\0';
		x = y = initialized = cpos.x = cpos.y = 0;
	}

	~gutility() //Destructor: Automatically closes graphics mode.
	{
		close();
	}

	int init() //Initializing Graphics
	{
		int r = init(1,1);
		x=y=1;
		return r;
	}
	
	int init(int x1, int y1)
	{
		int d = DETECT, m = VGAHI;
		initgraph( & d, & m, BGI_DIR);
		x = getmaxx() / x1;
		y = getmaxy() / y1;
		initialized = 1;
		return graphresult();
	}

	void close() //Closing graphics mode
	{
		initialized = cpos.x = cpos.y = 0;
		closegraph();
	}

	gutility &setdefaultfont()
	{
		settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
		return *this;
	}

	gutility &setfont(int fontname, int fontdir, int fontsize)
	{
		settextstyle(fontname, fontdir, fontsize);
		return *this;
	}

	//Note: Resolution operator (::) used inside because same names are used
	//Inside the functions...

	gutility &line(float x1, float y1, float x2, float y2) //Line
	{
		::line(x1 * x, y1 * y, x2 * x, y2 * y);
		cpos.x = x2 * x;
		cpos.y = y2 * y;
		return *this;
	}
	
	gutility &rectangle(int left, int top, int right, int bottom) //Rectangle
	{
		::rectangle(left, top, right, bottom);
		cpos.x = right * x;
		cpos.y = bottom * y;
		return *this;

	}

	gutility &rectangler(float left, float top, float right, float bottom) //Rectangle
	{
		::rectangle(left * x, top * y, right * x, bottom * y);
		cpos.x = right * x;
		cpos.y = bottom * y;
		return *this;

	}

	void conv_pts(int pts[], int n) //Converts a set of co-ordinates by x & y units in graph
	{
		//n = no. of co-ordinates, not number of points...
		for (int i = 0; i < n - 1; i += 2) {
			pts[i] *= x;
			pts[i + 1] *= y;
		}
	}
	
	//PATCH//////////////////////////////////////////////////////////////////////////////////////////////
	gutility &patch(float a, float b) {
		patchxy(a * x, b * y);
		return *this;
	}

	gutility &patchxy(int a, int b) //Puts a "block" character at (a,b)  [absolute]
	{
		int bkc = getbkcolor();
		int fgc = getcolor();
		int chs = getcharsize()*8;
		
		setcolor(bkc);
		outtextxy(a, b, block);
		setcolor(fgc);
		cpos.x = a + chs; cpos.y = b;
		return *this;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	gutility &clear() //Clear Screen
	{::cleardevice();
	return *this;
	}
	
	//GETSTR////////////////////////////////////////////////////////////////////////////////////////////
	gutility &getstrxy(int x, int y, char str[]) {
		str[0] = '\0';
		int chs = getcharsize()*8;
		for (int i = 0; str[i] != 13; i++) {
			outtextxy(x + i * chs, y, cursor);
			int in = getch();
			if ( in >= 32 && in <= 126 || in == 13 || in ==8) {
				if ( in == 13) 
				{
					patchxy(x + (i) * chs, y);
					break;
				}
				else if ( in == 8) {

					if (i >= 1) {
						i -= 2;
						patchxy(x + (i + 1) * chs, y);
						patchxy(x + (i + 1) * chs + chs, y);

						str[i + 1] = '\0';
					} else {
						str[0] = '\0';
						i = -1;
					}
				} else {
					str[i] = (char) in ;
					str[i + 1] = '\0';
					char temp[2];
					temp[0] = str[i];
					temp[1] = '\0';
					patchxy(x + i * chs, y);
					outtextxy(x + i * chs, y, temp);
				}
			}
			else i--;
		}
		cpos.x = x + i * chs;
		cpos.y = y + chs;
		return *this;
	}

	gutility &getstr(float x1, float y1, char str[]) {
		getstrxy(x1 * x, y1 * y, str);
		return *this;
	}
	
	gutility &getstr(char str[])
	{
		getstrxy(cpos.x, cpos.y, str);
		return *this;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//GETINT/////////////////////////////////////////////////////////////////////////////////////////////
	gutility &getintxy(int x1, int y1, int &val)
	{
		char *str;
		getstrxy(x1, y1, str);
		val = atoi(str);
		return *this;
	}
	
	gutility &getint(float x1, float y1, float &val)
	{
		getintxy(x1*x, y1*y, val);
		return *this;
	}
	
	gutility &getint(int &val)
	{
		getintxy(cpos.x, cpos.y, val);
		return *this;
	}
	
	
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//PUTINT/////////////////////////////////////////////////////////////////////////////////////////////
	gutility &putintxy(int x1, int y1, int val)
	{
		gotoxy(x1,y1);
		char *str;
		itoa(val, str, 10);
		outtextxy(x1,y1,str);
		return *this;
	}
	
	gutility &putint(float x1, float y1, float val)
	{
		putintxy(x1*x,y1*y,val);
		return *this;	
	}
	
	gutility &putint(int val)
	{
		putintxy(cpos.x, cpos.y, val);
		return *this;	
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//UNITS///////////////////////////////////////////////////////////////////////////////////////////////
	int xunit()
	{
		return x;
	}
	
	int yunit()
	{
		return y;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//PUTCH//////////////////////////////////////////////////////////////////////////////////////////////
	gutility &putchxy(int x1, int y1, char ch)
	{
		char str[] = {ch, '\0'};
		int chs = getcharsize() * 8;
		if(ch == '\n')
		{
			cpos.x = x1;
			cpos.y += chs;
		}
		else
		{
			cpos.x = x1 + chs;
			cpos.y = y1;
			outtextxy(x1, y1, str);
		}
		return *this;
	}

	gutility &putch(float x1, float y1, char ch)
	{
		putchxy(x1 * x, y1 * y, ch);
		return *this;
	}
	
	gutility &putch(char ch)
	{
		putchxy(cpos.x, cpos.y, ch);
		return *this;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	//PUTTXT/////////////////////////////////////////////////////////////////////////////////////////////
	gutility &puttxt(float x1, float y1, char *str)
	{
		gotoxy(x*x1, y*y1);
		*this<<str;
		return *this;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//SETXY AND GOTOXY///////////////////////////////////////////////////////////////////////////////////
	gutility &setxy(int x1, int y1) //Sets the size of one unit of the graph
	{
		x = x1; y = y1;
		return *this;
	}
	
	gutility &gotoxy(int x1, int y1)
	{
		cpos.x = x1; cpos.y = y1;
		return *this;
	}
	

	gutility &gotoxyr(float x1, float y1)
	{
		cpos.x = x1 * x; cpos.y = y1 * y;
		return *this;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////
		
	//OPERATORS//////////////////////////////////////////////////////////////////////////////////////////
	gutility &operator<<(char ch)
	{
		putchxy(cpos.x, cpos.y, ch);
		return *this;
	}
	
	gutility &operator<<(char *ch)
	{
		for(char *i = ch; *i != '\0'; i++)
			putch(*i);
		return *this;
	}
	
	gutility &operator<<(int i)
	{
		char *temp = new char;
		*this<<itoa(i, temp, 10);
		delete temp;
		return *this;
		
	}
	
	gutility &operator>>(int &i)
	{
		getint(i);
		return *this;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//PRINTSCREEN!!!//////////////////////////////////////////////////////////////////////////////////////
	void printscreen(char file[])
	{
	int i = 0, j = 0, r, g, b;

	FILE * fp;
	BMP * bmp;

	bmp = (BMP * ) malloc(54);

	bmp -> bfType[0] = 'B';
	bmp -> bfType[1] = 'M';
	bmp -> bfSize = 153718;
	bmp -> bfReserved1 = 0;
	bmp -> bfReserved2 = 0;
	bmp -> bfOffset = 118;
	bmp -> biSize = 40;
	bmp -> biWidth = 640;
	bmp -> biHeight = 480;
	bmp -> biPlanes = 1;
	bmp -> biBitCount = 4;
	bmp -> biCompression = 0;
	bmp -> biSizeImage = 153600;
	bmp -> biXPelsPerMeter = 0;
	bmp -> biYPelsPerMeter = 0;
	bmp -> biClrUsed = 0;
	bmp -> biClrImportant = 0;

	fp = fopen(file, "wb");
	if (fp == NULL) {
		printf("File can't be open");
		getch();
	}


	fwrite(bmp, 54, 1, fp);
	fseek(fp, 54L, SEEK_SET);

	fputc(0x0, fp);
	fputc(0x0, fp);
	fputc(0x0, fp);
	fputc(0x0, fp);

	fputc(127, fp);
	fputc(0x0, fp);
	fputc(0x0, fp);
	fputc(0x0, fp);

	fputc(0x0, fp);
	fputc(127, fp);
	fputc(0x0, fp);
	fputc(0x0, fp);

	fputc(127, fp);
	fputc(127, fp);
	fputc(0x0, fp);
	fputc(0x0, fp);

	fputc(0x0, fp);
	fputc(0x0, fp);
	fputc(127, fp);
	fputc(0x0, fp);

	fputc(127, fp);
	fputc(0x0, fp);
	fputc(127, fp);
	fputc(0x0, fp);

	fputc(0x0, fp);
	fputc(192, fp);
	fputc(192, fp);
	fputc(0x0, fp);

	fputc(192, fp);
	fputc(192, fp);
	fputc(192, fp);
	fputc(0x0, fp);

	fputc(128, fp);
	fputc(128, fp);
	fputc(128, fp);
	fputc(0x0, fp);

	fputc(255, fp);
	fputc(0x0, fp);
	fputc(0x0, fp);
	fputc(0x0, fp);

	fputc(0x0, fp);
	fputc(255, fp);
	fputc(0x0, fp);
	fputc(0x0, fp);

	fputc(255, fp);
	fputc(255, fp);
	fputc(0x0, fp);
	fputc(0x0, fp);

	fputc(0x0, fp);
	fputc(0x0, fp);
	fputc(255, fp);
	fputc(0x0, fp);

	fputc(255, fp);
	fputc(0x0, fp);
	fputc(255, fp);
	fputc(0x0, fp);

	fputc(0x0, fp);
	fputc(255, fp);
	fputc(255, fp);
	fputc(0x0, fp);

	fputc(255, fp);
	fputc(255, fp);
	fputc(255, fp);
	fputc(0x0, fp);

	i = 0;
	j = 479;

	fseek(fp, 118, SEEK_SET);

	while (j >= 0) {
		i = 0;
		while (i < 640) {
			fputc((getpixel(i, j) << 4) | getpixel(i + 1, j), fp); 
			i += 2;
		}
		j--;
	}
	free(bmp);
	fclose(fp);
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////
} graph;