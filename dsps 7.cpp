/* write a program a based on  circular queue

Pizza parlor accepting maximum M orders. Orders are served in
first come first served basis. Order once placed cannot be
cancelled. Write C++ program to simulate the system using  circular queue
using array.

*/

#include<iostream>
using namespace std;
int f =-1 , r =-1 ;

class pizza {

    public:

    int quntity,bill ;
    string name, address ;
    void accept();
    void deliver();

}q[5];

void pizza :: accept() {

    if( f == -1 && r == -1){
        f = r = 0;
        cout << "Enter your name";
        cin >> name;
        cout << "Enter  youe address";
        cin >> address;
        cout << "Enter no. of pizza you want ";
        cin >> quntity;
        cout <<"Your order is placed successfully and Congratulations you have won the 10% disscount on your order\n";
    }
    else if (((r+1)%5 == f) || r == f-1) {

        cout << "order cannot place ";


    }

    else {
        r = (r+1) % 5;
        cout << "Enter your name";
        cin >> name;
        cout << "Enter  youe address";
        cin >> address;
        cout << "Enter no. of pizza you want ";
        cin >> quntity;

    }
    
    }


void pizza :: deliver(){

    if(r == -1 && f == -1 ) {

        cout << "there is no order ! please first place  the order \n";
    }

    else if (f == 0 && r == 0 ){
        f = (f+1) % 5;
        bill = quntity * 100;
        cout << "Your order is deliver sucessfully\n";
        cout << "the bill is" << bill; 
    }
    else {
        
        bill = quntity * 100;
        cout << "Your order is deliver sucessfully\n";
        cout << "the bill is" << bill;

    }

}




int main ()  {

int ch = 1, choice;
    while (ch != 0)
    {
        cout << "0. Exit \n";
        cout << "1. Accept the order\n";
        cout << "2. cheak  order delivery \n";
        cin >> choice;
        
        switch (choice)
        {
        case 0:
            ch =0;
            break;

        case 1:
                q[0].accept();
                break;
        case 2:
                q[0].deliver();
                break;
        
        default:
            break;
        }
        
    }
    
    
    return 0;

}