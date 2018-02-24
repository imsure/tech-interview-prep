#include "common.hpp"


class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    int len = digits.size();
    if (!len) return {};

    int carry = 0;
    for (int i = len - 1; i >= 0; --i) {
      if (digits[i] < 9) {
        digits[i]++;
        carry = 0;
        break;
      } else {
        digits[i] = 0;
        carry = 1;
      }
    }

    if (carry) digits.insert(digits.begin(), 1);
    return digits;
  }
};


int main()
{
  Solution sol;
  vector<int> digits {3, 5, 9};
  // vector<int> digits {6, 5, 4};
  // vector<int> digits {9, 9, 9};
  auto ret = sol.plusOne(digits);
  for (int n : ret) cout << n;
  cout << endl;
}
