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
    int r = stoi(s.substr(3, 3));
    cout << (1 <= r && r <= 349 && r != 316 ? "Yes" : "No") << "\n";
    return 0;
}