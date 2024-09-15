/*
Implement C++ program for expression conversion infix to
postfix using stack.  without using a predefined stack;


*/
  
#include<iostream>
#include<algorithm>
using namespace std;
int stack[100];
int top = -1 ;

void push_to_stack(char ch){

    stack[++top] = ch;


}

inline  int cheak_presidance(char c){
    
    if(c == '+' || c == '-')   
         return 1;
    else if( c == '*' || c == '/' )
         return 2;
    else if(c == '^')
         return 3;
    
    else 
         return 0;
}


 char pop_stack(){

    if(top >=0 ){

        return stack[top--];
    }
    else
        return '\0';
    
}

  char peek_stack(){
    if(top>=0){
        return stack[top];
    }
    else{
        return '\0';
    }

}


string infix_to_postfix(string s ){

    string  s1 = "";
    char ch;

    for(int i=0;i<s.size();i++){
        
        if(isalnum(s[i])){

            s1  = s1 + s[i];
        }
        else if(s[i] == '('){
            push_to_stack(s[i]);
        }
        else if(s[i] == ')'){

            while( peek_stack() != '('){ 
                s1 = s1 + pop_stack();
           }

           pop_stack();                      // remove '(' from the stack;
        
           
        }
        else{
            
                while (top != -1 && cheak_presidance(s[i]) <= cheak_presidance(stack[top]))
                {
                    s1 = s1 + pop_stack();
                   
                }

                push_to_stack(s[i]);
                
        }

        }

        while(top != -1){
           
            s1 = s1 + pop_stack();

        }
        
        return s1;
    }


    


int main(){

    string s;

cout << "Enter the expression:";
cin >> s;

cout << infix_to_postfix(s);



    return 0;
}
