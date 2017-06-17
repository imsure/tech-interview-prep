#include "common.hpp"

// time:
// space:
class Solution {
public:
  bool detectCapitalUse(string word) {
    size_t word_size = word.size();
    if (word_size == 1) return true;

    if (isupper(word[0]) && word_size > 1 && isupper(word[1])) {
      for (int i = 2; i < word_size; ++i) {
        if (islower(word[i])) return false;
      }
      return true;
    }

    if (isupper(word[0]) && word_size > 1 && islower(word[1])) {
      for (int i = 2; i < word_size; ++i) {
        if (isupper(word[i])) return false;
      }
      return true;
    }

    if (islower(word[0])) {
      for (int i = 1; i < word_size; ++i) {
        if (isupper(word[i])) return false;
      }
      return true;
    }
  }
};

int main()
{
}
