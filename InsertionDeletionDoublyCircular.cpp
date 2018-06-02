//double linked circular lists

#include <iostream>
using namespace std;
class node{
	int info;
	node *next;
	node *prev;
	node *first;

public:
	node(){
		first = NULL;
	}
	void add(int);
	void del();
	void display();

};
void node::add(int key){
	
	int elem;
	cout<<"\n\nEnter the information for the node: ";
	cin>>elem;
	
	node *temp = new node;
	temp->info = elem;
	temp->next = temp;
	temp->prev = temp;

	switch(key){
		case 1: //insert beginning
			if(first == NULL)
				first = temp;
			else{
				temp->next = first;
				first->prev->next = temp;
				temp->prev = first->prev;
				first->prev = temp;
				
				first = temp;
			}
			cout<<"\nElement "<<temp->info<<" added in the beginning."<<endl;
			return;
		case 2: //insert end
			if(first == NULL)
				first = temp;
	
			else{
				
				first->prev->next = temp;
				temp->prev = first->prev;
				temp->next = first;
				first->prev = temp;
			}
			cout<<"\nElement "<<temp->info<<" added in the end."<<endl;
			return;	
	}
	
}

void node::del(){
	int elem;
	if(first == NULL){
		cout<<"\nList Empty!";
		return;
	}
	cout<<"\nEnter the element to be deleted: ";
	cin>>elem;

	node *cur = first;
	while(cur->info!=elem)
		cur = cur->next;
    if(cur == first)
		first = cur->next;
		
	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;
	
	delete cur;

	cout<<"\nElement "<<elem<<" deleted.";
}
void node::display(){
	if(first == NULL){
		cout<<"\nList Empty!";
		return;
	}
	else{
		cout<<"\n\nDisplaying the list: ";
		node *cur = first; 
		cout<<cur->info<<" ";
		cur = cur->next;  //for the case where cur = first
		while(cur!=first){
			cout<<cur->info<<" ";
			cur=cur->next;
		}
	}
}
int main(){
	node N;
	int ch,ch1;
	bool goAgain = true;
	do{
		cout<<"\n\n------MENU-----"<<endl;
		cout<<"\n1. Insert an element.";
		cout<<"\n2. Delete an element.";
		cout<<"\n3. Display the list.";
		cout<<"\n4. Exit.";
		cout<<"\n Enter a choice: ";
		cin>>ch;
		
		switch(ch){
			case 1:
			cout<<"\n\n\t\t-----SUB-MENU-FOR-ADDITION-----"<<endl;
			cout<<"\n\t\t1. Insert element at the beginning.";
			cout<<"\n\t\t2. Insert element at the end.";
			cout<<"\n\t\t Enter a choice: ";
			cin>>ch1;
			switch(ch1){
				case 1:
					N.add(1);
					break;
				case 2:
					N.add(2);
					break;
			}
			break;

			case 2:
			N.del();
			break;

			case 3:
			N.display();
			break;

			case 4:
			goAgain = false;
			break;


		}


	
	}while(goAgain == true);



	return 0;
}