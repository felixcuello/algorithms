#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// ----------------------------------------------------------------------------------------------
//
// dp[n]
//   -1 => not defined
//    1 => can form the word starting from n
//    0 => CAN'T form the word starting from n
//
// f(x > sl) -> false
// f(sl) -> true
// f(n, s) -> substr(n, n+wl, s) == word && f(n+wl, s)   // a word matches and we can start from n+word.length()
// 
// ----------------------------------------------------------------------------------------------
class Solution {
public:
  bool match(int n, string& w, string& s) {
    int sl = s.length();
    int wl = w.length();

    int m = min(sl, wl);
    for(int i=n, j=0; i<n+m; i++, j++)
      if(w[j] != s[i]) return false;

    return true;
  }

  bool f(int n, vector<int>&dp, string&s, vector<string> wordDict) {
    int sl = s.length();
    if(n == sl) return true;
    if(n > sl) return false;
    if(dp[n] != -1) return dp[n] == 1;

    bool can = false;
    for(auto w : wordDict) {
      int wl = w.length();
      if(wl > sl + n) continue; // can't fit the word
      can |= match(n, w, s) && f(n+wl, dp, s, wordDict);
    }
    dp[n] = can;

    return dp[n] == 1;
  }

  bool wordBreak(string s, vector<string> &wordDict) {
    int sl = s.length();
    vector<int> dp;
    for(int i=0; i<sl; i++) dp.push_back(-1);

    return f(0, dp, s, wordDict);
  }
};

int main() {
  Solution* s = new Solution();

  string input_string; cin >> input_string;
  int words; cin >> words;

  vector<string> wordDict;
  for(int i=0; i<words; i++) {
    string word; cin >> word;
    wordDict.push_back(word);
  }

  cout << (s->wordBreak(input_string, wordDict) ? "true" : "false") << endl;

  return 0;
}
