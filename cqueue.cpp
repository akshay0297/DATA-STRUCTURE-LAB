#include<iostream>
#include<conio.h>
#include<cstring>
#include<stdio.h>
const int Max = 10;
using namespace std;

class cq
{
    int f , r  , a[Max];
public:
    cq()
    {
        f = r = -1;
    }
    void ins (int ele);
    int del();
    void disp();
};
void cq :: ins(int ele)
{
    if((r+1)%Max == f)
    {
        cout<<"Queue is Full !";
    }
        r = (r+1)%Max ;
        a[r] = ele ;
        if(f == -1)
            f=0;
}
void cq :: disp()
{
    if(f == -1)
    {
        cout<<"Queue is empty !";
    }
    else
    {

        if(f>r)
        {

            for(int i=f ; i<Max ; i++)
                cout<<a[i]<<"\t";
        }
        if(f<r)
        for(int i=0 ; i<=r ; i++)
           cout<<a[i]<<"\t";
    }
}
int cq :: del()
{

}
