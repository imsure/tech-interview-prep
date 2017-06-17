#include "common.hpp"

// time:
// space:
class Solution {
public:
  vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    unordered_map<string, int> word2index;
    int len1 = list1.size();
    int len2 = list2.size();
    int min_index_sum = len1 + len2;

    for (int i = 0; i < len1; ++i) {
      word2index[list1[i]] = i;
    }

    for (int i = 0; i < len2; ++i) {
      if (word2index.find(list2[i]) != word2index.end()) {
        min_index_sum = min(min_index_sum, i + word2index[list2[i]]);
      }
    }

    vector<string> res;
    for (int i = 0; i < len2; ++i) {
      if (word2index.find(list2[i]) != word2index.end()) {
        if (i + word2index[list2[i]] == min_index_sum) {
          res.push_back(list2[i]);
        }
      }
    }

    return res;
  }
};

int main()
{
  Solution sol;
  vector<string> list1 {"Shogun", "Tapioca Express", "Burger King", "KFC"};
  vector<string> list2 {"KFC", "Shogun", "Burger King"};

  vector<string> res = sol.findRestaurant(list1, list2);
  for (const string& word : res) {
    cout << word << endl;
  }
}
