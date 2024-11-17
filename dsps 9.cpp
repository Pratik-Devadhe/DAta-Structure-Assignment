#include <iostream>
using namespace std;


class CMS {
    public:

        int amt;
        string name, add;
        int id;

        CMS *next;

        void accept();
        void display();
        void search();
        void modify();
        void displayall();
        void remove();
}*start = NULL;

void CMS::accept() {
    CMS *nnode ,*temp;
    nnode = new CMS;

    nnode->next = 0;
    cout << "Enter the details: "<<endl;
    cout << "Enter the name : ";
    cin >> nnode->name ; 
    cout << "Enter the address :";
    cin >> nnode->add;
    cout << "Enter the amount : ";
    cin >> nnode->amt;


    if(start == 0){
        start = nnode;
    }
    else {
        temp = start;

        while(temp->next != 0){
            temp = temp->next;
        }

        temp->next = nnode;

    }
    
}


void CMS :: displayall() {

    CMS *temp = start ;

    cout << "name \t address \t amount" << endl; 
    while(temp != 0){

        cout <<temp->name << "\t" << temp->add << "\t" <<temp->amt << endl; 
        temp = temp->next;
    
    }

}


void CMS :: display() {

    CMS *temp = start ;
    string nn;
    cout <<"Enter the name";
    cin >> nn;
    bool f = 0;
    
    while(temp != 0){

        if(temp->name == nn) {
            f = 1;
        cout << "name \t address \t amount" << endl; 
        cout <<temp->name << "\t" << temp->add << "\t" <<temp->amt << endl; 
        break;
        
        }
        temp = temp->next;
    
    }
    if(f == 0){
        cout <<"Record not fount in database" << endl;
    }

}

void CMS :: modify() {

    CMS *temp = start ;
    string nn;
    cout <<"Enter the name";
    cin >> nn;
    bool f = 0;
    
    while(temp != 0){

        if(temp->name == nn) {
            f = 1;
        cout << "Enter the  new details: "<<endl;
        cout << "Enter the name : ";
        cin >> temp->name ; 
        cout << "Enter the address :";
        cin >> temp->add;
        cout << "Enter the amount : ";
        cin >> temp->amt;
        break;
        
        }
        temp = temp->next;
    
    }
    
    if(f == 0){
        cout <<"Record not fount in database" << endl;
    }

}




void CMS :: remove() {

    CMS *temp = start  ,* q = temp;
    string nn;
    cout <<"Enter the name";
    cin >> nn;
    bool f = 0;
    
    while(temp != 0){

        if(temp->name == nn) {
            f = 1;
            q->next = temp->next;
            delete temp;
            break;
        }
        q = temp;
        temp = temp->next;
    
    }
    
    if(f == 0){
        cout <<"Record not fount in database" << endl;
    }

}



void CMS :: search() {

    CMS *temp = start;
    string nn;
    cout <<"Enter the name";
    cin >> nn;
    bool f = 0;
    
    while(temp != 0){

        if(temp->name == nn) {
            f = 1;
            cout <<"record found in database" << endl;
            break;
        }
        temp = temp->next;
    
    }
    
    if(f == 0){
        cout <<"Record not fount in database" << endl;
    }

}



int main () {

int ch = 1, choice;
CMS s;

while(ch != 0) {
    cout <<"MENU : "<<endl;
    cout <<"0. EXIT : "<<endl;
    cout <<"1. accept the record : "<<endl;
    cout <<"2. search the record : "<<endl;
    cout << "3. modify he record : "<<endl;
    cout <<"4. remove the record : "<<endl;
    cout <<"5. display  records: "<<endl;
    cout <<"6. display all records : "<<endl;
    cin >> choice;

    switch(choice) {


        case 0:
             ch =0 ;
             break;
        case 1:
            s.accept();
            break;
        case 2:
            s.search();
            break;
        case 3:
            s.modify();
            break;
        case 4:
            s.remove();
            break;
        case 5:
            s.display();
            break;
        case 6:
            s.displayall();
            break;

        default:

            break;
             

    }
}



    return 0;
}