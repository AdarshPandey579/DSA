#include<iostream>
using namespace std;

int main(){
    string s = "aaabbb";
    int b = 0;
    for(char ch : s) {
        if(ch == 'a' && b != 0) {
            cout << false << endl;
            return 0;
        }
        if(ch == 'b') b++;
    }
    cout << true << endl;
    return 0;
}