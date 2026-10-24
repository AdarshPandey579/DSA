#include<iostream>
using namespace std;

int main(){
    string s="abciiidef";
    int k=3;
    int maxCount=0, i=0, count=0;
    while(i<k){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') count++;
        i++;
    }
    maxCount=max(maxCount , count);
    while(i<s.size()){
        char add=s[i];
        char sub=s[i-k];
        if(add=='a' || add=='e' || add=='i' || add=='o' || add=='u') count++;
        if(sub=='a' || sub=='e' || sub=='i' || sub=='o' || sub=='u') count--;
        maxCount=max(maxCount , count);
        i++;
    }
    cout << maxCount;
    return 0;
}