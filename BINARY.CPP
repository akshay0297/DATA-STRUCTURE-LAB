#include<iostream.h>
#include<conio.h>
void main ()
{
clrscr();
int a[100] , i , j , k , p , n , m , d=0 ;
cin>>n;
    for(i=0;i<n;i++)
     {
       cin>>a[i] ;//array to be entered in sorted form
     }
     cin>>k;
     p=0;
     j=n-1;
     while(p<=j)
     {
       m=(p+j)/2;
       if(a[m]==k)
	{
	  d=1;
	  break;
	}
       else
	  if(a[m]<k)
	    p = m+1;
	  else
	   j=m-1;
     }
if(d==0)
  cout<<"not found";
else
  cout<<"found";
getch();
}