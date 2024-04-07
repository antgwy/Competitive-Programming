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
    int t;
    cin >> t;
    while (t--) {
        string time, period = " AM";
        cin >> time;
        int hh = stoi(time.substr(0, 2));
        if (hh == 0) hh = 12;
        else if (hh == 12) period = " PM"; 
        else if (hh > 12) { hh -= 12; period = " PM"; }
        cout << setw(2) << setfill('0') << to_string(hh) << time.substr(2) << period << "\n";
    }
    return 0;
}