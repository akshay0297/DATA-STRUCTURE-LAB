#include<iostream>
#include<conio.h>
#include<cstdlib>

using namespace std;

class list
{
   int data ;
   list *link;
public :
  void disp();
  void ins_end();
  void ins_front();
  int count();
  void del_front();
  void del_end();
  void del_spec();
  void ins_before();
  void ins_after();
};
list *first = NULL;
list *curr = NULL;

void list :: ins_end()
{
    list *temp = new list();
    cout<<"Enter Data : ";
    cin>>temp->data;
    temp->link=NULL;
    if(first == NULL)
    {
        first = temp;
    }
    else
    {
        for(curr= first ; curr->link != NULL ; curr = curr->link);
        curr->link = temp;
    }
}
void list :: ins_front()
{
    list *temp = new list();
    cout<<"Enter Data : " ;
    cin>>temp->data;
    temp->link = NULL;
    if(first == NULL)
    {
        first = temp;
    }
    else
        {
            temp->link = first ;
            first = temp;
        }
}
int list :: count()
{
    int c=0;
    for(list *curr = first ; curr !=NULL ; curr= curr->link)
    {
        c++;
    }
    return c;
}
void list ::  disp()
{
    if(first == NULL)
    {
        cout<<"List is Empty !";
    }
    else
        for(list *curr=first ; curr!=NULL ; curr = curr->link)
            cout<<curr->data<<"\t";
}
void list :: del_front()
{
    if(first == NULL)
        cout<<"List is empty ! ";
    else
    {
        list *temp;
        temp = first;
        first = first->link;
        delete temp;
    }
}
void list :: del_end()
{
    list *prev ;
    list *last;
    if(first == NULL)
    {
        cout<<"List is empty ";
    }
    else if(first->link == NULL)
    {
        list *temp;
        temp = first;
        first = NULL ;
        delete temp;
    }
    else
    {
        for(last = first ; last->link != NULL ; prev = last , last = last->link);
        list *temp;
        temp = last ;
        prev->link = NULL ;
        delete temp;
    }
}
void list :: del_spec()
{
   if(first == NULL)
   {
       cout<<"List is empty !" ;
   }
   else
   {
       cout<<"Enter the value to be deleted : ";
       int e ;
       cin>>e;
       if(first->data == e)
        del_front();
       else
       {
           list *prev;
         for(list *curr = first ; curr->data != e && curr->link != NULL ; prev = curr , curr = curr->link);
                if(curr->link == NULL)
                {
                   if(curr->data == e)
                   {
                      prev->link = curr->link;
                      delete curr ;
                      cout<<"Value deleted ! ";
                   }
                   else cout<<"Element Not Found ! "<<endl;
                }
         else
            {
                prev->link = curr->link;
                delete curr ;
                cout<<"Value deleted ! ";
            }
       }
   }
}
void list :: ins_after()
{
    list *temp ;
    cout<<"Enter the Value after which you want to insert a node : ";
    int af; cin>>af;
    cout<<"Enter the value to be inserted : ";
    cin>>temp->data;
    temp->link = NULL;
    if(first == NULL)
    {
      first = temp;
    }
    else
        {
            list *curr;
          //  list *prev;
            for(curr = first ; curr->data = af && curr != NULL ; curr = curr->link);
            temp->link = curr->link;
            curr->link = temp;
        }
}
void list :: ins_before()
{
    list *temp ;
    cout<<"Enter the Value before which you want to insert a node : ";
    int bf; cin>>bf;
    cout<<"Enter the value to be inserted : ";
    cin>>temp->data;
    temp->link = NULL;
    if(first == NULL)
    {
      first = temp;
    }
    else
        if(first->link == NULL && first->data == bf)
        {
          temp->link = first ;
          first = temp;
        }
        else
        {
            list *curr;
            list *prev;
            for(curr = first ; curr->data = bf && curr != NULL ;prev = curr , curr = curr->link);
            temp->link = curr->link;
            prev->link = temp;
        }
}
int main()
{
    list a ;
    char op;
  do
  {
    cout<<"Enter 1 to insert in end ! "<<endl;
    cout<<"Enter 2 to insert in front ! "<<endl;
    cout<<"Enter 3 to insert before an element ! "<<endl;
    cout<<"Enter 4 to insert after an element ! "<<endl;
    cout<<"Enter 5 to delete from the end ! "<<endl;
    cout<<"Enter 6 to delete from the front ! "<<endl;
    cout<<"Enter 7 to delete  Specific element ! "<<endl;
    cout<<"Enter 8 to display ! "<<endl;
    cout<<"Enter 9 to exit !";
    int ch ;
    cout<<"Enter your choice : ";
    cin>>ch;
    switch(ch)
    {
        case 1 : a.ins_end();
                 a.disp();
                 break;
        case 2 : a.ins_front();
                 a.disp();
                 break;
        case 3 : a.ins_before();
                 a.disp();
                 break;
        case 4 : a.ins_after();
                 a.disp();
                 break;
        case 5 : a.del_end();
                 a.disp();
                 break;
        case 6 : a.del_front();
                 a.disp();
                 break;
        case 7 : a.del_spec();
                 a.disp();
                 break;
        case 8 : a.disp();
                 break;
        case 9 : exit(0);
                break;
        default: cout<<"Invalid option !";
    }
    cout<<endl;
    cout<<"To continue Press Y/y or press N/n : ";
    cin>>op;
  }while(op == 'Y' || op == 'y');
}
