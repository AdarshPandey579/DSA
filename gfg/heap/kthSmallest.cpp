#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

int main(){
    vector<int> arr = {10, 5, 4, 3, 48, 6, 2, 33, 53, 10};
    int k=4;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int num:arr){
        pq.push(num);
    }
    while(k>1){
        pq.pop();
        k--;
    }
    cout << pq.top() << endl;
    return 0;
}