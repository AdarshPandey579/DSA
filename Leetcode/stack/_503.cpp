#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main(){
    vector<int> nums={1,2,1};
    stack<int> st;
    vector<int> ans(nums.size(),0);
    int n=nums.size();
    for(int i=2*n-1; i>=0; i--){
        while(!st.empty() && st.top()<=nums[i%n]) st.pop();
        if(i<n){
            if(!st.empty()) ans[i]=st.top();
            else ans[i]=-1;
        }
        st.push(nums[i%n]);
    }
    for(int num : ans){
        cout<<num<<" ";
    }
    return 0;
}