class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int last = nums[0];
    int count = 1;
    for(int i=1; i<nums.size(); i++) {
      if(last != nums[i]) {
        count--;
        if(count <= 0) {
          last = nums[i];
          count = 1;
        }
      } else {
        count++;
      }
    }
    
    return last;
  }
};
