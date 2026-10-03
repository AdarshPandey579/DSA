#include<iostream>
#include<vector>
#include<set>
using namespace std;

set<vector<int>> st;

void CS(vector<int>& arr, int target, int i, int n, vector<int>& ans, vector<vector<int>>& result){
    if(i==n || target<0) return;
    if(target==0){
        if(st.find(ans)==st.end()){
            st.insert(ans);
            result.push_back(ans);
            return;
        }
    }
    ans.push_back(arr[i]);
    CS(arr, target-arr[i], i+1, n, ans, result);
    CS(arr, target-arr[i], i, n, ans, result);
    ans.pop_back();
    CS(arr, target, i+1, n, ans, result);
}

int main() {
    vector<int> arr={2,3,5};
    int target=8;
    vector<int> ans;
    vector<vector<int>> result;
    CS(arr, target, 0, arr.size(), ans, result);
    for(auto v: result){
        for(auto x: v){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// g++ _39.cpp -o _39;./_39