#include "common.hpp"


class Solution {
public:
  bool isStrobogrammatic(string num) {
    unordered_set<char> basic_nums {'0', '1', '8'};
    int begin = 0, end = num.size() - 1;
    while (begin < end) {
      if (num[begin] == num[end] && basic_nums.count(num[end])) {
        ++begin;
        --end;
        continue;
      }
      if (num[begin] != num[end]
          && ((num[begin] == '6' && num[end] == '9')
              || (num[begin] == '9' && num[end] == '6'))) {
        ++begin;
        --end;
        continue;
      }
      return false;
    }

    if (begin == end && !basic_nums.count(num[end])) return false;
    return true;
  }
};


// better code quality

class Solution2 {
public:
  bool isStrobogrammatic(string num) {
    unordered_map<char, char> table;
    table['0'] = '0';
    table['8'] = '8';
    table['1'] = '1';
    table['6'] = '9';
    table['9'] = '6';

    int l = 0, r = num.size() - 1;
    while (l <= r) {
      if (!table.count(num[l]) || table[num[l]] != num[r]) return false;
      ++l;
      --r;
    }

    return true;
  }
};


int main()
{
  Solution sol;
  cout << std::boolalpha << sol.isStrobogrammatic("69") << endl;
  cout << std::boolalpha << sol.isStrobogrammatic("88") << endl;
  cout << std::boolalpha << sol.isStrobogrammatic("818") << endl;
  cout << std::boolalpha << sol.isStrobogrammatic("9886") << endl;
  cout << std::boolalpha << sol.isStrobogrammatic("9966") << endl;
  cout << std::boolalpha << sol.isStrobogrammatic("6996") << endl; // false
  cout << std::boolalpha << sol.isStrobogrammatic("8108") << endl; // false
}
