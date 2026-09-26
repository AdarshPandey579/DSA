#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> A={1,2,3,0,0,0} , B={2,5,6};
    int m=3, n=3;
    int i=m-1, j=n-1, k=A.size()-1;
    while(i>=0 && j>=0){
        if(A[i]>B[j]){
            A[k--]=A[i--];
        }else{
            A[k--]=B[j--];
        }
    }
    while(j>=0){
        A[k--]=B[j--];
    }
    for(int a:A){
        cout<<a<<" ";
    }
    return 0;
}
    