#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<process.h>

using namespace std ;

class queue
{
    int r, f ;
    int max = 20 ;
    int a[20];
public :
    queue()
    {
        f = 0;
        r = -1;
    }
   void insert(int ele)
    {
        if (r == max - 1)
            cout<<"Queue is Full !";
        else
        {
            a[++r] = ele;
        }
        f=0;
    }
 int del()
    {
        if(f == r +1)
        {
            cout<<"Queue is Empty !";
            return -1;
        }
        else
        {
            int val;
            val = a[f++];
            return val;
        }
    }

 void disp()
    {
        if (f == r+1)
        {
            cout<<"Queue is Empty !";
        }
        else
            for (int i = f; i <=r; i++)
            {
                cout<<a[i]<<"\t";
            }
    }
};

int main()
{
        char p;
        queue q ;
        do
        {
            cout<<"Enter 1 to insert element in the queue !"<<endl;
            cout<<"Enter 2 to delete an element from the queue !"<<endl;
            cout<<"Enter 3 to display !"<<endl;
            cout<<"Enter 4 to exit ! "<<endl;
            int ch;
            cout<<"Enter your choice : ";
            cin>>ch;
            switch (ch)
            {
                case 1:
                   cout<<"Enter Element to be inserted : ";
                    int ele;
                    cin>>ele;
                    q.insert(ele);
                    break;
                case 2:
                    int pop;
                    pop = q.del();
                     cout<<pop<<endl;
                    break;
                case 3:
                    q.disp();
                    break;
                case 4:
                    exit(0);
                    break;
                default:
                    cout<<"Invalid Option !";
                    break;
            }
            cout<<" Do you want to continue Y/N : ";
            cin>>p;
        } while(p == 'y' || p == 'Y');
}
