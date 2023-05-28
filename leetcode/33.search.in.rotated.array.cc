class Solution {
public:
  int bs_shift(vector<int>& nums, int target, int low, int high, int shift) {
    if(high < low) return -1;
    
    int mid = (high + low) / 2;
    
    //  [ 5  6  0  1  2  3  X ]
    //    l        m        h
    if(target == nums[(mid + shift) % nums.size()]) return (mid + shift) % nums.size();
    
    if(target < nums[(mid + shift) % nums.size()]) {
      return bs_shift(nums, target, low, mid-1, shift);
    } else {
      return bs_shift(nums, target, mid+1, high, shift);
    }
  }
  
  // This returns the shift in O(log n)
  int find_shift(vector<int>& nums, int low, int high) {
    while(true) {
      if(nums[high] < nums[low]) {
        if(high == low + 1) {
          return nums[high] > nums[low] ? low : high;
        }
        
        int mid = (high + low) / 2;
        if(nums[mid] > nums[low]) {
          low = mid;
        } else {
          high = mid;
        }
      } else {
        return low;
      }
    }
  }
  
  int search(vector<int>& nums, int target) {
    int shift = find_shift(nums, 0, nums.size()-1);
    int ans = bs_shift(nums, target, 0, nums.size(), shift);
    
    return ans;
  }
};


/*

IDEA: O(2 log(n))

The array is shifted n positions (n >= 0)

1. I need to know how much is shifted -> In order to do that, we can do a binary search
   trying to find the lower bound.
   
     [6 0 1 2 3 4 5]
      l     m     h

2. Once we know the lower bound we use a binary search using  low+shift / high+shift    (and use modulo operation to get the position)

*/
