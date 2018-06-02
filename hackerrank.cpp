#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<process.h>


using namespace std;


int main()
{
    int siz = 10;
    int *a;
    a = new int[siz];
    // int *p = a;
    int i;
    for(i=0 ; i<siz ;i++)
        a[i]= i;
   // p[0] = 10 ;
    //for(i=0 ; i<siz ;i++)
      //  cout<<a[i]<<" ";
      while(*a<9)
      {
          a++;
          cout<<*a<<" ";
      }
    cout<<endl;
}
