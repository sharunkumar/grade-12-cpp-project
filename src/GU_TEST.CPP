#include "GU.H"

void main()
{
 /*char str[100];
 graph.init(29,17);
 setcolor(RED);
 graph.line(10,10,20,16);
 graph.clear();
 graph.rectangle(1,1,28,16);
 //graph.patch(1,1);
 graph.getstrxy(100,100,str);
 setcolor(BLUE);
 outtextxy(200,200,str);
 graph.putchxy(10,10,'a');
 graph.putch(5,5,'B');
 graph<<'A'<<'B';
 graph<<'\n';
 graph<<"Sharun Kumar";
 graph<<'\n';
 //graph<<10;
 textsettingstype *sett;
 gettextsettings(sett);
 graph<<sett->charsize;
 */
 graph.init(29,17);
 graph.line(10,10,20,16)
      .rectangle(1,1,28,16);
 char *str;
 graph.getstrxy(10,10,str).gotoxy(30,30)<<str;
 //graph.printscreen("graph.bmp");
 //graph<<"File saved!";
 getch();
}