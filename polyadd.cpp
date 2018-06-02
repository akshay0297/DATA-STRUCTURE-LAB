#include<iostream>
#include<cstdlib>
#include<process.h>


class list
{
    int cof ;
    int exp;
    list *link;
    list *prev;
public:
    list *ins(list * , int , int);
    node disp(list *);
    list *add(list * , list *);
};
list *f = NULL;
list *s = NULL;

list *list :: ins(list *h , int ele , int  c)
{
    list *temp = new list();
    temp->exp = ele;
    temp->cof = c;
    temp->link = temp->prev = NULL;
    if(h == NULL)
    {
        h = temp;
        temp->link = h;
        return h;
    }
    else
        if(h->link == h)
    {
        h->link = temp;
        temp->link = h;
        temp->prev = h;
    }
}
