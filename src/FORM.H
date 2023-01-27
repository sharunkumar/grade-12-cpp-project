//structures
#include"DATE.H"

struct orderform
{
 char cname[100];

 char add1[100];
 char add2[100];
 char add3[100];

 int orderno;


 date ordate;

 int refnum;

 date refdate;



 int quant1,quant2,quant3;

 char cremark[100];

 char sname[25];

 int scode;

 int status;


}o;

struct suppregister
{

 int sno;

 int orderno;

 date ordate;

 int ordquant; 

 date cdate; 

 int challan;  
 
 int suppquant; 

 int quantsupp; 

 char remark[100];

}s;

 
