#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> height={1,8,6,2,5,4,8,3,7};
    int capacity=0, i=0, j=height.size()-1;
    while(i<j){
        int h = min(height[i], height[j]);
        capacity = max(capacity, h * (j - i));
        if(height[i] < height[j]){
            i++;
        } else {
            j--;

        }
    }
    cout<<capacity;
    return 0;
}