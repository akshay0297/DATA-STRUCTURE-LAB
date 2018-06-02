#include<iostream>
#include<cstdlib>
#include<process.h>

using namespace std;

class node
{
    int data;
    node *pre;
    node *link;
public:
    void disp(node *);
    node *ins_bef(node *);
    node *ins_aft(node *);
    node *del(node *);
    node *rev(node *);
};
node *head = NULL;
void node :: disp(node *h)
{
    if(h == NULL)
        cout<<"List is empty !"<<endl;
    else
    {
        node *trev;
        for(trev = h ; trev != NULL ; trev = trev->link)
            cout<<trev->data << " ";
        cout<<endl;
    }
}
node *node :: ins_bef(node *h)
{
    node *temp = new node();
    cout<<"Enter the element before which you want to insert the node : ";
    int f ; cin>>f;
    cout<<"Enter the value to be inserted : ";
    cin>>temp->data;
    temp->link = NULL;
    temp->pre = NULL;
    if(h == NULL)
       {
          h = temp;
          return h;
        }
    else
      if(h->link == NULL && h->data == f)
    {
        h->pre = temp;
        temp->link = h;
        h = temp;
        return h;
    }
    else
    {
        node *curr;
        node *prev;
        for(curr = h ; curr->data=f && curr!= NULL ;prev = curr , curr = curr->link);
        if(curr == NULL)
        {
            prev->link = temp;
            temp->pre = prev;
        }
        else
        {
            temp->link = curr;
            curr->pre = temp;
            temp->pre = prev;
        }
        return h;
    }
}
node *node :: ins_aft(node *h)
{
    node *temp = new node();
    int f ;
    cout<<"Enter the value to be inserted : ";
    cin>>temp->data;
    temp->link = NULL;
    temp->pre = NULL;
    if(h == NULL)
    {
       // cout<<"A"<<endl;
        h = temp;
        return h;
    }
    else
    {
        cout<<"Enter the element after which you want to insert the node : ";
        cin>>f;
        //cout<<"B"<<endl;
        node *curr;
        for(curr = h ;  curr!= NULL ; curr = curr->link)
        {
            if(curr->data == f )
        {
          //  cout<<"C"<<endl;
            temp->link = curr->link;
            curr->link = temp;
            temp->pre  = curr;
            //temp->link->pre = temp;
        }
        }
        return h;
    }
}
node *node :: del(node *h)
{
    cout<<"Enter the value to be deleted : ";
    int d; cin>>d;
    node *curr;
    node *prev;
    if(h == NULL)
      {
        cout<<"List is empty !"<<endl;
        return NULL;
      }
    else if(h->link == NULL && h->data == d)
    {
        node *temp = h;
        delete temp;
        h = NULL;
        cout<<"Value deleted !"<<endl;
        return h;

    }
    else
    {
        for(curr = h ; curr->data = d && curr !=NULL ; prev = curr , curr = curr->link);
        if(curr == NULL)
            cout<<"Value not found !"<<endl;
        else
        {
            prev->link = curr->link;
            curr->link->pre = prev;
            delete curr;
        }
        return h;
    }
}
node *node :: rev(node *h)
{
   node *a ;
   node *b;
   node *temp;
   a = b = temp = NULL;
   if(h == NULL)
   {
       cout<<"List is empty ! "<<endl;
       return NULL;
   }
   else
    if(h->link == NULL)
   {
       return h;
   }
   else
   {
       while(h != NULL)
       {
           b = a;
           a = h;
           h = h->link;
           temp = h;
           a->link = b;
           a->pre = temp;
           temp->link = a;
       }
       h = temp;
       return h;
   }
}

int main()
{
    node c;
    char op;
    do
    {
      cout<<"Enter 1 to insert after ! "<<endl;
      cout<<"Enter 2 to insert before !"<<endl;
      cout<<"Enter 3 to delete ! "<<endl;
      cout<<"Enter 4 to reverse ! "<<endl;
      cout<<"Enter 5 to traverse ! "<<endl;
      cout<<"Enter 6 to exit !"<<endl;
      int ch ;
      cout<<"Enter your choice : ";
      cin>>ch;
      switch(ch)
      {
          case 1 : head = c.ins_aft(head);
                    break;
          case 2 : head = c.ins_bef(head);
                   break;
          case 3 : head = c.del(head);
                   cout<<"After deletion : "<<endl;
                   c.disp(head);
                   break;
          case 4 : head = c.rev(head);
                   cout<<"Reversed list is  : "<<endl;
                   c.disp(head);
                   break;
          case 5 : c.disp(head);
                   break;
          case 6 : exit(0);
                   break;
          default : cout<<"Invalid option ! "<<endl;
                    break;
      }
      cout<<"To continue press Y/y : ";
      cin>>op;
    }while(op == 'y' || op == 'Y');
}
