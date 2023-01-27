// file handling for order form


void formwrite(orderform o)
{
 ofstream form("ORDFRM.dat",ios::binary|ios::app);
 if(!form)
 cout<<"error";
 else
  form.write((char *)&o,sizeof(orderform));
  //outtext("success");

 form.close();
}

void suppwrite(suppregister s)
{
 ofstream supp("SPPREG.dat",ios::binary | ios::app);
 if(!supp)
 cout<<"error";
 else
 {
  supp.write((char *)&s,sizeof(suppregister));
 }
 supp.close();
}

void suppread(suppregister s)
{
 ifstream supp("SPPREG.dat",ios::binary);

 if(!supp)
 outtext("e");
 else
 {
  while(!supp.eof())
  {
   supp.read((char *)&s,sizeof(suppregister));
  }
 }
 supp.close();
 
}

void formread(orderform o)
{
 ifstream form("ORDFRM.dat",ios::binary);
 if(!form)
 outtext("e");
 else
 {
  while(!form.eof())
  {
   form.read((char *)&o,sizeof(orderform));
  }
 }
 form.close();
 
}
