#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int max_profit = 0;
    if (not prices.empty()) {
      auto[buy, sell, profit] = _maxProfit(prices.begin(), prices.end());
      max_profit = profit;
      while (prices.begin() != buy) {
        tie(buy, sell, profit) = _maxProfit(prices.begin(), buy);
        max_profit = max(profit, max_profit);
      }
    }

    return max_profit;
  }

 private:
  template<class Iter>
  tuple<Iter, Iter, int> _maxProfit(Iter begin, Iter end) {
    auto buy = min_element(begin, end);
    if (end != buy) {
      auto sell = max_element(next(buy), end);
      if (end != sell) {
        return {buy, sell, *sell - *buy};
      }
    }

    return {buy, buy, 0};
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
