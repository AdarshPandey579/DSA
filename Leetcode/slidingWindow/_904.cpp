#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


int main(){
    vector<int> fruits={1,2,1};
    unordered_map<int,int> m;
    int k=2;
    int low=0, high=0, n=fruits.size(), result=-1;
    for(high=0; high<n; high++){
        m[fruits[high]]++;
        if(m.size()>k){
            while(m.size()>k){
                m[fruits[low]]--;
                if( m[fruits[low]]==0) m.erase(fruits[low]);
                low++;
            }
        }
        result = max(result, high-low+1);
    }
    cout<< result;
    return 0;
}