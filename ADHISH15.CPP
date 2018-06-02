#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
enum Boolean{false,true};
class stack{
	     char s[100];
	     int item;
	     int top;
	     int maxsize;
  public:
	 stack(){top=-1;maxsize=100;};
	 stack(int max){top=-1;maxsize=max;};
	 Boolean isempty();
	 Boolean isfull();
	 void push(char a);
	 char pop();
	 //void topele();
	// void display();
	 };
	 Boolean stack::isempty()
	 {
	    if(top==-1)
	    return true;
	    return false;
	 }
	 Boolean stack::isfull()
	 {
	    if(top==maxsize-1)
	     return true;
	     return false;
	 }
	 void stack::push(char ele)
	 {
	    if(isfull())
	    cout<<"Stack Overflow";
	    else
	    s[++top]=ele;
	 }
	 char stack::pop()
	 {
	    if(isempty())
	    return -1;
	    else
	    item=s[top];
	    top--;
	    return (item);
	 }
	 void stack::topele()
	 {
	     cout<<"\n Top element is"<<s[top];
	 }
	 void stack::display()
	 {
	     if(isempty())
	     cout<<"Stack is empty";
	     else
	     for(int i=top;i>=0;i--)
	     {
		int k=pop();
		if(k>=0&&k<=9)
			cout<<k;
		else
			cout<<(char)(55+k);
	     }
	 }
void main()
{
   clrscr();
   stack Q;
   char p[100];
   int c=0,k=0;
   cout<<"Enter string:";
   gets(p);
   cout<<"\n";
   int l=strlen(p);
   int flag=1;
   for(int i=0;i<l;i++)
   {
    if(p[i]=='('||p[i]=='{'||p[i]=='[')
    {
      Q.push(p[i]);
      c++;
    }
    else if(p[i]==')')
    { k++;
      if(Q.pop()!='(')
	{
	  flag=0;
	  break;
	}
    }
     else if(p[i]=='}')
    { k++;
      if(Q.pop()!='{')
	{
	  flag=0;
	  break;
	}
    }
     else if(p[i]=='[')
    { k++;
      if(Q.pop()!=']')
	{
	  flag=0;
	  break;
	}
    }
  }
  if(c!=k)
  flag=0;
  if(flag==1)
    cout<<"Expression balanced";
  else
    cout<<"Not balanced";
   getch();
}

