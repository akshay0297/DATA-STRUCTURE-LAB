#include<iostream>
#include<cstring>
#include<stack>
#include<stdio.h>

using namespace std;

int getWeight(char ch) {
   switch (ch) {
      case '/':
      case '*': return 2;
      case '+':
      case '-': return 1;
      default : return 0;
   }
}

void infix2prefix(char infix[], char prefix[], int size) {
   stack<char> s;
   int weight;
   int i = 0;
   int k = 0;
   char ch;
   while (i < size) {
      ch = infix[i];
      if (ch == '(') {
         s.push(ch);
         i++;
         continue;
      }
      if (ch == ')') {
         while (!s.empty() && s.top() != '(') {
            prefix[k++] = s.top();
            s.pop();

         }
         if (!s.empty()) {
            s.pop();
         }
         i++;
         continue;
      }
      weight = getWeight(ch);
      if (weight == 0) {
         prefix[k++] = ch;

      }
      else {
         if (s.empty()) {
            s.push(ch);
         }
         else {
            while (!s.empty() && s.top() != '(' &&
                  weight <= getWeight(s.top())) {
               prefix[k++] = s.top();
               s.pop();

            }
            s.push(ch);
         }
      }
      i++;
   }
   while (!s.empty()) {
      prefix[k++] = s.top();
      s.pop();
   }
   prefix[k] = 0;
}
int main() {
   char  infix[100];
   cout<<"Enter infix string :";
   gets(infix);
   int size = strlen(infix);
   char prefix[size];
   infix2prefix(strrev(infix),prefix,size);
   cout<<"\nInfix Expression :: "<<strrev(infix);
   cout<<"\nprefix Expression :: "<<strrev(prefix);
   cout<<endl;
   return 0;
}
