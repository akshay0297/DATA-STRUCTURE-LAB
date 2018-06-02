#include<iostream>
#include<conio.h>
using namespace std;

int  main()
{
//    clrscr();
    int a[100] , n , i , j , temp;
    cout<<"Enter the Number of elements of array "<<endl;

    cin>>n;
cout<<"Enter the Elements : "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(i=1;i<n;i++)
    {
        j=i;

        while(j>0 && a[j]<a[j-1])
        {
            temp=a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
            j--;
        }

    }
cout<<"The sorted array is  : ";
     for(i=0;i<n;i++)
    {
        cout<<a[i]<<'\t';
    }
    getch();
}
