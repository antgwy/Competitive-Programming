class DSU {
private:
    vector<int> par, rk, w;
public:
    DSU(int n) : par(n), rk(n, 0), w(n, INT_MAX) {
        for (int i = 0; i < n; ++i) par[i] = i;
    }

    int find(int x) {
        if (x != par[x])
            par[x] = find(par[x]);
        return par[x];
    }

    void unite(int x, int y, int weight) {
        int fx = find(x), fy = find(y);
        if (fx != fy) {
            if (rk[fx] < rk[fy]) swap(fx, fy);
            par[fy] = fx;
            w[fx] &= w[fy] & weight;
            if (rk[fx] == rk[fy]) rk[fx]++;
        } 
        else w[fx] &= weight;
    }

    int getMin(int x) {
        int fx = find(x);
        return w[fx];
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        DSU dsu(n);
        for (auto& e : edges) {
            dsu.unite(e[0], e[1], e[2]);
        }

        vector<int> ans;
        for (auto& q : queries) {
            if (q[0] == q[1]) { ans.push_back(0); continue; }
            if (dsu.find(q[0]) == dsu.find(q[1])) {
                ans.push_back(dsu.getMin(q[0]));
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};