#include "common.hpp"

// time:
// space:
class Solution {
public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    int g_size = g.size();
    int s_size = s.size();

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int g_index = 0, s_index = 0;
    int nContent = 0;
    while (g_index < g_size && s_index < s_size) {
      if (s[s_index] >= g[g_index]) {
        ++nContent;
        ++g_index;
        ++s_index;
      } else {
        ++s_index;
      }
    }

    return nContent;
  }
};

int main()
{
  Solution sol;
  vector<int> g {1,2,3}, s {1,2, 4};
  cout << sol.findContentChildren(g, s) << endl;
}
