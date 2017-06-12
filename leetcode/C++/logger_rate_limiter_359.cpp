#include "common.hpp"

// time:
// space:
class Logger {
private:
  unordered_map<string, int> m2t;
public:
  /** Initialize your data structure here. */
  Logger() {

  }

  /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
      If this method returns false, the message will not be printed.
      The timestamp is in seconds granularity. */
  bool shouldPrintMessage(int timestamp, string message) {
    if (m2t.find(message) == m2t.end()) {
      m2t[message] = timestamp;
      return true;
    } else {
      if (timestamp - m2t[message] >= 10) {
        m2t[message] = timestamp;
        return true;
      } else {
        return false;
      }
    }
  }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */

int main()
{
}
