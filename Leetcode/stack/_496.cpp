#include<iostream>
#include<stack>
#include<unordered_map>
#include<vector>

using namespace std;

int main(){
    vector<int> nums1={4,1,2};
    vector<int> nums2={1,3,4,2};
    stack<int> st;
    vector<int> ans;
    unordered_map<int , int> mp;
    int n=nums2.size();
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()<=nums2[i]) st.pop();
        if(!st.empty()) mp[nums2[i]]=st.top();
        else mp[nums2[i]]=-1;
        st.push(nums2[i]); 
    }

    for(int num : nums1){
        ans.push_back(mp[num]);
    }
        
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}