#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int num:nums){
        pq.push(num);
        if(pq.size()>k) pq.pop();
    }
    cout << pq.top() << endl;
    return 0;
}