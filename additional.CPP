#include<iostream.h>
#include<conio.h>
#include<string.h>
class tnode
{
  int data;
  tnode *llink;
  tnode *rlink;
  public:
  tnode(int ele=0)
  {
    data=ele;
    llink=NULL;
    rlink=NULL;
  }
  tnode* insert(int,tnode*);
  void display(tnode*,int);
  tnode* copy(tnode*);
  int equal(tnode*,tnode*);
  int mirror(tnode*,tnode*);
};
tnode *root=NULL,*root1=NULL;
int tnode::mirror(tnode*r,tnode*r1)
{
   return((!r&&!r1)||((r&&r1)&&(r->data==r1->data)&&(mirror(r->llink,r1->rlink))&&mirror(r->rlink,r1->llink)));
}
int tnode::equal(tnode*r,tnode*r1)
{
    return((!r&&!r1)||((r&&r1)&&(r->data==r1->data)&&(equal(r->llink,r1->llink))&&equal(r->rlink,r1->rlink)));
}
tnode* tnode::copy(tnode*r)
{
  if(r==NULL)return NULL;
  else
 { tnode *temp=new tnode;
  temp->data=r->data;
  temp->llink=copy(r->llink);
  temp->rlink=copy(r->rlink);
  return temp;
  }
}
void tnode::display(tnode *r,int lvl)
{
      int i;
      if(r==NULL)
      return;
      display(r->rlink,lvl+1);
      for(i=0;i<lvl;i++)
      cout<<" ";
      cout<<r->data<<endl;
      display(r->llink,lvl+1);
 }
tnode* tnode::insert(int item,tnode* r)
{
   tnode *temp=new tnode(item);
   if(r==NULL)
   { r=temp;
     return r;
   }
   else{
   tnode *curr=r;
   tnode *prev=NULL;
   char dir[10];
   cout<<"\nEnter the direction:";
   cin>>dir;
   for(int i=0;i<strlen(dir)&&curr!=NULL;i++)
   {
     prev=curr;
     if(dir[i]=='L')
     curr=curr->llink;
     else
     curr=curr->rlink;
   }
   if(curr!=NULL||i!=strlen(dir))
   {
     cout<<"\ninsertion not possible";
     delete(temp);
     return r;
   }

   if(dir[i-1]=='L')
   prev->llink=temp;
   else
   prev->rlink=temp;

  }
  return r;
}
void main()
{     clrscr();
tnode ob;
root=ob.insert(1,root);
root=ob.insert(2,root);
root=ob.insert(3,root);
root=ob.insert(4,root);
root=ob.insert(5,root);

ob.display(root,0);
root1=ob.insert(1,root1);
root1=ob.insert(2,root1);
root1=ob.insert(3,root1);
root1=ob.insert(4,root1);
root1=ob.insert(5,root1);

ob.display(root1,0);
cout<<"\n";
if(ob.equal(root,root1)==1)
cout<<"equal";
else
cout<<"not equal";
cout<<"\n";
if(ob.mirror(root,root1)==1)
cout<<"mirror";
else
cout<<"not mirror";
getch();
}
