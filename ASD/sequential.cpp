//LAB10 File handling program to 1. Create 2. Display 3. Add 4. Search 5. Remove student records.
#include<iostream>
#include<fstream>
using namespace std;
struct student
{
int rn;
char div;
char name[20], adr[20];
};
class File
{
char fname[20];
public :
void create();
void display();
void add();
void Delet(int rn);
void search(int rn);
};
int main()
{
int choice, rn;
File obj;
do
{
cout<<"Select operation from : 1. Create records 2. Display records 3. Add records 4. Remove records 5. Search records 6. exit\n";
cin>>choice;
switch(choice)
{
case 1: obj.create();
break;
case 2: obj.display();
break;
case 3: obj.add();
break;
case 4: cout<<"Enter student Roll No whose record to be deleted\n" ;
cin>>rn;
obj.Delet(rn);
break;
case 5: cout<<"Enter student Roll No whose record to be searched\n" ;
cin>>rn;
obj.search(rn);
break;
case 6: cout<<"Exit\n";
break;
default:cout<<"Wrong Choice\n";
break;
}
}while(choice!=6);
return 0;
}
void File :: create()
{
ofstream fp;
student s;
char option;
cout<<"Enter File name to be opened\n";
cin>>fname;
fp.open(fname);
do
{
cout<<"Enter student Roll No, Div, Name, Address\n";
cin>>s.rn>>s.div>>s.name>>s.adr;
fp.write((char*)(&s),sizeof(s));
cout<<"Do you want to add more records\n";
cin>>option;
}while(option=='y');
fp.close();
}
void File :: display()
{
ifstream fp;
student s;
fp.open(fname);
cout<<"Roll No\tDiv\tName\tAddress\n";
fp.read((char*)(&s),sizeof(s));
while(!fp.eof())
{
cout<<s.rn<<"\t"<<s.div<<"\t"<<s.name<<"\t"<<s.adr<<"\n";
fp.read((char*)(&s),sizeof(s));
}
fp.close();
}
void File :: add()
{
fstream fp;
student s;
fp.open(fname, ios::app);
cout<<"Enter records to be added \n Enter Roll No\tDiv\tName\tAddress\n";
cin>>s.rn>>s.div>>s.name>>s.adr;
fp.write((char*)(&s),sizeof(s));
fp.close();
}
void File :: search(int rn)
{
fstream fp;
student s;
int flag=0;
fp.open(fname);
fp.read((char*)(&s),sizeof(s));
while(!fp.eof())
{
if(rn==s.rn)
{
flag=1;
break;
}
fp.read((char*)(&s),sizeof(s));
}
if(flag==1)
cout<<s.rn<<"\t"<<s.div<<"\t"<<s.name<<"\t"<<s.adr<<"\n";
else
cout<<"Record not found\n";
fp.close();
}
void File :: Delet(int rn)
{
ifstream fp1;
ofstream fp2;
student s;
int flag=0;
fp1.open(fname);
fp2.open("temp.txt");
fp1.read((char*)(&s),sizeof(s));
while(!fp1.eof())
{
if(rn==s.rn)
{
cout<<s.rn<<"\t"<<s.div<<"\t"<<s.name<<"\t"<<s.adr<<"\n";
flag=1;
}
else
fp2.write((char*)(&s),sizeof(s));
fp1.read((char*)(&s),sizeof(s));
}
if(flag==0)
cout<<"Record not found\n";
fp1.close();
fp2.close();
remove(fname);
rename("temp.txt", fname);
}