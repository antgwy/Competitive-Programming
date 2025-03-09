vector<int> manacher(string s) {
    string t = "#";
    for (auto c : s) {
        t += c;
        t += '#';
    }
    int n = t.size();
    vector<int> r(n);
    for (int i = 1, j = 0; i < n; i++) {
        if (2 * j - i >= 0 && j + r[j] > i) {
            r[i] = min(r[2*j-i], j + r[j] - i);
        }
        while (i >= r[i] && i + r[i] < n && t[i-r[i]] == t[i+r[i]]) {
            r[i] += 1;
        }
        if (i + r[i] > j + r[j]) j = i;
    }
    return r;
}

class Solution {
public:
    string longestPalindrome(string s) {
        auto r = manacher(s);
        int n = s.size(), id = 0, maxr = 0;
        for (int i = 1; i < 2 * n; i++) {
            if (r[i] - 1 > maxr) {
                id = i;
                maxr = r[i] - 1;
            }
        }
        return s.substr((id - maxr) / 2, maxr);
    }
};