class Solution {
    typedef long long ll;
public:
    long long beautifulSubstrings(string s, int k) {
        vector<int> vow(26);
        vow[0] = 1; vow['e'-'a'] = 1; vow['i'-'a'] = 1;
        vow['o'-'a'] = 1; vow['u'-'a'] = 1;
        int n = s.length(), sum = 0, m = 1;
        for(; m < k; ++m) if(m * m % k == 0) break;
        m <<= 1;
        map<pair<int, int>, int> cnt;
        cnt[make_pair(0, 0)] = 1;
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (vow[s[i-1]-'a']) sum++;
            else sum--;
            auto it = cnt.find(make_pair(i % m, sum));
            if (it == cnt.end()) cnt[make_pair(i % m, sum)] = 1;
            else ans += it->second++;
        }
        return ans;
    }
};