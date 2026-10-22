#include<iostream>
using namespace std;

bool isPalindrom(string& s, int left, int right){
    while(left<=right){
        if(s[left]==s[right]){
            left++;
            right--;
        }else{
            return false;
        }
    }
    return true;
}

int main(){
    string s="eceec";
    int n=s.size();
    int left=0, right=n-1;
    while(left<right){
        if(s[left]==s[right]){
            left++;
            right--;
        }else{
            cout << isPalindrom(s,left+1,right) || isPalindrom(s,left,right-1);
            return 0;
        }
    }
    cout << true;
    return 0;
}