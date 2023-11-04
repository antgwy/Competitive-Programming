#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;

int a[15][15];
int row[15], col[15], sub[15];

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    int f = 1;
    for (int i = 0; i < 9; ++i) {
    	for (int j = 0; j < 9; ++j) {
    		cin >> a[i][j];
    	}
    }
    for (int i = 0; i < 9; ++i) {
    	memset(row, 0, sizeof(row));
    	memset(col, 0, sizeof(col));
    	memset(sub, 0, sizeof(sub));
    	for (int j = 0; j < 9; ++j) {
    		row[a[j][i]] = 1;
    		col[a[i][j]] = 1;
    	}
    	int rs = 3 * (i / 3);
    	int cs = 3 * (i % 3);
    	for (int j = rs; j < rs + 3; ++j) {
    		for (int k = cs; k < cs + 3; ++k) {
    			sub[a[j][k]] = 1;
    		}
    	}
    	for (int j = 1; j <= 9; ++j) {
    		if (!row[j] || !col[j] || !sub[j]) { f = 0; break; }
    	}
    }
    if (f) cout << "Yes\n";
    else cout << "No\n";
	return 0;
}