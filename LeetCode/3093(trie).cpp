using pii = pair<int, int>;

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int l = 0;
        for (auto e : wordsContainer) l += e.size();
        vector<array<int, 26> > tr(l + 1);
        vector<pii> key(l + 1, {1e9, 0});
        int tot = 0;

        auto insert = [&] (const string &s, int id) {
            int p = 0, len = s.size();
            key[p] = min(key[p], {len, id});
            for (auto ch : s) {
                int c = ch - 'a';
                if (!tr[p][c]) tr[p][c] = ++tot;
                p = tr[p][c];
                key[p] = min(key[p], {len, id});
            }
        };

        for (int i = 0; i < wordsContainer.size(); ++i) {
            auto s = wordsContainer[i];
            reverse(s.begin(), s.end());
            insert(s, i);
        }

        vector<int> ans;
        for (auto s : wordsQuery) {
            reverse(s.begin(), s.end());
            int p = 0;
            for (auto ch : s) {
                int c = ch - 'a';
                if (!tr[p][c]) break;
                p = tr[p][c];
            }
            ans.push_back(key[p].second);
        }
        return ans;
    }
};