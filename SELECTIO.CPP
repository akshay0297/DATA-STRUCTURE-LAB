#include<iostream>
#include<conio.h>

using namespace std;

int main ()
{
//clrscr();
int a[100] , i , j , k , loc , min , n ;
cin>>n;
   for(i=0;i<n;i++)
     cin>>a[i];
   for(i=0;i<=n-2;i++)
    {
      min = a[i];
      loc=i;
       for(j=i+1;j<=n-1;j++)
      {
      if(min>a[j])
       {
       min=a[j];
       loc=j;
       }
      }
       k=a[i];
       a[i]=a[loc];
       a[loc]=k;
    }
    for(i=0;i<n;i++)
	{
	  cout<<a[i]<<" ";
	}
getch();
}
