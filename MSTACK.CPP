#include<iostream.h>
#include<conio.h>

class mstack
{
    int a[50] , bot[10], top[10] , max , ns ;
public :
    mstack();
    mstack(int,int) ;
    void push(int,int);
    int pop (int);
    void disp(int i);
} ;
mstack :: mstack()
{
    max = 10 ;
    ns =1;
}
mstack :: mstack (int m , int n)
{

    max = m ;
    ns = n;
    for(int i=0 ; i < ns ; i++)
    {

	top[i] = bot[i] = ((max/ns)*i)-1;
    }
}
void mstack :: push (int ele  , int i)
{
 if(top[i]==bot[i+1] || top[i] == max-1 )
	cout<<"\n Stack is full ! ";
 else
    a[++top[i]] = ele ;
}
int mstack :: pop(int i)
{

    if(top[i] == bot[i])
    {
      cout<<"\n Stack is empty !";
      return -1;
    }
    else
    {
      int val = a[top[i]];
      top[i]--;
      return val;
    }
}
void mstack :: disp (int i)
{

    if(top[i]== bot[i])
    {
	cout<<"\n Stack is empty ! ";
    }
    else
    {
      for (int j=top[i] ; j>bot[i] ; j--)
      {

	  cout<<a[j] <<" \t ";
      }
    }
}
void main ()
{
    clrscr();
    mstack ms;
    int ch , m , n , i , ele ;
    cout<<"\n Enter the maximum size of stack : ";
    cin>>m;
    cout<<"\n Enter the number of stacks you want to create :";
    cin>>n;
    ms = mstack (m , n);
    do
	{
	    cout<<"\n Enter 1 to insert an element into the stack ! " ;
	    cout<<"\n Enter 2 to delete an element from the stack ! " ;
	    cout<<"\n Enter 3 to display the elements of the stack ! ";
	    cout<<"\n Enter 0 to exit !"<<endl;
	    cin>>ch;
	    switch(ch)
	    {
	    case 1: cout<<"\n Enter the stack index : ";
		    cin>>i;
		    cout<<"\n Enter element to insert : " ;
		    cin>>ele;
		    ms.push(ele , i);
		    break;
	    case 2: cout<<"\n Enter the stack index : ";
		    cin>>i;
		    cout<<"The popped element is : "<<ms.pop(i);
		    break;
		    case 3: cout<<"\n Enter the stack index : ";
			    cin>>i;
			    ms.disp(i);
			    break;
	    case 0: break; //breaks of while loop
	    default : cout<<"INVALID OPTION ! ";
	    }
	}while(ch!=0);
getch();
}
