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
  void reverseString(string& s, int a, int b) {
    while(a < b) {
      if(a == '(' && b == ')') {
        continue;
      }
      swap(s[a], s[b]);
      a++;
      b--;
    }
  }

  string reverseParentheses(string s) {
    vector<int> v = {};
    for(int i=0; i<s.length(); i++) {
      if(s[i] == '(') {
        v.push_back(i);
      } else if(s[i] == ')') {
        int a = v.back(); v.pop_back();
        reverseString(s, a, i);
      }
    }

    string ans;
    for(auto c : s)
      if(c != '(' && c != ')')
        ans.push_back(c);

    return ans;
  }
};

int main() {
        cin.sync_with_stdio(false);
        Solution* sol = new Solution();
        cout << sol->reverseParentheses("u(tuoutf()pa(x(ykigx(wq))(()()cj()(xicb)najyeiw)u(oxn)f(ga(jimkd)(a)rylu)ass)dge)iqk(n()t((yc(afs((a)((j)qf(ksvqg(s)sin)fy()(s(((lid)jy(p(bo()((()jrs)))zauve(krhact(lpw))ne))ng)gm(i)f)t)h()tois)mu))((au)mzpc)(ilqa(tnprm)hmul(y(er)pjj)qnqcd(exx)(pmjkd)(nhexjxhuc)(ehq)t()uo(gnbh)cpmjofgd)(oio()twrzssjt)()iln(vprgttrt(d((yhiwae)ix()owemq)(((pk()h(((jdpt()()l()jkq()mrm((gnu)mq)srz(ua(nofa(nf))dzkikdwlr)ww)qf(q)jhm)()h(o(kt)kbm(ilqr)tq)h(mo)))(g)ln)nmgj)y(()jwetph))(u)mpf(j((xujbp)ezg(((nucbr(g)ckndk))))))))") << endl;
        return 0;
}

