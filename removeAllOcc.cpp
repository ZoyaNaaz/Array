#include<iostream>
using namespace std;

// 2 pointer approach
void removeAllOcc(string& s, string& part){
    int m = s.length();
    int n = part.length();

    for(int i = 0; i < m; i++){

        if(s.find(part) < m){
                s.erase(s.find(part), n);
        }
    }
}


int main(){
    string s = "abcabcbbccadc";
    string part = "abc";
    removeAllOcc(s, part);

    cout<<s<<endl;
    return 0;
}