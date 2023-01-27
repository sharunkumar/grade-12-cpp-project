#include"gu.h"
#include"date.h"

void main()
{
 graph.init();
 date d;
 graph.getintxy(10,10,d.day)
      .getintxy(10,20,d.month)
      .getintxy(10,30,d.year)
      .gotoxy(50,50);
 graph<<d.tostring();
 getch();
}