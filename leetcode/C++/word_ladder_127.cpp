#include "common.hpp"

// time:
// space:

// wrong DFS attemp

class Solution {
private:
  void _ladderLength(string beginWord, string endWord, unordered_set<string> visited,
                     unordered_set<string>& wordSet, int cur_len) {
    if (beginWord == endWord) {
      minLen = min(minLen, cur_len+1);
      cout << "min len: " << minLen << endl;
      found = true;
      return;
    }

    for (int i = 0; i < beginWord.size(); ++i) {
      string newWord (beginWord);
      for (char c = 'a'; c <= 'z'; ++c) {
        if (c == beginWord[i]) continue;
        newWord[i] = c;
        if (!visited.count(newWord) && wordSet.count(newWord)) {
          //cout << "transformed word: " << newWord << endl;
          visited.insert(newWord);
          _ladderLength(newWord, endWord, visited, wordSet, cur_len+1);
          //visited.erase(newWord);
        }
      }
    }

    return;
  }

public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet, visited;
    for (int i = 0; i < wordList.size(); ++i) {
      wordSet.insert(wordList[i]);
    }

    if (!wordSet.count(endWord)) return 0;

    minLen = numeric_limits<int>::max();
    int cur_len = 0;
    found = false;
    visited.insert(beginWord);
    _ladderLength(beginWord, endWord, visited, wordSet, cur_len);
    return found ? minLen : 0;
  }

private:
  int minLen;
  bool found;
};


// Correct BFS solution.
// In each round of BFS, push all the non-visited neighbors (words in the list that differ with the current visited word
// by only one letter) of the current visited word into the queue. Once we found the endWord, done, if we have
// exhausted all the words in the list but cannot find the endWord, return 0.

class Solution2 {
private:
  void addWords(string beginWord, queue<string>& to_visit, unordered_set<string>& wordSet) {
    // put all the words that differ with the current word by one letter into the queue
    for (int i = 0; i < beginWord.size(); ++i) {
      string word (beginWord);
      for (char c = 'a'; c <= 'z'; ++c) {
        word[i] = c;
        if (wordSet.count(word))
          to_visit.push(word);
      }
    }
  }

public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet;
    for (int i = 0; i < wordList.size(); ++i) {
      wordSet.insert(wordList[i]);
    }

    if (!wordSet.count(endWord)) return 0;
    if (wordSet.count(beginWord)) wordSet.erase(beginWord);

    int min_dist = 1;
    queue<string> to_visit;
    addWords(beginWord, to_visit, wordSet);

    while (!to_visit.empty()) {
      int sz = to_visit.size();
      while (sz--) {
        string word = to_visit.front();
        to_visit.pop();
        wordSet.erase(word); // erase the visited word
        if (word == endWord) return ++min_dist;
        addWords(word, to_visit, wordSet);
      }
      min_dist++; // increment current distance and start the next round of BFS
    }

    return 0;
  }
};


// Two-end BFS solution: approach the solution from both begin and end words.

class Solution3 {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet;
    for (int i = 0; i < wordList.size(); ++i) {
      wordSet.insert(wordList[i]);
    }

    if (!wordSet.count(endWord)) return 0;
    if (wordSet.count(beginWord)) wordSet.erase(beginWord);

    int min_dist = 1;
    unordered_set<string> begin_set, end_set, *set1, *set2;
    begin_set.insert(beginWord);
    end_set.insert(endWord);

    while (!begin_set.empty() && !end_set.empty()) {
      if (begin_set.size() <= end_set.size()) { // pick smaller set as the forward set
        set1 = &begin_set;
        set2 = &end_set;
      } else {
        set1 = &end_set;
        set2 = &begin_set;
      }

      unordered_set<string> interm_set;
      for (auto it = set1->begin(); it != set1->end(); ++it) {
        string word = *it;
        wordSet.erase(word);
        for (int i = 0; i < word.size(); ++i) {
          char letter = word[i];
          for (char c = 'a'; c <= 'z'; ++c) {
            word[i] = c;
            if (wordSet.count(word)) {
              if (set2->count(word)) return ++min_dist;
              interm_set.insert(word);
            }
          }
          word[i] = letter;
        }
      }

      swap(*set1, interm_set);
      min_dist++; // increment current distance and start the next round of BFS
    }

    return 0;
  }
};


int main()
{
  vector<string> wordList1 {"hot","dot","dog","lot","log","cog"};
  vector<string> wordList2 {"git", "hot","dot","dog","lot","log","cog", "got"};
  vector<string> wordList3 {"hot","dot","dog","lot","log","cog"};
  // kiss -> diss -> disk -> dusk -> tusk
  vector<string> wordList4 {"miss","dusk","kiss","musk","tusk","diss","disk","sang","ties","muss"};
  vector<string> wordList5 {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
  Solution3 sol;
  cout << sol.ladderLength("hit", "cog", wordList1) << endl; // 5
  cout << sol.ladderLength("hit", "got", wordList2) << endl; // 3
  cout << sol.ladderLength("abc", "got", wordList3) << endl; // 0
  cout << sol.ladderLength("kiss", "tusk", wordList4) << endl; // 5
  cout << sol.ladderLength("qa", "sq", wordList5) << endl; // 5
}
