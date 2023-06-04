#include<bits/stdc++.h>

#define UL unsigned long
#define ULL unsigned long long
#define LL long long

using namespace std;

void pp(const vector<int>& v) {
        for(int i=0; i<v.size(); i++)
                cout << v[i] << " ";
        cout << endl;
}

void compute(vector<int>& in, vector<int>& cur, int used = 0) {
        int is = in.size();

        if(is == cur.size()) {
                pp(cur);
                return;
        }

        for(int i=0; i<is; i++) {
                if(used & (1 << i)) continue;
                cur.push_back(in[i]);
                compute(in, cur, used | (1 << i));
                cur.pop_back();
        }
}

int main() {
        vector<int> input = {1,2,3};
        vector<int> cur;
        compute(input, cur);
        return 0;
}
