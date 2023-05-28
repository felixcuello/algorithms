#include<bits/stdc++.h>

#define UL unsigned long
#define ULL unsigned long long
#define LL long long

#define BEGZ(x) __builtin_clz(x)      // Return the number of zeroes at the beginning of the bit representation
#define ENDZ(x) __builtin_ctz(x)      // Return the number of zeroes at the end of the bit representation
#define ONES(x) __builtin_popcount(x) // Return the number of ones in the bit representation
#define PARITY(x) __builtin_parity(x) // Return the parity of the numbers of one in the bit representation
#define FOR(a,b) for(unsigned long i=a; i<b; i++)

#define DEBUG true

using namespace std;

class Solution {
public:
        void bt(string tiles, unordered_set<string>& things, string current = "", int used = 0, int k = 0) {
                int tl = tiles.length();

                if(k == tl) {
                        if(things.find(current) == things.end()) {
                                things.insert(current);
                                if(DEBUG) cout << current << endl;
                        }
                        return;
                }

                for(int i=0; i<tl; i++) {
                        if(used & (1 << i)) continue;
			current.push_back(tiles[i]);
                        bt(tiles, things, current, used | (1 << i), k+1);
			current.pop_back();
                        bt(tiles, things, current, used, k+1);
                }
        }

        int numTilePossibilities(string tiles) {
                unordered_set<string> things;
                things.insert("");
                bt(tiles, things);
                return things.size() - 1;
        }
};

int main() {
        cin.sync_with_stdio(false);
        Solution* sol = new Solution();
        sol->numTilePossibilities("AAAAA");
        return 0;
}
