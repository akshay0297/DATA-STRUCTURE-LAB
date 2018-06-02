#include<iostream.h>
#include<conio.h>

void main ()
{
clrscr();
int a[50][50] , b[50][50] , c[50][50] , i , k , j , n;
cin>>n;
 for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
     {
       cin>>a[i][j];
     }
  }
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
     {
       cin>>b[i][j];
     }
  }
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
     {
      if(a[i][j] > b[i][j])
       {
	 c[i][j]=a[i][j];
       }
       else
	 c[i][j]=b[i][j];
     }
  }
 for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
     {
       cout<<c[i][j]<<" ";
     }
     cout<<endl;
  }
getch();
}