#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<cstring>

using namespace std;

class stack
{
	int top , max , a[100];
  public :
  	stack()
	{
		max = 10 ;
		top = -1;
	}
	void push(int ele);
	int pop();
	void disp();
	void posteval();
};
 void stack :: push (int ele)
 {
 	if (top == max-1)
    cout<<"Stack Overflow ";
	else
	 a[++top] = ele;
 }
 int stack ::  pop()
 {
 	if(top == -1)
	   {
	   return -1;
	    cout<<"Stack is empty !";
	   }
	else
	{
		int val ;
		val = a[top];
		top--;
		return val;
	}
 }
 void stack :: disp()
 {
 	if(top == -1 )
	{
		 cout<<"Stack is empty ! ";
	}
	else
	 for(int i=0 ; i<=top ; i++)
	   {
	   	cout<<a[i]<<"\t" ;
	   }
 }
 void stack :: posteval()
 {
 	stack s;
	int opr , op1 , op2  , c;
	char sym , post[50];
	cout<<"Enter postfix expression for evaluation : ";
	gets(post);
	int p =strlen(post);
	for(int i=0 ; i<p ; i++)
	{
		sym = post[i];
		if(sym >= '0' && sym <= '9')
		{
			opr = sym - '0';
			s.push(opr);
		}
		else
		 {
		 	if(sym == '+' || sym == '-' || sym == '*' || sym == '/' || sym == '%' )
			{
				op2 = s.pop();
				op1 = s.pop();
				switch (sym)
				{
					case '+' : c = op1 + op2 ;
							   s.push(c);
							   break;
				    case '-' : c = op1 - op2;
					           s.push(c);
							   break;
					case '*' : c = op1 * op2 ;
							   s.push(c);
							   break;
				    case '/' : c = op1 / op2;
					           s.push(c);
							   break;
					case '%' : c = op1 % op2 ;
							   s.push(c);
							   break;
				}
			}
			else
			  {
			   int v ;
			   cin>>v;
			   s.push(v);
		 	}
		}
	}
	cout<<"Result = " <<s.pop()<<endl;
 }

 int main ()
 {
 	// clrscr();
 	stack sa;
	sa.posteval();
	//getch();
 }
