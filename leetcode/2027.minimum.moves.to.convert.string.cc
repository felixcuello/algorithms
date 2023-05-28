class Solution {
public:
  int minimumMoves(string s) {
    int ss = s.size();
    int i = 0;
    int ans = 0;
    while(i < ss) {
      if(s[i] == 'X') {
        i += 2;
        ans++;
      }
      i++;
    }
    
    return ans;
  }
};

/*

=> Final decision was to go with IDEA 2

IDEA 1: Simulation

Simulating this is trivial, you change X to O every time you find an X
you add 1, and the result is that



IDEA 2: Counting
I think the same of IDEA 1 can be done without modifying the string, by just using a pointer.


*/
