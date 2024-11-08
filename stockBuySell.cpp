#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// best time to buy sell stock
// vector -> {1,2,4},
// output -> 3
// 121. Best Time to Buy and Sell Stock
int maxProfit(vector<int>& prices) {
      int buy_price = prices[0];
      int maxProfit = 0;
      for(int price : prices){
        if(price > buy_price)
            maxProfit = max(maxProfit, price - buy_price); //price - buy_price = current profit
        buy_price = min(buy_price, price);
      }
      return maxProfit;
}

int main()
{
    vector<int> v = {7,1,5,3,6,4};

    int element = maxProfit(v);
    // print
    cout << element;

    return 0;
}