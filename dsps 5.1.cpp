/*

PALINDROME STRING :
Example : 
        Aibohphobia ,"A man, a plan, a canal, Panama" ,"Able was I ere I saw Elba" ;

*/

#include<iostream>
using namespace std;

// Stack 
int top = -1 ; 

char stack[200];

// push the characters onto stack;

void push_ch(char c){
    if(top == 199){
        cout << "Stack is full";
    }
    else{
        stack[++top] = c;
    }

}


int main(){
    
    string s, s2 ="\0";
   
    bool f = true;
    cout << "Enter the string ";
    getline (cin , s);
    

    // converting string to lowercase ;

    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];

        if(isalpha(ch)){

            ch = tolower(ch);
            s2 += ch; 
            push_ch(ch);
             
        }
        else{
            continue;
        }
    }

    
// cheaking whether string is palindrome or not ;  we cannot run the loop with size of s2 becoz s2 is character array


    for(int i = 0; i <  s2.size()  ;i++){

        if(stack[top--] != s2[i]){
            f=false;
            break;
        }
    }

    
    if(!f){

        cout<<"Entered string is not palindrome";
    }
    else{
        
        cout << "Entered string is palindrome";
    }


    return 0;
}