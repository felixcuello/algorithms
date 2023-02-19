#include<bits/stdc++.h>

#define UL unsigned long
#define ULL unsigned long long
#define LL long long

#define BEGZ(x) __builtin_clz(x)      // Return the number of zeroes at the beginning of the bit representation
#define ENDZ(x) __builtin_ctz(x)      // Return the number of zeroes at the end of the bit representation
#define ONES(x) __builtin_popcount(x) // Return the number of ones in the bit representation
#define PARITY(x) __builtin_parity(x) // Return the parity of the numbers of one in the bit representation
#define FOR(a,b) for(unsigned long i=a; i<b; i++)

using namespace std;

int main() {
        cin.sync_with_stdio(false);
        int x,n;
        set<int> s;
        multiset<int> ms;

        cin >> x >> n;
        s.insert(0);
        s.insert(x);
        for(int i=0; i<n; i++) {
                if(i>0) cout << ' ';
                int p; cin >> p;
                set<int>::iterator current;
                pair<set<int>::iterator, bool> res = s.insert(p);

                int left = *prev(res.first);
                int right = *next(res.first);

                ms.insert(p - left);
                ms.insert(right - p);

                multiset<int>::iterator itms = ms.find(right-left);
                if(itms != ms.end())
                        ms.erase(itms);

                // cout << "SET INSERT " << left << " [" << p << "] " << right << endl;
                // cout << "MS  INSERT " << p - left << endl;
                // cout << "MS  INSERT " << right - p << endl;

                cout << *prev(ms.end());
        }

        cout << endl;
        return 0;
}
