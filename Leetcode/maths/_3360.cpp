#include<iostream>
using namespace std;

int main(){
    int n = 12;
    bool aliceTurn = false;
    int stone = 10;
    while(stone <= n){
        n-=stone;
        stone--;
        aliceTurn = !aliceTurn; // successful remove of stone switch the winner.
    }
    cout << aliceTurn << endl;
    return 0;
}