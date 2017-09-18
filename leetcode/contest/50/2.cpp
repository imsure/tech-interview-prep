#include "../common.hpp"

class MapSum {
public:
  /** Initialize your data structure here. */
  MapSum() {

  }
    
  void insert(string key, int val) {
    data[key] = val;
  }

  bool isPrefix(string s, string& prefix) {
    if (s.size() < prefix.size()) return false;
    for (int i = 0; i < prefix.size(); ++i) {
      if (s[i] != prefix[i]) return false;
    }
    return true;
  }

  int sum(string prefix) {
    int s = 0;
    for (auto& kv : data) {
      if (isPrefix(kv.first, prefix)) s += kv.second;
    }

    return s;
  }

private:
  unordered_map<string, int> data;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */

int main()
{
}
