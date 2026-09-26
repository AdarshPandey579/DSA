#include<iostream>
using namespace std;

int main(){
    string s = "A man, a plan, a canal: Panama";
    int st=0, end=s.length()-1;
    while(st<end){
        if(!isalnum(s[st])){
            st++;
            continue;
        }
        if(!isalnum(s[end])){
            end--;
            continue;
        }
        if(tolower(s[st])!=tolower(s[end])){
            cout << false;
            return 0;
        }
        st++;
        end--;
    }
    cout << true;
    return 0;
}