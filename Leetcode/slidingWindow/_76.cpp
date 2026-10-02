#include<iostream>
#include<unordered_map>
#include<climits>
using namespace std;

int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";
    unordered_map<char,int> needed;
    int need=t.size();
    int low=0,high=0,n=s.size();
    int minLen=INT_MAX, start=0;
    string res="";

    for(char c:t){
        needed[c]++;
    }
    while(high<n){
        if(needed[s[high]]>0){
            need--;
        }
        needed[s[high]]--;
        while(need==0){
            if(high-low+1<minLen){
                minLen=high-low+1;
                start=low;
            }
            needed[s[low]]++;
            if(needed[s[low]]>0){
                need++;
            }
            low++;
        }
        high++;
    }
    if(minLen==INT_MAX){
        res="";
    }else{
        res=s.substr(start,minLen);
    }
    cout << res << endl;
    return 0;
}