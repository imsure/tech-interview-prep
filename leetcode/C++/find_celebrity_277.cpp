#include "common.hpp"

// time:
// space:

// Forward declaration of the knows API.
bool knows(int a, int b);

// time: O(n)
// space: O(n)

class Solution {
public:
  int findCelebrity(int n) {
    if (n < 2) return -1;

    // check how many people 0 knows
    vector<int> people;
    for (int i = 1; i < n; ++i) {
      if (knows(0, i)) people.push_back(i);
    }

    if (!people.size()) { // 0 doesn't know anyone, 0 might be the only possible celebrity
      for (int i = 1; i < n; ++i) {
        if (!knows(i, 0)) return -1;
      }
      return 0;
    } else {
      // use two-pointer techinque to find the possible celebrity,
      // i should always point to the possible celebrity.
      int i = 0, j = 1;
      while (i < people.size() && j < people.size()) {
        if (knows(people[i], people[j]) && knows(people[j], people[i])) { // i and j know each other, no one is celebrity
          i = j + 1;
          j = j + 2;
        } else if (knows(people[i], people[j]) && !knows(people[j], people[i])) { // i knows j but j doesnot know i, j might be celebrity
          i = j;
          ++j;
        } else if (!knows(people[i], people[j]) && knows(people[j], people[i])) { // i does know j but j knows i, i might be celebrity
          ++j;
        } else { // they do not know each other, both cannot be celebrity
          i = j + 1;
          j = j + 2;
        }
      }

      if (i < people.size()) {
        for (int k = 0; k < n; ++k) {
          if (k != people[i] && (!knows(k, people[i]) || knows(people[i], k))) return -1;
        }
        return people[i];
      } else {
        return -1;
      }
    }

    return -1;
  }
};

class Solution2 {
public:
  int findCelebrity(int n) {
    if (n < 2) return n;

    int candidate = 0;
    for (int i = 1; i < n; ++i) {
      if (!knows(i, candidate)) candidate = i; // update candidate as i might be candidate
    }

    for (int i = 0; i < n; ++i) {
      if (i == candidate) continue;
      if (!knows(i, candidate) || knows(candidate, i)) return -1;
    }

    return candidate;
  }
};

int main()
{
}
