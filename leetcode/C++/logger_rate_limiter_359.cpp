#include "common.hpp"

// time:
// space:

class LoggerOld {
private:
  unordered_map<string, int> m2t;
public:
  /** Initialize your data structure here. */
  LoggerOld() {

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


// Use a HashMap to map each message to an integer t where t = timestamp + 10.
// Thus if the same message received before t, just return false; if the same message
// received at or after t, update HashMap entry and return true.

class Logger {
public:
  /** Initialize your data structure here. */
  Logger() {
  }

  /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
      If this method returns false, the message will not be printed.
      The timestamp is in seconds granularity. */
  bool shouldPrintMessage(int timestamp, string message) {
    if (timestamp >= msg2time[message]) {
      msg2time[message] = timestamp + 10;
      return true;
    }
    return false;
  }

private:
  unordered_map<string, int> msg2time;
};


class Logger2 {
private:
  int hash(string& s) { // naive hashing
    int val = 0;
    for (char c : s) val += c;
    return val;
  }

public:
  /** Initialize your data structure here. */
  Logger2() {
  }

  /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
      If this method returns false, the message will not be printed.
      The timestamp is in seconds granularity. */
  bool shouldPrintMessage(int timestamp, string message) {
    if (timestamp >= hash2time[hash(message)]) {
      hash2time[hash(message)] = timestamp + 10;
      return true;
    }
    return false;
  }

private:
  unordered_map<int, int> hash2time;
};


class Logger3 {
private:
  uint64_t hash(string& s) { // djb2: http://www.cse.yorku.ca/~oz/hash.html#djb2
    uint64_t val = 5381;
    for (char c : s) val = ((val << 5) + val) + c; // val * 33 + c
    return val;
  }

public:
  /** Initialize your data structure here. */
  Logger3() {
  }

  /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
      If this method returns false, the message will not be printed.
      The timestamp is in seconds granularity. */
  bool shouldPrintMessage(int timestamp, string message) {
    if (timestamp >= hash2time[hash(message)]) {
      hash2time[hash(message)] = timestamp + 10;
      return true;
    }
    return false;
  }

private:
  unordered_map<uint64_t, int> hash2time;
};


/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */

int main()
{
  Logger3 logger;
  cout << logger.shouldPrintMessage(1, "foo") << endl; // true
  cout << logger.shouldPrintMessage(2, "bar") << endl; // true
  cout << logger.shouldPrintMessage(3, "foo") << endl; // false
  cout << logger.shouldPrintMessage(8, "bar") << endl; // false
  cout << logger.shouldPrintMessage(10, "foo") << endl; // false
  cout << logger.shouldPrintMessage(11, "foo") << endl; // true
}
