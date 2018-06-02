#include <iostream>
#include <cstdlib>
using namespace std;
class node{
public:
	int coef, expo;
	node *next;

	void display(node*);
	void attach(int,int,node*);
	void read_poly(node*);
	void add_poly(node*,node*,node*);

};
void node::attach(int c, int e, node* first){
	node *temp = new node;
	temp->next = first;
	temp->coef = c;
	temp->expo = e;

	if(first->coef == 0){
		first->next = temp;
		(first->coef)++;
		return;
	}

	node *cur = first->next;
	while(cur->next!=first)
		cur = cur->next;

	cur->next = temp;
	(first->coef)++;
	return;


}
void node::read_poly(node *first){
	int c, e, i=1;
	cout<<"\nEnter -999 as coefficient to end the polynomial.";
	while(1){
		cout<<"\nEnter the term "<<i++<<": ";
		cout<<"\nCoefficient: ";
		cin>>c;
		if(c == -999)
			break;
		cout<<"\nPower of x: ";
		cin>>e;
		attach(c,e,first);

	}
	return;
}
void node::add_poly(node *poly1, node *poly2 , node *c){

    node *a = poly1->next;
    node *b = poly2->next;

	int co, ex, com;
	while(a!=poly1 || b!=poly2){
		if(a->expo == b->expo)
			com = 0;
		else if((a->expo)>(b->expo))
			com = 1;
		else
			com = -1;

		switch(com){
			case 0:
				co = a->coef + b->coef;
				if(co!=0)
                                    attach(co,a->expo,c);
				a = a->next;
				b = b->next;
				break;

			case 1:
				attach(a->coef,a->expo,c);
				a = a->next;
				break;

			default:
				attach(b->coef,b->expo,c);
				b = b->next;
				break;
		}
	}

	while(a!=poly1){ //to add the remaining elements
                attach(a->coef,a->expo,c);
		a = a->next;
	}
	while(b!=poly2){
		attach(b->coef, b->expo,c);
		b = b->next;
	}

}
void node::display(node *first){
	if(first->coef == 0){
		cout<<"\nPolynomial doesn't exist.";
		return;
	}
	node *cur = first->next;
        while(cur!=first){
		if((cur->coef)<0)
			cout<<cur->coef<<"x^"<<cur->expo<<" ";
		else
			cout<<"+"<<cur->coef<<"x^"<<cur->expo<<" ";

		cur = cur->next;
	}
	return;
}
int main(){

	node *poly1, *poly2, *poly_sum, p; //creating header nodes
	poly1 = new node;
	poly2 = new node;
	poly_sum = new node;

	poly1->coef = poly2->coef = poly_sum->coef = 0; //coef acting like the counter for header nodes

	cout<<"\nEnter the first polynomial: ";
	p.read_poly(poly1);
	cout<<"\nDisplaying the first polynomial: ";
	p.display(poly1);

	cout<<endl;
	cout<<"\nEnter the second polynomial: ";
	p.read_poly(poly2);
	cout<<"\nDisplaying the second polynomial: ";
	p.display(poly2);

    cout<<endl;
    p.add_poly(poly1,poly2,poly_sum); //error prone line
	cout<<"\nAfter addition, the polynomial becomes: ";
	p.display(poly_sum);


	return 0;

}
