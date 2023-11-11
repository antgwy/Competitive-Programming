#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    if (n < 3) { cout << s << "\n"; exit(0); }
    vector<int> sta(n + 1);
    int top = 0, ptr = 2;
    sta[++top] = s[0] - 'A';
    sta[++top] = s[1] - 'A';
    while (ptr < n) {
        sta[++top] = s[ptr++] - 'A';
        while (top >= 3 && sta[top] == 2) {
            int f = 1;
            for (int i = 0; i < 3; ++i) {
                if (sta[top-i] != 2 - i) {
                    f = 0; break;
                }
            }
            if (f) top -= 3;
            else break;
        }
    }
    for (int i = 1; i <= top; ++i) {
        cout << char('A' + sta[i]);
    }
    cout << "\n";
    return 0;
}