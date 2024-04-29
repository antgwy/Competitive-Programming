#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> cnt(26), c(101);
    for (int i = 0; i < n; ++i) cnt[s[i]-'a']++;
    for (int i = 0; i < 26; ++i) c[cnt[i]]++;
    int flag = 1;
    for (int i = 1; i < 101; ++i) {
        if (!c[i] || c[i] == 2) continue;
        flag = 0;
        break;
    }
    if (flag) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}