#include "flow.h"

//Program Flow:
//splashscreen() --> homescreen() --> Regional Office --> [Welcome] --> Place Order Form
//								  |									|-> Recieve Supply Target (just display)
//								  |
//								  |-> Head Office --> [options] --> See Suppply Register
//																|-> Enter Target For Each Regional Office
//																|-> See Regionwise Sales Report
//																|-> See Sales Officer - wise Sales Report
//																|-> See Product - wise Sales Report

int ckey = 0; //Current Keyboard Key

void main()
{
 clrscr();
 graph.init(29,17);
 //spashscreen();
 //ordfrm();
 //targetregister();
 int c = homescreen();
 graph.clear().putint(10,10,c);
 getch();
}