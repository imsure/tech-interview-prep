#include "common.hpp"


// map all possible domains to its count then output the list of <value, key>


class Solution {
public:
  vector<string> subdomainVisits(vector<string>& cpdomains) {
    unordered_map<string, int> domain2count;
    for (auto& item : cpdomains) {
      istringstream iss(item);
      int count;
      string domain;
      iss >> count;
      iss >> domain;
      string::size_type start_pos = 0, found_pos = -1;
      do {
        domain = domain.substr(found_pos + 1);
        domain2count[domain] += count;
        found_pos = domain.find('.', start_pos);
      } while (found_pos != string::npos);
    }

    vector<string> ans;
    for (auto& kv : domain2count) {
      stringstream oss;
      oss << kv.second;
      oss << ' ';
      oss << kv.first;
      ans.push_back(oss.str());
    }

    return ans;
  }
};


int main()
{
  Solution sol;
  // vector<string> input {"9001 discuss.leetcode.com"};
  vector<string> input {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
  auto ret = sol.subdomainVisits(input);
  for (auto s : ret) cout << s << endl;
}
