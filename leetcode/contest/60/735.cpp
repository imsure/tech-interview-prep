#include "../common.hpp"

class Solution {
public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    bool neg = asteroids[0] < 0;
    bool finish = true;
    for (auto a : asteroids) {
      if (neg) {
        if (a < 0) continue;
        else {
          finish = false;
          break;
        }
      } else {
        if (a > 0) continue;
        else {
          finish = false;
          break;
        }
      }
    }

    if (finish) return asteroids;

    vector<int> res;
    int i = 0;
    while (i < asteroids.size()-1) {
      if ((asteroids[i] > 0 && asteroids[i+1] > 0) ||
          (asteroids[i] < 0 && asteroids[i+1] < 0)) {
        res.push_back(asteroids[i]);
        ++i; continue;
      }
      if (abs(asteroids[i]) == abs(asteroids[i+1])) {
        i += 2;
      } else {
        if (abs(asteroids[i]) > abs(asteroids[i+1])) {
          res.push_back(asteroids[i]);
        } else {
          res.push_back(asteroids[i+1]);
        }
        i += 2;
      }
    }

    return asteroidCollision(res);
  }
};

int main()
{
}
