#include "common.hpp"

// time:
// space:
class Solution {
public:
  vector<int> constructRectangle(int area) {
    vector<int> lw {};
    for (int i = (int)floor(sqrt(area)); i > 0; --i) {
      if (area % i == 0) {
        lw.push_back(area / i);
        lw.push_back(i);
        break;
      }
    }

    return lw;
  }
};

int main()
{
  Solution sol;
  vector<int> res = sol.constructRectangle(10);
  cout << "len: " << res[0] << ", width: " << res[1] << endl;
}
