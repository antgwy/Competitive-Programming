using ll = long long;

class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<vector<pair<int, int> > > g(n);
        for (auto e : edges) {
            g[e[0]].emplace_back(e[1], e[2]);
            g[e[1]].emplace_back(e[0], e[2]);
        }

        auto dijkstra = [&](int s) {
            vector<ll> dis(n, 1e18);
            vector<bool> vis(n);
            dis[s] = 0;
            priority_queue<pair<ll, int> > pq;
            pq.push({0, s});
            while (!pq.empty()) {
                auto [len, u] = pq.top();
                pq.pop();
                len = -len;
                if (vis[u]) continue;
                for (auto [v, w] : g[u]) {
                    if (dis[v] > len + w) {
                        dis[v] = len + w;
                        pq.push({-dis[v], v});
                    }
                }
            }
            return dis;
        };

        auto d1 = dijkstra(0), d2 = dijkstra(n - 1);
        vector<bool> ans(m, false);
        ll dist = d1[n-1];
        if (dist == 1e18) return ans;
        for (int i = 0; i < m; ++i) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if (d1[u] + d2[v] + w == dist || d1[v] + d2[u] + w == dist)
                ans[i] = true;
        }
        return ans;
    }
};