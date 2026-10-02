//Longest Substring with K Uniques

#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    string s = "aabacbebebe";
    int k = 3;
    int low=0, high=0, n=s.size(), result=-1;
    unordered_map<char,int> m;
    for (high=0; high<n; high++){
        m[s[high]]++;
        if(m.size()==k){
            result=max(result,high-low+1);
        }
        while(m.size()>k){
            m[s[low]]--;
            if(m[s[low]]==0) m.erase(s[low]);
            low++;
        }
    }
    cout << result;
    return 0;
}

//g++ longSubKunique.cpp -o longSubKunique; ./longSubKunique