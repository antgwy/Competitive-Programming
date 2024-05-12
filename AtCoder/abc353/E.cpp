#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

struct Trie {
    struct Node {
        Node *son[26];
        int cnt = 0;
    };
    Node *rt;
    Trie() { rt = new Node(); }
    ll insert(string str) {
        auto cur = rt;
        ll lcpSum = 0;
        int dep = 0;
        for (auto c : str) {
            int id = c - 'a';
            if (!cur->son[id]) {
                cur->son[id] = new Node();
            }
            Node *last = cur;
            cur = cur->son[id];
            cur->cnt++;
            if (cur->cnt < last->cnt) {
                lcpSum += (last->cnt - cur->cnt) * dep;
            }
            dep++;
        }
        if (cur->cnt > 1) lcpSum += (cur->cnt - 1) * dep;
        return lcpSum;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> s(n);
    Trie trie;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        ans += trie.insert(s[i]);
    }
    cout << ans << "\n";
    return 0;
}