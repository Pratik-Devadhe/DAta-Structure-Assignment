/******************************************************************************
Write C++ program to store roll numbers of student in array who
attended training program in random order. Write function for
a) Searching whether particular student attended training
program or not using linear search . OR
a) Searching whether particular student attended training
program or not using binary.'

additional task:
 take students address and percentage 
 feedback analysis:
 add a 5 question 

 Q.1  How would you rate the clarity of the training objectives presented at the beginning of the program?;
 Q.2  How effective were the training materials and resources in aiding your understanding of the subject matter?
 Q.3  How would you evaluate the instructor's ability to engage and facilitate discussions during the training?
 Q.4 How well did the training program address your specific needs and expectations?
 Q.5 How would you rate the overall organization and structure of the training sessions?
  OPTIONS :
 1. poor\n2.Satisfactory\n3.Good\n4.Very Good\n5.Excellent

 Take a feedback and display the overall feedback if it is > 60 % display message good feedback otherwise display a appropric=ate message
*******************************************************************************/
#include <iostream>
using namespace std;

class student{
    public:
            string name;
            int roll;
            void accept(){
                cout <<"Enter roll number and name:";    
                cin >> roll >> name;
            }
            void l_search(student*,int);
            void b_search(student*,int);
            void display_all();
            double question();
            void feedback(student* ,int);

            
};

    void student::l_search(student s[],int n){
        
        bool found = false;
        int key;
        cout << "\nEnter which roll number you want to store:";
        cin >> key;
        
        for(int i=0;i<n;i++){
            
            if(s[i].roll == key){
                cout << "\nroll number "<<key<<" is present in training program\n";
               found = true;
               break;
                
            }
        }
        
        if(!found){
            cout << "\nroll number "<<key<<" is not present in training program\n";
        }
        
        
    }
    void student::b_search(student s[],int n){
        int key;
        cout << "\nEnter which roll number you want to store:";
        cin >> key;
        
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if(s[i].roll >  s[j].roll){
                    student temp = s[j];
                    s[j] = s[i];
                    s[i] = temp;
                }
            }
        }
        
        int mid , low = 0,high = n-1;
        bool found = false;
        
        while(low <= high){
            
             mid = (low+high) / 2;
             
         if(s[mid].roll == key){
             cout << "roll number "<<key<<" is present in training program\n";
             found = true;
             break;
         }
         
         else if(s[mid].roll > key){
             high = mid-1;
         }
         else{
             
             low = mid+1;
         }
        }
        
        if(!found){
            cout << " roll number "<<key<<" is not present in training program\n";
        }
        
        
        
    }
    
    void student::display_all(){
        cout <<"\n\t "<< roll <<"\t\t"<< name <<"\n";
    }

double student::question(){
    int answer,sum=0;

    
                    cout<<"Q.1 How would you rate the clarity of the training objectives presented at the beginning of the program? \n";
                    cout <<"1. poor\n2.Satisfactory\n3.Good\n4.Very Good\n5.Excellent\n";
                    cin >> answer;
                    sum += answer;
                 
                    cout<<"Q.2 How effective were the training materials and resources in aiding your understanding of the subject matter?\n";
                    cout <<"1. poor\n2.Satisfactory\n3.Good\n4.Very Good\n5.Excellent\n";
                    cin >> answer;
                    sum += answer;
                 
                    cout<<"Q.3 How would you evaluate the instructor's ability to engage and facilitate discussions during the training?\n";
                    cout <<"1. poor\n2.Satisfactory\n3.Good\n4.Very Good\n5.Excellent\n";
                    cin >> answer;
                    sum += answer;
             
                    cout <<"Q.4 How well did the training program address your specific needs and expectations?\n";
                    cout <<"1. poor\n2.Satisfactory\n3.Good\n4.Very Good\n5.Excellent\n";
                    cin >> answer;
                    sum += answer;
                   
            
                    cout <<"Q.5 How would you rate the overall organization and structure of the training sessions?\n";
                    cout <<"1. poor\n2.Satisfactory\n3.Good\n4.Very Good\n5.Excellent\n";
                    cin >> answer;
                     sum += answer;
        

    double per = (sum/5)*100/5;

    return per;

}

void student::feedback(student s[],int n){
    double sum[n],per;
        for(int i=0;i<n;i++){
            cout <<" feedback of Roll no."<< s[i].roll<< endl;
            sum[i] =  s[i].question();

        }

for(int i=0;i<n;i++){
    per += sum[i];
}

 per = (per/n);

if(per > 60){
    cout <<"good feedback "<< per <<"%"<<endl;
}
else{
    cout <<"Bad feedback  "<< per <<"%"<<endl;
}
    
}

int main()
{
    int n;
    student s[100];
    cout << " How many roll number do you want to store?:";
    cin >> n;
    
    int ch,choice=2;
    while(choice != 0){
        
        cout<<"\n0. Exit";
        cout<<"\n1. Enter record  of  students";
        cout<<"\n2. Linear search";
        cout<<"\n3. binary search";
        cout<<"\n4. display all present students";
        cout<<"\n5. give the feedback \n";
        cin >>ch;
        
        switch(ch){
            case 0:
                    choice = 0;
                    break;
            case 1:
                    for(int i=0;i<n;i++){
                        s[i].accept();
                    }
                     break;
            case 2:
                    s[0].l_search(s,n); 
                    break;
            case 3:
                    s[0].b_search(s,n);
                    break;
            case 4:
                    cout <<"\t Roll no.\t Name";
                    for(int i = 0; i < n; i++){
                        s[i].display_all();
                    }
                    break;
            case 5:
                    s[0].feedback(s,n);     
                    break;
                    
            default:
                    cout <<"wrong choice ! Please try again.";
                    break;
        }
        
    }

    return 0;
}