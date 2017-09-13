#include "common.hpp"

// wrong logic!

class Solution {
public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int len = flowerbed.size();

    for (int i = 0; i < len; ++i) {
      if (flowerbed[i] == 0) {
        if (i - 1 >= 0 && i + 1 < len && flowerbed[i-1] == 0 && flowerbed[i+1] == 0) {
          --n;
          flowerbed[i] = 1;
        } else if (i - 1 < 0 && i + 1 < len && flowerbed[i+1] == 0) {
          --n;
          flowerbed[i] = 1;
        } else if (i - 1 >= 0 && i + 1 > len && flowerbed[i-1] == 0) {
          --n;
          flowerbed[i] = 1;
        }
      }
    }

    return n == 0 ? true : false;
  }
};

// scan through the flowerbed, whenever we see a 0, check if it is avaible to plant

class Solution2 {
public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int len = flowerbed.size();

    for (int i = 0; i < len; ++i) {
      if (flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == len-1 || flowerbed[i+1] == 0)) {
        --n;
        flowerbed[i] = 1;
      }
      if (n == 0) return true;
    }

    return n <= 0;
  }
};

int main()
{
  Solution2 sol;
  vector<int> flowerbed {1, 0, 0, 0, 0};
  cout << sol.canPlaceFlowers(flowerbed, 2) << endl;
}
