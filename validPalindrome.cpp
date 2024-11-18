#include<iostream>
using namespace std;

bool isAlphaNum(char ch){
    if( (ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')){
        return true;
    }
    return false;
}
// iswalnum(ch) can be used to check alphanumric char -> for this you need to include cwtype header file

// 2 pointer approach
bool validPalindrome(string& s){
    int n = s.length();
    int i = 0, j = n-1;

    while(i < j){
        if(!isAlphaNum(s[i])){
            i++; continue;
        }
        if(!isAlphaNum(s[j])){
            j--; continue;
        }
        if(tolower(s[i]) != tolower(s[j]))
            return false;
        i++; 
        j--;
    }
    return true;
}


int main(){
    string s = "ra$ceca*R";

    validPalindrome(s) ? cout<<"valid" : cout<<"not";

    return 0;
}