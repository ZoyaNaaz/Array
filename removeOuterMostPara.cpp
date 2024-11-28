#include<iostream>
#include<vector>
using namespace std;
// input -> "(()())(())(()(()))"
// output-> "()()()()(())"
string removeOuterMostPara(string& s){
    int n = s.length();
    string result = "";
    int leftPara = 0, start = 0;
    vector<string>v;

    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            leftPara++;
        }
        else{
            leftPara--;
        }
        if(leftPara == 0){//valid primitive
            v.push_back(s.substr(start, i+1-start));
            start = i+1;
        }
    }
    for(auto str : v){
        if(str.length() > 1){
            result += str.substr(1, str.length()-2);
        }
    }
    return result;

}

int main(){
    string s = "(()())(())(()(()))";
    cout<<removeOuterMostPara(s);
    return 0;
}