#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> arr = {1, -2, 0, 3};
    int n = arr.size();

    int noDelete = arr[0];
    int oneDelete = 0;
    int maxSum = arr[0];

    for (int i = 1; i < n; i++) {
        oneDelete = max(noDelete, oneDelete + arr[i]);
        noDelete = max(arr[i], noDelete + arr[i]);
        maxSum = max(maxSum, max(noDelete, oneDelete));
    }

    cout << maxSum;
    return 0;
}