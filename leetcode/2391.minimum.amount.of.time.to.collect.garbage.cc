class Solution {
public:
  int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    vector<char> trucks = {'M', 'P', 'G'};
    
    vector<int> ext;
    ext.push_back(0);
    for(int i=0; i<travel.size(); i++)
      ext.push_back(travel[i]);
    
    int ts = ext.size(); 
    int ans = 0;
    for(int i=0; i<3; i++) {
      char truck = trucks[i];
      
      int travel_time = 0;
      for(int ti=0; ti<ts; ti++) {
        travel_time += ext[ti];
        bool found = false;
        for(int g=0; g<garbage[ti].size(); g++) {
          if(garbage[ti][g] == truck) {
            ans += 1;
            found = true;
          }
        }
        if(found) {
          ans += travel_time;
          travel_time = 0;
        }
      }
    }
    
    return ans;
  }
};

/*

IDEA: Simulation O(i * i+1 * garbage.length) => 3M iterations :facepalm:

-> The complexity can be reduced creating a HASH based off the garbage containers.

ALGORITHM

It is just a simulation, since the trucks are mutually exclusive 3M simulated is fast enough!

*/

