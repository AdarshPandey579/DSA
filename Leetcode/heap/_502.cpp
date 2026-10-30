#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    int w=0;
    int k=2;
    vector<int> profits={1,2,3};
    vector<int> capital={0,1,1};
    vector<pair<int,int>> arr;
    int n=profits.size();
    for(int i=0; i<n; i++) arr.push_back({capital[i],profits[i]});
    sort(arr.begin(),arr.end());

    int i=0;
    priority_queue<int> pq;
    while(k>0){
        while(i<n){
            if(arr[i].first<=w) pq.push(arr[i].second);
            else break;
            i++;
        }
        if(pq.empty()){
            cout << w << endl;
            return 0;
        }
        w+=pq.top();
        pq.pop();
        k--;
    }
    cout << w << endl;
    return 0;
}