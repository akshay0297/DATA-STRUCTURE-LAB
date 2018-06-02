#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<process.h>

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
  for(int i=0 ; i<=top ;i++)
    {
      cout<<a[i];
    }
}
void main ()
{
  clrscr();
  stack s;
  int  n  , b ;
  cout<<"Enter the number : ";
  cin>>n;
  cout<<"Enter the base : ";
  cin>>b;
  int p;
  while (n>0)
  {
    p = n%b;
    s.push(p);
    n=n/b;
  }
  int v ;
  while(!s.isempty())
  {
    v=s.pop();
    if(v<10)
	cout<<v;
    else
	cout<<(char)(v+55);
    /*if(v==10)
    cout<<"A";
    if(v==11)
    cout<<"B";
    if(v==12)
    cout<<"C";
    if(v==13)
    cout<<"D";
    if(v==14)
    cout<<"E";
    if(v==15)
    cout<<"F";cout<<v;*/
  }
getch();

}