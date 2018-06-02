#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<process.h>

using namespace std;

class list
{
    int data;
    list *prev;
    list *link;
public:
    void disp(list *);
    list *make(list * , int);
    list* conc(list * , list *);
};
list *x1 = NULL;

void list :: disp(list *h)
{
    if(h == NULL)
           cout<<"List is empty !"<<endl;
    else
        {
            for(list *curr = h ; curr != NULL ; curr = curr->link)
           cout<<curr->data<<" ";
        }
        cout<<endl;

}
list* list :: make(list *h , int ele)
{
    list *temp = new list;
    temp->data = ele;
    temp->prev = NULL;
    temp->link = NULL;
    if(h == NULL)
        {
            h = temp;
            return h;
        }
    else
    {
        list *curr;
        for(curr = h ; curr->link!= NULL ; curr = curr->link);
        curr->link = temp;
        temp->prev = curr;
        return h;
    }
}
list* list :: conc(list *l , list *m)
{
    if(l == NULL && m != NULL)
       {
           l = m;
           return l;
       }
    else
        if(m == NULL && l != NULL)
    {
        return (l);
    }
    else
    {
        list *curr;
        for(curr = l ; curr->link !=NULL ; curr = curr->link);
            curr->link = m;
            m->prev = curr;
        return l;
    }
}
int main()
{
    list a;

    list *x2 = NULL;
    list *x3 = NULL;
    cout<<"Enter the number of values to be inserted in list 1 : ";
    int n;
    cin>>n;
    for(int i = 0 ; i<n ; i++)
    {
        cout<<"\n Enter the value to be inserted : ";
        int p;
        cin>>p;
        x1=a.make(x1 , p);
    }
    cout<<"Enter the number of values to be inserted in list 2 : ";
    int k;
    cin>>k;
    for(int i = 0 ; i<k ; i++)
    {
        cout<<"\n Enter the value to be inserted : ";
        int d;
        cin>>d;
       x2= a.make(x2 , d);
    }
    cout<<"You Entered list 1 as : "<<endl;
    a.disp(x1);
    cout<<"And list 2 as : "<<endl;
    a.disp(x2);
    x1 = a.conc(x1 , x2);
    cout<<"The concatenated  list is : "<<endl;
    a.disp(x1);
}
