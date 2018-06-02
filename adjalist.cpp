#include<iostream>
using namespace std;
class list
{
    list* link;
    int data;
public:
    list* insert(list*,int );
    void display(list*);

};
void list::display(list *l)
{

    if(l==NULL)
        cout<<"Empty";
    else
    {
        list *curr;
        for(curr=l;curr!=NULL;curr=curr->link)
            cout<<curr->data<<"->";
    }
}
list* list::insert(list* l,int ele)
{
    list *temp=new list();
    temp->data=ele;
	temp->link=NULL;
    if(l==NULL)
        l=temp;
    else
    {
        list *curr;
        for(curr=l;curr->link!=NULL;curr=curr->link);
        curr->link=temp;
    }

        return l;
}
int main()
{
    list obj;
    cout<<"Enter the number of Vertices : ";
    int n;
    int i,j;
    cin>>n;
    list *a[n];
    int count[n];
    for(i=0;i<n;i++)
        a[i]=NULL;
    for(i=0;i<n;i++)
        count[i]=0;
    int adj[20][20];
    cout<<"Enter adjacency matrix  : "<<endl;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>adj[i][j];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
    {
        if(adj[i][j]==1)
         {
             a[i]=obj.insert(a[i],j);
            count[i]++;
         }

    }
    for(i=0;i<n;i++)
    {
        cout<<" for "<<i<<"adjacent vertex are ";
        obj.display(a[i]);
        cout<<" Degree ="<<count[i];
        cout<<"\n";
    }

}
