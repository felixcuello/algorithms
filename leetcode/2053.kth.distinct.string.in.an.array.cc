class Solution {
public:
  string kthDistinct(vector<string>& arr, int k) {
    map<string, int> freq;
    int as = arr.size();
    for(int i=0; i<as; i++)
      freq[arr[i]] += 1;
    
    int c = 0;
    for(int i=0; i<as; i++) {
      if(freq[arr[i]]==1) {
        c++;
        if(c == k)
          return arr[i];
      }
    }
    
    return "";
  }
};
/*
IDEA: O(2n)

1. Calculate the frequencies for all the leters
2. Traverse the array again looking for the k-th unique letter

*/
