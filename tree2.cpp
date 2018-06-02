#include<iostream>
#include<cstdlib>

using namespace std;

class tree
{
   int data ;
   tree *lchild ;
   tree *rchild;
public:
     tree *create();
     void printin(tree *);
};
tree *tree :: create()
{
    tree *root;
    cout<<"\nEnter Data (-1 for No data) : ";
    int n; cin>>n;
    if(n == -1)
        return NULL;
    root = new tree;
    root->data = n;
    cout<<"\nEnter Left child : ";
    root->lchild = create();
    cout<<"\nEnter Right child : ";
    root->rchild = create();
    return root;
}
void tree :: printin(tree *root)
{
    if(root != NULL)
    {
        printin(root->lchild);
        cout<<root->data<<" ";
        printin(root->rchild);
    }
}
int main()
{
    tree a;
    tree *head = a.create();
    cout<<"\nIn-Order Display : ";
    a.printin(head);
}
