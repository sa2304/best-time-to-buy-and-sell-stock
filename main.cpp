#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    // FIXME
    return 0;
  }
};

void TestMaxProfit() {
  Solution s;
  {
    vector<int> prices{7,1,5,3,6,4};
    assert(5 == s.maxProfit(prices));
  }
  {
    vector<int> prices{7,6,4,3,1};
    assert(0 == s.maxProfit(prices));
  }
  {
    vector<int> prices{2,5,4,3,2,1,1};
    assert(3 == s.maxProfit(prices));
  }
  {
    vector<int> prices{2,12,1,6};
    assert(10 == s.maxProfit(prices));
  }
}

int main() {
  TestMaxProfit();
  std::cout << "Ok!" << std::endl;
  return 0;
}
