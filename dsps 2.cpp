#include <iostream>
#include <cstring>
using namespace std;
int N;

class book
{
	int cost;
	char tt[100], aut[100];
public:
	void accept();
	void displayA();
	void display();
	void displayD();
	void displayless();
	void deleteD();
	void deleteT();
	void count();
	
}b[100],c[100],arr[100];


//To accept the book record
void book::accept()
{
        cout<<"Enter the Title: ";
        cin>>tt;
        cout<<"Enter the Author Name: ";
        cin>>aut;
        cout<<"Enter the cost: ";
        cin>>cost;
    
}


//display method:
	void book::display(){
	    
	    cout <<"Title\t" <<"Author\t" <<"Cost"<<endl;
	    for(int i=0;i<N;i++){
	        
	         cout << b[i].tt <<"\t";
             cout << b[i].aut <<"\t";
             cout << b[i].cost << endl;
	    }
	}
	
	

//To display record in ascending order
void book::displayA()
{
int temp;

  for(int i=0;i<N-1;i++)
  {
    for(int j=i+1;j<N;j++)
    {
        if(b[i].cost>b[j].cost)
        {
	        swap(b[i],b[j]);
        }
    }
  }


 display();
}


//To display record in decending order
void book::displayD()
{

int temp;
  for(int i=0;i<N;i++){
      
    for(int j=i+1;j<N;j++){
        
       if(b[i].cost < b[j].cost){
        
	        swap(b[i],b[j]);

        }
    }
  }
  
display();
    
}


//To display record < 500 in temp array
void book::displayless()
{
    int j=0,count=0;
    for(int i=0;i<N;i++)
    {
      if(b[i].cost<500)
      {
        c[j++]=b[i];
        count++;
      }
    }
  
  cout <<"Title\t\t" <<"Author\t\t" <<"Cost"<<endl;
	    for(int i=0;i<count;i++){
	        
	         cout << c[i].tt <<"\t\t";
             cout << c[i].aut <<"\t\t";
             cout << c[i].cost << endl;
	    }
 
}

// delete a  repeted element present in the record;
void book::deleteD(){
    
    int k=0;
    bool f = false;
    for(int i=0;i<N;i++){
        
        for(int j=0;j<N;j++){
        
        if(b[i].tt == b[j].tt && b[i].aut == b[j].aut && b[i].cost == b[j].cost)
        {
            f = true;
            break;
            
        }
        }
        if (f == false) {
            arr[k++] = b[i];
            f = true;
            }
    }
    
/* Handle the last element if it was not part of a duplicate sequence
        if (!f && N > 0) {
            arr[j++] = b[N - 1];
        }   
    */
    
    cout << " record with non duplicate element:"<<endl;
    cout <<"Title\t\t" <<"Author\t\t" <<"Cost"<<endl;
    for(int i=0;i<k;i++){
        
        cout << arr[i].tt <<"\t\t";
        cout << arr[i].aut <<"\t\t";
        cout << arr[i].cost << endl;
    }
    
}

int main() 
{
    
    cout << "enter how many records you want to create: ";
    cin >>  N;
    

    
   int ch,i=0, choice=1;
    while(choice != 6)
    {
        cout <<"\nMenu:";
        cout<<"\n1.Accept Book Record.";
        cout<<"\n2.Display in ascending order";
        cout<<"\n3.Display in descending order";
        cout<<"\n4.Display less than 500";
        cout<<"\n5.delete a  repeted element present in the record";
        cout<<"\n6.Exit";
        cout<<"\nEnter your choice.: ";
        cin>>ch;
        
    switch(ch)
    {
    case 1:
            for(int i=0;i<N;i++){
                	b[i].accept();
            }
    	break;
    
    case 2:
    	b[i].displayA();
    	break;
    	
    case 3:
    	b[i].displayD();
    	break;
    	
    case 4:
    	b[i].displayless();
    	break;
    case 5:
        b[i].deleteD();
    case 6:
        choice =6;
        break;
    	
    	
    }

    
	}
    return 0;

}