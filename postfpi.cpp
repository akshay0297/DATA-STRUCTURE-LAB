#include<iostream>
#include<stdio.h>
#include<cstring>
const int MAX = 20;
using namespace std;

class stack
{
    int top ;
    char a[MAX][MAX];
public :
    stack(){top = -1;}
    void push (char[]);
    char* pop();
    void postinf();
};
void stack :: push (char opr[])
{
    if(top == MAX-1)
        cout<<"Stack OverFlow !";
    else
        {
            top++ ;
            strcpy(a[top] , opr);
        }
}
char* stack :: pop()
{
    if(top == -1)
        return "x";
    else
        return (a[top--]);
}
void stack :: postinf()
{

    stack s;
    int c ,cop , j ;
    char opr[20] ,op1[20] , op2[20] ;
    char sym[20] , postfix[20] ;
    cout<<"Enter the postfix expression : " ;
    gets(postfix);
    for(int i=0 ; i<strlen(postfix) ; i++)
    {
        char temp1[20] , temp2[20] , temp3[20] ;
        temp1[0] = postfix[i];
        temp1[1] ='\0';
        strcpy(sym , temp1);
        if(!isalpha(sym[0]))
        {
            strcpy(op2 , s.pop());
            strcpy(op1 , s.pop());
            strcpy(temp3 , "(");
            strcat(temp3 , op1);
            strcat(temp3 , sym);
            strcat(temp3 , op2);
            strcat(temp3 , ")");
            s.push(temp3);
        }
        else
            s.push(temp1);
    }
    cout<<"Resultant infix string is  : "<<s.pop();
}

int main ()
{
  stack sa ;
  sa.postinf();
}
