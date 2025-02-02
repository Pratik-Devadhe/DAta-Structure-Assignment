#include<iostream>
using namespace std;


class BT{

public: 
	
	char data;
	
	BT *lc , *rc;
	
	void create();
	void insert(BT * , BT *);
	void display(BT *);
	void display1(BT *);
	void display2(BT *);



}*root;

void BT::create(){

	root = new BT;
	
	
	
	int ch = 5;
	
	do{
	
	if(ch == 5){
	
	cout << "enter the data :";
	cin >> root->data;
	root->lc = root->rc = 0;
	
	}
	cout << "Do you want to create more node 1/0:";
	cin >> ch;
	
	 if(ch == 0) break;
	
	BT *next = new BT;
	
	cout << "Enter data :";
	cin >> next->data;
	
	next->lc = next->rc = 0;
	
	insert(root , next);
	
	}while(ch == 1);



}


void BT::insert( BT *root , BT *next){
	char ch1;
	cout <<"Where you want to insert the "<<next->data <<" (left  or right) : ";
	cin >> ch1;
	
	if(ch1 =='l' || ch1 == 'L'){
	
		if(root->lc == 0){
		
			root->lc = next;
		}
		else{
			
			insert(root->lc , next);
		}
	}
	else if(ch1 == 'r' || ch1 == 'R'){
	
		if(root->rc == 0){
			
			root->rc = next;
		
		}
		else{
		
			insert(root->rc, next);
		}
	
	}	
	
}

void BT::display(BT * root){

	if(root == NULL){
	
	return ;
	
	}
	else{
	
		display(root->lc);
		cout << "Data : "<< root->data << endl;
		display(root->rc);
	
	}


}


void display1(BT *root){

	// if root is null the we call back to previous data / node;
	if(root == NULL){
	
	return ;
	
	}
	else{
		cout << "Data : "<< root->data << endl;
		display1(root->lc);
		display1(root->rc);
	
	}

}


void display2(BT *root){

	if(root == NULL){
	
	return ;
	
	}
	else{
	
		display2(root->lc);
		display2(root->rc);
		cout << "Data : "<< root->data << endl;
		
		
	
	}

}

int main(){


int ch = 1, choice;

while(ch != 0){

	cout << "0. Exit" << endl;
	cout << "1. Create and insert node" << endl;
	cout << "2. Display inorder" << endl;
	cout <<"3.Display preorder"<<endl;
	cout <<"4. Display Postorder"<<endl;
	cin >> choice ;
	
	switch(choice){
	case 0:
	
		ch =0;
		break;
	case 1:
	
		root->create();
		break;
	case 2:
	
		root->display(root);
		break;
	case 3: 
		root->display1(root);
		break;
	case 4 : 
	
		root->display2(root);
		break;
		
	default : 
	
		cout << "Wrong choice !!"<< endl;
		


}
}



return 0;

}
