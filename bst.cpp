#include<iostream>
#include<process.h>
#include<conio.h>
using namespace std;
class bst
{
	bst *lchild;
	int data;
	bst *rchild;
public:
	bst(int ele=0)
	{
		lchild=NULL;
		rchild=NULL;
		data=ele;
	}
	void insert(int);
	bst *search(bst * , int);
	void display(bst *root);
	bst *del(bst * , int);
	void level(bst *);
};
bst *root=NULL;
void bst::insert(int ele)
{
	bst *temp=new bst(ele);
	if(root==NULL){root=temp; return;}
	bst *curr=root,*prev=NULL;
	while(curr)
	{
		prev=curr;
		if(temp->data<curr->data)	curr=curr->lchild;
		else if(temp->data>curr->data)	curr=curr->rchild;
		else
		{
		    cout<<"Insertion is not possible";
			return;
		}
	}
	if(temp->data>prev->data)		prev->rchild=temp;
	else if(temp->data<prev->data)	prev->lchild=temp;
}
 bst *bst :: search(bst *r,int key)
{
  if (!r) return NULL;
  if (key==r->data) return r;
  if (key<r->data)
      return search(r->lchild,key);
  return search(r->rchild,key);
}
void bst :: display(bst *ptr)
{
    if (ptr)
    {
        display(ptr->lchild);
        cout<<ptr->data<<" ";
        display(ptr->rchild);
    }
}
void bst :: level (bst *ptr)
{
    int front=-1;
    int rear=-1;
    bst *Q[10];
    if(!ptr)   return;
    Q[++rear]=ptr;
    do
    {
	ptr=Q[++front];
 	   cout<<ptr->data<<" ";
	    if(ptr->lchild)      Q[++rear]=ptr->lchild;
	    if(ptr->rchild)     Q[++rear]=ptr->rchild;
    }while(front!=rear);
}
bst *bst::del(bst*r,int ele)
{
   bst *prev,*curr,*q,*suc;
   if(r==NULL)
   {
      cout<<"empty";
      return r;
   }
   else
   {
     curr=r;
     prev=NULL;
    while(curr!=NULL&&curr->data!=ele)
    {
       prev=curr;
       if(curr->data<ele)
       curr=curr->rchild;
       else
       curr=curr->lchild;
    }
    if(curr==NULL)
    {
       cout<<"element not found";
       return r;
    }
    if(curr->lchild==NULL)
    q=curr->rchild;
    else
    if(curr->rchild==NULL)
    q=curr->lchild;
    else
    {
      suc=curr->rchild;
      while(suc->lchild!=NULL)
      suc=suc->lchild;
	suc->lchild=curr->lchild;

	q=curr->rchild;
    }
    if(prev==NULL)
    {
       delete curr;
       return q;
    }
    if(curr==prev->lchild)
    prev->lchild=q;
    else
    prev->rchild=q;
    delete curr;
    return r;
   }
}
int main()
{
    bst ob;
    cout<<"Inserting 6 , 25 , 5 , 10 , 30 , 1 !"<<endl;
    ob.insert(6);
    ob.insert(25);
    ob.insert(5);
    ob.insert(10);
    ob.insert(30);
    ob.insert(1);
    cout<<endl;
    cout<<" Displaying In Order "<<endl;
    ob.display(root);
    cout<<endl;
    cout<<"Displaying Level Order : "<<endl;
    ob.level(root);
    if(ob.search(root,35))
    {
       cout<<"\nelement found\n";
    }
    else
    {
       cout<<"\nelement not found\n";
    }
    root=ob.del(root,25);
    cout<<"\nAfter Deleting In Order is : "<<endl;
    ob.display(root);
}
