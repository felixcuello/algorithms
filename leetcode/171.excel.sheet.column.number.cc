class Solution {
public:
  int loi(char c) { return c - 'A' + 1; }
  
  int titleToNumber(string columnTitle) {
    int cl = columnTitle.length();
    int ans = 0;
    int power = 0;
    
    for(int i=cl-1; i>=0; i--) {
      ans += loi(columnTitle[i]) * pow(26, power);
      power++;
    }
    
    return ans;
  }
};

/*

IDEA:

This seems to be like converting a base26 number into decimal.
So for example:

A -> 1        = 1
...
Z -> 26       = 26
AA -> 26 + 1  = 27
AB -> 26 + 2  = 28
...
AZ -> 26 + 26 = 52
BA -> 52 + 1  = 53
...
BZ -> 52 + 26 = 78  
CA -> 78 + 1  = 79
...
xy -> 26 * loi(x) + y
...
ZZ -> 26 * 26 + 26 = 702
AAA -> 26^2 * 1 + 26^1 * 1 + 1 = 703
...
*/
