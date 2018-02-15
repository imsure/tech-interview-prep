#include "common.hpp"


class Solution {
private:
  bool _isHappy(int n, unordered_set<int>& visited) {
    if (visited.count(n)) return false;
    visited.insert(n);

    int square_sum = 0;
    while (n) {
      int digit = n % 10;
      square_sum += digit * digit;
      n = n / 10;
    }

    if (square_sum == 1) return true;
    else return _isHappy(square_sum, visited);
  }

public:
  bool isHappy(int n) {
    unordered_set<int> visited;
    return _isHappy(n, visited);
  }
};


class Solution2 {
public:
  bool isHappy(int n) {
    unordered_set<int> visited;

    while (true) {
      if (visited.count(n)) return false;
      visited.insert(n);

      int square_sum = 0;
      while (n) {
        int digit = n % 10;
        square_sum += digit * digit;
        n = n / 10;
      }
      if (square_sum == 1) return true;
      else n = square_sum;
    }

    return false;
  }
};


int main()
{
  Solution sol;
  cout << std::boolalpha << sol.isHappy(19) << endl;
  cout << std::boolalpha << sol.isHappy(20) << endl;
}
