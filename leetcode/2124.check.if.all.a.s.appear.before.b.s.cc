class Solution {
public:
    bool checkString(string s) {
      int sl = s.length();
      int checking_a = false;
      for(int i=sl-1; i>=0; i--) {
        if(s[i] == 'b' && checking_a)
          return false;
        if(s[i] == 'a')
          checking_a = true;
      }
      
      return true;
    }
};
