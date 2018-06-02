#include<iostream>
#include<process.h>
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
  void del_front();
  void del_end();
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
int main()
{
    list q;
    list s;
    char fn;
    char sd;
    do
    {
    cout<<"Enter q for Queue operation !"<<endl;
    cout<<"Enter s for stack operation !"<<endl;
    char op;
    cin>>op;
    switch(op)
    {
        case 'q' : do{
                    cout<<"1.Insert \t 2.Delete \t 3.Display \t 4.Exit \t "<<endl;
                    int ch;

                    cin>>ch;
                    switch(ch)
                    {
                        case 1 : q.ins_front();
                                 break;
                        case 2 : q.del_end();
                                 break;
                        case 3 : q.disp();
                                 break;
                        case 4 : exit(0);
                                 break;
                        default: cout<<"Invalid Option !"<<endl;
                    }
                    cout<<"To continue With Queue enter Y/y :";
                    cin>>sd;
                }while(sd == 'y' || sd == 'Y');


         case 's' : do{
                    cout<<"1.Insert \t 2.Delete \t 3.Display \t 4.Exit \t "<<endl;
                    int ch;
                    cin>>ch;
                    switch(ch)
                    {
                        case 1 : s.ins_front();
                                 break;
                        case 2 : s.del_front();
                                 break;
                        case 3 : s.disp();
                                 break;
                        case 4 : exit(0);
                                 break;
                        default: cout<<"Invalid Option !"<<endl;
                    }
                    cout<<"To continue With Stack enter Y/y :";
                    cin>>sd;
                }while(sd == 'y' || sd == 'Y');

            default : cout<<"Invalid Choice ! ";
    }
    cout<<"Enter y/Y to continue with the program : ";
    cin>>fn;
    }while(fn == 'y' || fn == 'Y');
}
