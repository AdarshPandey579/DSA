#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    vector<int> stones = {2,7,4,1,8,1};
    priority_queue<int> pq;
    for(int weight:stones) pq.push(weight);
    while(!pq.empty()){
        int s1 = pq.top();
        pq.pop();
        if(pq.empty()){
            cout << s1 << endl;
            return 0;
        }
        int s2 = pq.top();
        pq.pop();
        if(s1-s2!=0) pq.push(s1-s2);
    }
    cout << 0 << endl;
    return 0;
}