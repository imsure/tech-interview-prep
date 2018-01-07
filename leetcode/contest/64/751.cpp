#include "../common.hpp"

class Solution {
public:
  vector<string> ipToCIDR(string ip, int range) {
    vector<string> ans;
    vector<int> fields;
    stringstream ss (ip);
    string token;
    while (std::getline(ss, token, '.')) {
      if (!token.empty()) fields.push_back(stoi(token));
    }

    // for (auto f : fields) cout << f << endl;

    ans.push_back(ip + "/32");
    int count = 1;
    int findex = 3;
    while (count != range) {
      int f = fields[findex];
      if (f + 1 > 255) {
        --findex; continue;
      } else {

      }
    }

    return ans;
  }
};

int main()
{
  Solution sol;
  sol.ipToCIDR("255.0.0.7", 10);
}
