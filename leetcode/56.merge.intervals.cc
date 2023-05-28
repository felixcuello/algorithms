class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;
    intervals.push_back({20000,20000});
    
    sort(intervals.begin(), intervals.end());
    
    int a = intervals[0][0]; // begin
    int b = intervals[0][1]; // end
    for(auto c : intervals) {
      if(c[0] > b) {
        ans.push_back({a,b});
        a = c[0];
        b = c[1];
      } else {
        if(c[1] > b)
          b = c[1];
      }
    }
    
    return ans;
  }
};

/*

IDEA: O(n * log(n))

1. Sort intervals
2. Keep track of the last starting start/end overlap (and try to create intervals as bigger as possible)
3. QUICK FIX => I added a fake interval (outside the last one), because the algorithm does not add the last one if it's disjoint :shrug:

*/
