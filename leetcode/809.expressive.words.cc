class Solution {
public:
  bool expressive(string s, string b) {
    int sl = s.length();
    int bl = b.length();
    bool is_expressive = true;

    if(sl < bl) return false;

    int i=0; // pointer b
    int j=0; // pointer s

    b.push_back('+');
    s.push_back('+');

    while(i<bl) {
      int group_count = 0;
      while(b[i] == s[j] && b[i] == b[i+1]) { // skip the group of letters in base
        group_count++;
        i++;
        j++;
      }

      if(b[i] != s[j]) return false; // words are different

      int expressive = false;
      int added = 0;
      while(s[j] == b[i]) {
        added++;
        group_count++;
        j++;
      }

      if(added > 1 && group_count < 3)
        is_expressive = false;
      
      i++;
    }

    return is_expressive && b[i] == '+' && s[j] == '+';
  }

  int expressiveWords(string s, vector<string>& words) {
    int ans = 0;
    for(auto word : words)
      if(s == word || expressive(s, word))
        ++ans;
    return ans;
  }
};
