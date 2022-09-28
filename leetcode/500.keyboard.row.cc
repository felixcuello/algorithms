class Solution {
public:
  bool can_type(vector<set<char>>& kbd, string& word) {
    int row = 0;
    char first = word[0];
    if(kbd[1].find(first) != kbd[1].end())
      row = 1;
    else if(kbd[2].find(first) != kbd[2].end())
      row = 2;
    
    for(int i=0; i<word.length(); i++)
      if(kbd[row].find(word[i]) == kbd[row].end())
        return false;
    
    return true;
  }
  
  vector<string> findWords(vector<string>& words) {
    vector<set<char>> keyboard = {
      {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'},
      {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'},
      {'z', 'x', 'c', 'v', 'b', 'n', 'm', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'}
    };
    vector<string> res;

    for(vector<string>::iterator i=words.begin(); i!=words.end(); i++) {
      if(can_type(keyboard, *i))
        res.push_back(*i);
    }

    return res;
  }
};
