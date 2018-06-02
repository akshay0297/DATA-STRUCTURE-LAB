#include<iostream.h>
#include<conio.h>
#include<stdio.h>
class student
{
 char name[10];
 char grade;
 int roll;
 public :
    void read (student *s , int n);
    void print (student *s , int n);
    void sort (student *s , int n);
 };
 void student :: read(student s[] , int n)
 {
  for(int i=0;i<n;i++)
  {
    gets(s[i].name);
    cin>>s[i].roll;
    cin>>s[i].grade;
  }
 }
 void student :: sort(student s[] , int n )
 {
   student temp;
   for(int p=0;p<n;p++)
    {
      for(int j=0 ; j<(n-p);j++)
      {
	if(s[j].roll > s[j+1].roll)
	  {
	    temp = s[j];
	    s[j] = s[j+1];
	    s[j+1]  = temp;
	  }
       }
    }
 }
 void student :: print(student s[] , int n)
 {
   for(int i=0 ; i<n ; i++)
    {
    cout<<"Name :";
      puts(s[i].name);
      cout<<"Roll No. :  "<<s[i].roll<<endl;
      cout<<"Grade : "<<s[i].grade<<endl;
    }
 }
void main()
{
  clrscr();
  int m ;  cin>>m;
  student  b[10];
  b[0].read(b,m);
  b[0].sort(b,m);
  b[0].print(b,m);

  getch();
}