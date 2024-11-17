#include<iostream>
using namespace std;

// 2 pointer approach
void reverse(string& s){
    int n = s.length();
    int i = 0, j = n-1;

    while(i <= j){
        swap(s[i++], s[j--]);
    }
}

// 2nd approach
void reverse1(string& s){
    int n = s.length();
    for(int i = 0; i < n/2; i++){
        swap(s[i], s[n-i-1]);
    }
    
}
int main(){
    string s = "String gnirtS";

    reverse1(s);

    cout<<s<<endl;
    return 0;
}