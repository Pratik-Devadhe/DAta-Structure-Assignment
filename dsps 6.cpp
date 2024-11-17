/*
    Queue
*/

#include<iostream>
#include<vector>

using namespace std;
 

class queue{

        public:

        int f ,r; // f is front of the queue and rear is the traversing pointer (index) to the queue;
        int max = 10;
        vector < int > vec;
        

        queue(){

            f = -1;
            r = -1;
        }
        

        void empty();
        void full();
        void enqueue();
        void dequeue();
        void display();

};

 void queue::empty(){

  if( r == -1 && f == -1){
    cout <<"Queue is Empty. \n";
  }
  else{
     cout << "Queue have some element in it.\n";
  }
 }

void queue::full(){

    if(r == max-1){
        cout<< "Queue is full\n";
    }
    else{
        cout <<"Queue is Not full \n";
    }
    
}

void queue :: enqueue(){

    int val;
    cout << "Enter the value : ";
    cin >> val;

    if(r == -1 && f == -1){
        r =0;
        f = 0;
        vec.push_back(val);
    
    }
    else if ( r == max -1 ){
        cout << "Cannot insert Queue is full";
    }
    else{
        ++r;
        vec.push_back(val);
    }
}

void queue  :: dequeue(){

    if ( f == -1){
        cout << "Queue is Empty \n";
    }
    else if ( f == r){
        cout << "Deleted element is "<< vec[f] << endl;
        f = -1;
        r = -1;

    }
    else {

       cout << "Deleted element is "<< vec[f] << endl;
       f++;

    }
}

void queue :: display(){

    if(r == -1  && f == -1){
        cout << "Queue is empty" << endl;
    
    }
    else{

        for(int i = f ; i != r; i++){

            cout << vec[i] <<" ";

        }

        cout << vec[r] << endl;
    }
}


int main(){

     queue q;
    int count = 0;
    int ch =3,choice;

    while(ch != 0){

        cout << "\nMenu\n";
        cout << " 0. EXIT\n";
        cout << " 1. Cheak  queue is Empty or not\n";
        cout << " 2. Cheak  queue is full or not\n";
        cout << " 3. Enter the element in the queue\n";
        cout << " 4. Delete the element from the queue\n";
        cout << " 5. Display queue elements \n";
        cin >> choice;

        switch(choice) {

            case 0:
                    ch = 0;
                    break;
            case 1: 
                    q.empty();
                    break;
            case 2:
                    q.full();
                    break;
            case 3:
                    q.enqueue();
                    count++;
                    break;
            case 4: 
                    q.dequeue();
                    break;
            case 5:
                    q.display();
                    break;
            default:
                    cout << "Wrong choice , Try Again !!";
                    break;
        }
        
    }
    



    return 0;
}