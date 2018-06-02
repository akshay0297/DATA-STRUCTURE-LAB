#include<iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;

class fast
{
public :
    int row , col ,val ;
    void create(int a[][10] , int r , int c);
    void fasttranspose(fast b[] , fast cd[]);
};
void fast :: create (int a[][10] , int r , int c)
{
    fast b[100];
    int k=0;
    for(int i=0 ; i<r ; i++)
    {
        for(int j=0 ; j<c ; j++)
        {
            if(a[i][j] !=0)
            {
                k++;
                b[k].row = i;
                b[k].col = j;
                b[k].val = a[i][j];
            }
        }

    }
        b[0].row = r;
        b[0].col = c;
        b[0].val = k;
        fast cd[100];
    //fasttranspose(b , cd);
}
void fast :: fasttranspose(fast b[] , fast cd[])
{

    int count[100] = {0} , pos[100] = {0};
    int m;
    for(int i=1; i<=b[0].val; i++)
    {
        count[b[i].col]++;
    }
    for(int j=1; j<=b[0].col ; j++)
    {
        pos[j] = pos[j-1] + count[j-1];
    }

    for(int i=1 ; i<=b[0].val;i++)
    {
        m = pos[b[i].col]++;
        cd[m].row = b[i].col;
        cd[m].col = b[i].row;
        cd[m].val = b[i].val;
    }
    cd[0].row = b[0].col;
    cd[0].col = b[0].row;
    cd[0].val = b[0].val;
    cout<<"Row \t Column \t  Value "<<endl;

    for(int i=0 ; i<=cd[0].val ; i++)
    {
        cout<<cd[i].row<<" \t "<<cd[i].col<<" \t "<<cd[i].val<<endl;
    }

}
int main()
{
    fast d;

   // fast  x[100];

    cout<<"Enter the Row and Column of the Matrix : "<<endl;
    int r , c;
    cin>>r >> c;
    cout<<"Enter The Matrix : "<<endl;
    int a[10][10];
    for(int i=0 ; i<r ; i++)
        for(int j=0 ; j<c ; j++)
        cin>>a[i][j];
    d.create(a , r , c);
    fast b[100] ;
    fast  cd[100];
    d.fasttranspose(b , cd);
  //d.fasttranspose(l , x);
}
