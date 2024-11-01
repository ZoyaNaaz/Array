#include<iostream>
#include<vector>
using namespace std;
// array ->  {5 1 1 2 2}
// output -> 5
// important -> n^n = 0 || n^0 = n
int singleNumber(vector<int>& arr){
    int answer = 0;
    for(int val : arr){
        answer ^= val; 
    }
    return answer;
}

int main(){
    vector<int>v;

    v.push_back(4);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);

    int result = singleNumber(v);
    cout<<"Single Number: "<<result<<" ";
    

    return 0;
}