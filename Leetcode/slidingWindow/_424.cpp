#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    string s="AABABBA";
    int k=1;
    int low=0, high=0, result=0, maxfreq=0, len=0, diff=0, n=s.length();
    int freq[26]={0};
    for(high=0;high<n;high++){
        freq[s[high]-'A']++;
        maxfreq=*max_element(freq,freq+26);
        len=high-low+1;
        diff=len-maxfreq;
        while(diff>k){
            freq[s[low]-'A']--;
            low++;
            maxfreq=*max_element(freq,freq+26);
            len=high-low+1;
            diff=len-maxfreq;
        }
        result=max(result,len);
    }
    cout<< result;
    return 0;
}