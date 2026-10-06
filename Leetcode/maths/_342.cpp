#include<iostream>
using namespace std;

int main(){
    int n=0;
    long long int x=1;
    while(x<n){
        x*=4;
    }
    if(x==n) {
        cout << true;
        return 0;
    }
    cout << false;
    return 0;
}

// g++ _342.cpp -o _342;./_342