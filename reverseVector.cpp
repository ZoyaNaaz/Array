#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Reverse vector element
// vector -> {5,10,15,-2,24,78}
// reverse -> {78,24,-2,15,10,5}

//1. approach
//  using two pointer approach
void reverseVector(vector<int>& vec){
   int start = 0;
   int end = vec.size() - 1;
   while(start < end){
        swap(vec[start], vec[end]);
        start++;
        end--;
   }

}
// 2. approach
// void reverseVector1(vector<int>&v){
//     reverse(v.begin(), v.end()); //using build-in func
// }
int main(){
    vector<int>v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    cout << "Original Vector: "<<endl;
    for (int val : v) {
        cout << val << " ";
    }
    reverseVector(v);
    //print 
    cout <<endl<< "Reversed Vector: "<<endl;
    for(int val : v){
        cout<<val<<" ";
    }
    return 0;
}