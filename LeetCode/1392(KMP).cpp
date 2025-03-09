vector<int> kmp(string s) {
    int n = s.size();
    vector<int> f(n + 1);
    for (int i = 1, j = 0; i < n; i++) {
        while (j && s[i] != s[j]) j = f[j];
        j += (s[i] == s[j]);
        f[i+1] = j;
    }
    return f;
}

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        auto z = kmp(s);
        return s.substr(0, z[n]);
    }
};