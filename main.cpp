#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int max_profit = 0, min_price = prices[0];
    for (size_t i = 1; i < prices.size(); ++i) {
      max_profit = max(prices[i] - min_price, max_profit);
      min_price = min(prices[i], min_price);
    }

    return max_profit;
  }
};

void TestMaxProfit() {
  Solution s;
  {
    vector<int> prices{7, 1, 5, 3, 6, 4};
    assert(5 == s.maxProfit(prices));
  }
  {
    vector<int> prices{7, 6, 4, 3, 1};
    assert(0 == s.maxProfit(prices));
  }
  {
    vector<int> prices{2, 5, 4, 3, 2, 1, 1};
    assert(3 == s.maxProfit(prices));
  }
  {
    vector<int> prices{2, 12, 1, 6};
    assert(10 == s.maxProfit(prices));
  }
  {
    vector<int> prices{2, 4, 1};
    assert(2 == s.maxProfit(prices));
  }
}

int main() {
  TestMaxProfit();
  std::cout << "Ok!" << std::endl;
  return 0;
}
