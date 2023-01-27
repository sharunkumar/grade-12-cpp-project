#include<iostream.h>
#include<conio.h>
#include "date.h"

void main()
{
 clrscr();
 date d = {5, 11, 1995};
 cout<<d.tostring();
 getch();
}