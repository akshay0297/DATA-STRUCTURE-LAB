#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<string.h>

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
void main()
{
  clrscr();
  stack s;
  char str[0100];
  int i  , count =0 , len;
  cout<<"Enter the string to check for palindrome : ";
  gets(str);
  len = strlen(str);
  for(i=0 ; i<len ; i++)
  {
    s.push(str[i]);
  }
  for(i=0 ; i< len ; i++)
  {
   if (str[i] ==s.pop())
   count++;
  }
  if(count==len)
  cout<<"The string is palindrome ! " ;
  else
  cout<<"The string is not palindrome !";
  getch();
}


