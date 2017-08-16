#include "common.hpp"

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

// binary search

class Solution {
public:
  int guessNumber(int n) {
    int low = 1, high = n, mid;
    int guess_res;

    while (low <= high) {
      mid = low + (high - low) / 2;
      guess_res = guess(mid);
      if (guess_res < 0) {
        high = mid - 1;
      } else if (guess_res > 0) {
        low = mid + 1;
      } else {
        return mid;
      }
    }

    return -1;
  }
};

// ternary search

class Solution2 {
public:
  int guessNumber(int n) {
    int low = 1, high = n, m1, m2;
    int g1, g2;

    while (low <= high) {
      m1 = low + (high - low) / 3;
      m2 = high - (high - low) / 3;

      g1 = guess(m1);
      if (g1 < 0) {
        high = m1 - 1;
      } else if (g1 > 0) {
        g2 = guess(m2);
        if (g2 < 0) {
          low = m1 + 1;
          high = m2 - 1;
        } else if (g2 > 0) {
          low = m2 + 1;
        } else {
          return m2;
        }
      } else {
        return m1;
      }
    }

    return -1;
  }
};

int main()
{
}
