#include<iostream>
using namespace std;

int isPowerOfTwo(int n, int x) {
    if(x>n) return 0;
    if(n==x) return 1;
    return isPowerOfTwo(n, x*2);
}

int main(){
    int n=16;
    int x=1;
    cout << isPowerOfTwo(n, x);
    return 0;
}