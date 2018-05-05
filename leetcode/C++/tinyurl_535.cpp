#include "common.hpp"

// Design:
// - use 6 chars to encode url
// - each char comes from alphabet set {0-9, a-z, A-Z},
//   which support total (10 + 26 + 26) ^ 6 = 56800235584 unique urls
// - to encode a long url, simply generate a random encoding
// - assign a unique ID to each long url and map the shortUrl to this ID for decoding


class Solution {
private:
  string generate_hash() {
    string hash = "";
    int index;
    for (int i = 0; i < 6; ++i) {
      index = rand() % alphabet.size();
      hash.push_back(alphabet[index]);
    }

    return hash;
  }

public:
  Solution() {
    for (char d = '0'; d <= '9'; ++d) alphabet.push_back(d);
    for (char l = 'a'; l <= 'z'; ++l) alphabet.push_back(l);
    for (char L = 'A'; L <= 'Z'; ++L) alphabet.push_back(L);
  }

  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    longurls.push_back(longUrl);
    string hash = generate_hash();
    shorturl2index[hash] = longurls.size() - 1;
    return "http://tinyurl.com/" + hash;
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    string hash = shortUrl.substr(shortUrl.size() - 6);
    return longurls[shorturl2index[hash]];
  }

private:
  vector<char> alphabet;
  vector<string> longurls;
  unordered_map<string, int> shorturl2index;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main()
{
  Solution sol;
  string url = "https://leetcode.com/problems/design-tinyurl";
  cout << sol.decode(sol.encode(url)) << endl;
}
