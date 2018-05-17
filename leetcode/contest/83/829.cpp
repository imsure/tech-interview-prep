#include "../common.hpp"


class Solution {
public:
  int consecutiveNumbersSum(int N) {
    int count = 0;
    int half;
    vector<int> presum;

    half = N / 2;

    int sum = 1;
    int end = 1, start = 1;
    while (start <= half) {
      if (sum < N) {
        end++;
        sum += end;
      } else if (sum > N) {
        sum -= start;
        start++;
      } else {
        ++count;
        sum -= start;
        start++;
      }
    }

    return count + 1;
  }
};


int main()
{
  Solution sol;
  cout << sol.consecutiveNumbersSum(5) << endl;
  cout << sol.consecutiveNumbersSum(9) << endl;
}
