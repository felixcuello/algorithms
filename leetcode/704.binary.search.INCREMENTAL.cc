class Solution {
public:
  int search(vector<int>& nums, int target) {
    // incremental binary search
    int start = 0;
    int ns = nums.size();
    for(int step=ns/2; step >= 1; step /= 2)
      while(start+step < ns && nums[start+step] <= target) start += step;

    if(nums[start] == target)
      return start;
    
    return -1;
  }
};

/*
This is another way to implement a binary search
*/
