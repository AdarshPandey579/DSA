#include<iostream>
using namespace std;

int main(){
    string s = "()(())((()()))";
    int count=0, maxCount=0;
    for(char ch : s){
        if(ch == '('){
            count++;
            if(maxCount<count){
                maxCount=count;
            }
        }else if(ch == ')'){
            count--;
        }
    }
    cout<<maxCount<<endl;
    return 0;
}