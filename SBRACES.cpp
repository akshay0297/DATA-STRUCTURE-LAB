#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<cstring>

using namespace std;

class stack
{
 // stack s ;
   char a[100];
   int max , top;
  public :
  stack()
  {
  max = 100;
   top = -1;
   }
  void push (char);
  char pop();
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
void stack :: push (char c)
{
  if(isfull())
  cout<<"Stack Overflow !";
  else
  a[++top]=c;
}
char stack :: pop()
{
  if(isempty())
    return (-1);
  else
  {
    char val  = a[top];
    top--;
    return val;
  }
}
void stack :: disp()
{
  for(int i=0 ; i<=top ;i++)
    {
      cout<<a[i];
    }
}
int main()
{
   // clrscr();
    stack s;
    char str[100]  ;
    int i , len ;
    cout<<"Enter the String  : ";
    gets(str);
    len = strlen(str);
    int flag=1;
    for(i=0 ; i< len ; i++)
    {
	if(str[i]=='(' || str[i]=='{' || str[i] == '[')
	s.push(str[i]);
	else
	    if(str[i]==')')
	    {
		if(!s.isempty())
	    {
		s.pop()!='(';
		flag=0 ;
		break;
	    }
	    }
	    else
	    if(str[i]=='}')
	       {
		if(!s.isempty())
	    {
		s.pop()!='{';
		flag=0 ;
		break;
	    }
	    }
	    else
	    if(str[i]==']')
	      {
		if(!s.isempty())
	    {
		s.pop()!='[';
		flag=0 ;
		break;
	    }
    }
      }
    if(flag==1)
    {
      cout<<"Braces are balanced !";
    }
    else
    {
	cout<<"Braces are imbalanced ! ";
    }
    //getch();
}
