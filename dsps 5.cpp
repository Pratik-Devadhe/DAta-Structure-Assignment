#include<iostream>
#include<vector>
using namespace std;

int main(){
    string s;
    string s1 = "";
   


    cout << "Enter the string: ";
   getline(cin ,s);

     for(int i=0;i< s.size();i++){
            char ch = s[i];
            bool isunique = true;
               for(int j=0;j<s1.size();j++){

                   if( s1[j] == ch){
                    isunique = false;
                    break;

                   }

                 }

               if(isunique){
                     s1 += ch;
                    
               }
             
     }   

            for(int i=0;i<s1.size();i++){
                int count = 0; 
                  vector <int> indices ;         
                for(int j=0;j<s.size();j++){

                    if(s[j] == s1[i]){
                         count++;
                        indices.push_back(j);
                         
                    }

                }  
                cout << s1[i] << " occurs "<< count <<" times  at index: ";
                for(int i=0;i< indices.size();i++){
                    cout << indices[i] <<" ";
                }
                cout << endl;

                }   
 
    return 0;
}