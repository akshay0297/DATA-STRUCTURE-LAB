#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>

using namespace std;

class tree
{

public:
     tree *lchild;
    int data;
    tree *rchild;
    tree()
    {
        lchild = NULL ;
        rchild = NULL;
    }
    tree *insert(tree * , int ele);
    void pr(tree *);
    void po(tree *);
    void ino(tree *);
    tree* parent(tree * , int , tree *);
    int depth(tree *);
    int leaf(tree *);
    int ancestors(tree *, int ele);
};
tree *root = NULL;
tree *tree :: insert(tree *r , int ele)
{
    tree *temp =new tree();
    temp->data = ele;
    if(r == NULL)
    {
        r = temp;
        return r;
    }
    else
    {
        char dir[20];
        cout<<"\n Enter the direction in UPPER CASE (only in terms of L and R): ";
        gets(dir);
        tree *curr = r;
        tree * prev = NULL;
        int i;
        for(i=0 ; i<strlen(dir) && curr != NULL ; i++)
        {
            prev = curr;
            if(dir[i] == 'L')
                curr = curr->lchild;
            else
                curr = curr->rchild;
        }
        if(curr != NULL || i!= strlen(dir))
        {
            cout<<"Insertion not possible ! ";
            delete temp;
            return r;
        }
        else
        {
            if(dir[i-1] == 'L')
                prev->lchild = temp;
            else
                prev->rchild = temp;
        }
        return r;
    }
}
void tree :: ino(tree *ptr)
{
  int top = -1;
  tree *stack[10];
  do
  {
      for(; ptr ; ptr = ptr->lchild )
      {
          stack[++top] = ptr;
      }
      if(top >= 0)
        ptr = stack[top--];
      else
        break;
      cout<<ptr->data<<" ";
      ptr = ptr->rchild;
  }while(1);
}
void tree :: pr(tree *ptr)
{
  int top = -1;
  tree *stack[10];
  do
  {
      for(; ptr ; ptr = ptr->lchild )
      {
          cout<<ptr->data<<" ";
          stack[++top] = ptr;
      }
      if(top >= 0)
        ptr = stack[top--];
      else
        break;
      ptr = ptr->rchild;
  }while(1);
}
void tree::po(tree*r)
{
   tree *temp=r;
   tree *p;
   int top=-1;
   tree *s[20];
   while(1)
   {
      while(temp)
      {
	 if(temp->rchild)  s[++top]=temp->rchild;
	 s[++top]=temp;
	 temp=temp->lchild;
      }
      if(top>=0)
      temp= s[top--] ;
      else break;
      if(top>=0)
    {  p=s[top--]; }
      else
     { cout<<temp->data;
       break;
     }
     if(p==temp->rchild)
     {
	  s[++top]=temp;
	  temp=temp->rchild;
     }
     else
     {
	cout<<temp->data<<" ";
	s[++top]=p;
	temp=NULL;
     }
   }
 }
tree* tree::parent(tree *curr , int ele , tree *prev)
{
	if(curr!=NULL)
	{
		parent(curr->lchild, ele, curr);
		if(ele==curr->data)
		{
			cout<<"\n parent : "<<prev->data;
			return prev;
		}
		parent(curr->rchild, ele , curr);
	}
}
int tree::depth(tree *ptr)
{
int ldepth,rdepth;
if(ptr==NULL)	return 0;
else
    {   ldepth=depth(ptr->lchild);
	rdepth=depth(ptr->rchild);
	if(ldepth>rdepth) 	return ldepth+1;
	else 		return rdepth+1;
    }
}
int tree::ancestors(tree*r,int ele)
{
    if(r==NULL) return 0;
    if(ele==r->data) return 1;
    if(ancestors(r->lchild,ele)||ancestors(r->rchild,ele))
    {
       cout<<r->data<<" ";
       return 1;
    }
    return 0;
}
int tree :: leaf(tree *root)
{
    if(root == NULL)
        return 0;
    else if(root->lchild == NULL && root->rchild == NULL)
        return 1;
    else
        return (leaf(root->lchild) + leaf(root->rchild));
}
int main()
{
    tree d;
    cout<<"\nAdding 10,20,30,40,50,60,70,80 to the tree !";
    root = d.insert(root , 10);
    root = d.insert(root , 20);
    root = d.insert(root , 30);
    root = d.insert(root , 40);
    root = d.insert(root , 50);
    root = d.insert(root , 60);
    root = d.insert(root , 70);
    root = d.insert(root , 80);
    cout<<"\nPre-Order display : "<<endl;
    d.pr(root);
    cout<<"\nIn-order display : "<<endl;
    d.ino(root);
    cout<<"\nPost-Order display : "<<endl;
    d.po(root);
    tree *par = d.parent(root , 40 , root);
     cout<<"\nFinding Ancestors  !"<<endl;
    int anc = d.ancestors(root , 40);
    cout<<anc<<" ";
    int dp = d.depth(root);
    cout<<"\nDepth  : " <<dp<<endl;
    int r;
    r = d.leaf(root);
    cout<<"\nNumber of leaf nodes : ";
    cout<<r;
}
