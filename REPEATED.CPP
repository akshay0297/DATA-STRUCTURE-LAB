#include<iostream.h>
#include<conio.h>
void repeated ( int b[] , int m );

void  main ()
{
    clrscr();
    int a[100] , n , i , j , pos ;
cout<<"Enter the number of elements : ";
    cin>>n;
    cout<<"Enter the array :"<<endl;
    for(i=0;i<n;i++)
    {
	cin>>a[i];
    }
    repeated(a , n);
    getch();
}
void repeated (int b[] , int m)
{
    int p , q , pos;
    for(p=0 ; p<m ; p++)
    {
	for(q=p+1 ; q<m ;q++)

	{
	    if(b[p] == b[q])
	    {
		pos=q;
		b[pos] = b[pos+1];
		m--;
		q--;
	    }
	}
    }
    cout<<"The final array is : ";
    for(p=0;p<m;p++)
    {
        cout<<b[p]<<'\t';
    }
}
