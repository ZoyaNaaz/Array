#include <iostream>
using namespace std;
// power -> x^n
// input -> 3^5
// output -> 243

// 1. approach - binary exponentiation
// O(log n)
double power(double x, int n){
    int binaryForm = n;
    // handling case when n is -ve
    if(n < 0){
        x = 1/x;
        binaryForm = -binaryForm;
    }
    double answer = 1;
    while(binaryForm > 0){
        if(binaryForm % 2 == 1) {
            answer *= x;
        }
        x *= x; //x^2
        binaryForm /= 2;
    }
    return answer;
}
// 2.approach
// O(n)
long power1(int x, int n){
    long prod = 1;
    for(int i = 0; i < n; i++)
        prod *= x;
    return prod;
}
// main code
int main()
{   int x, n;
    cout<<"enter x and its power: "<<endl;
    cin>>x>>n;
    long ans = power(x,n); 
    // print
    cout<<ans;

    return 0;
}