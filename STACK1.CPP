#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<process.h>

using namespace std;

class stack
{
 // stack s ;
  int a[10] ,max , top;
  public :
  stack()
  {
  max = 7;
   top = -1;
   }
  void push (int b);
  int pop();
  void disp();
  int isfull()
  {
    if(top==max - 1)
     return 1;
     return 0;
  }
  int isempty()
  {
    if(top == -1)
    return 1 ;
    return 0 ;
  }
};
void stack :: push (int b)
{
  if(isfull())
  cout<<"Stack Overflow !";
  else
  a[++top]=b;
}
int stack :: pop()
{
  if(isempty())
    return (-1);
  else
  {
    int val  = a[top];
    top--;
    return val;
  }
}
void stack :: disp()
{
  for(int i=top+1 ; i>=0 ;i++)
    {
      cout<<a[i] << "\t" <<endl;
    }
}
int main ()
{
// clrscr();
stack s;
int p;
 for(;p!=4;)
 {
 cout<<"To push an element in stack press 1 !"<<endl;
 cout<<"To pop an element from stack press 2 !"<<endl;
 cout<<"To display the stack press 3 !"<<endl;
 cout<<"Enter 4 to end the programm ! "<<endl;
 cin>>p;
 switch (p)
 {
  case 1 : cout<<"Enter a value to push :"<<endl;
	   int n;
	   cin>>n;
	   s.push(n);
	   break;
  case 2 : cout<<s.pop();
	    break ;
  case 3 : s.disp();
	  break;
  case 4 : cout<<"You Ended the program !";
	   exit(0);
  default : cout<<"Wrong Option ! " <<endl;

  }//switch
}//for
//getch();
}
