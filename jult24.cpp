// Hard Question

//https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/description/?envType=daily-question&envId=2025-07-24
/*class Solution {
public:
    int n;
    vector<vector<int>> tree;
    vector<int> nums;
    vector<int> subtreeXOR;
    vector<int> in, out;
    int timer = 0;
    int totalXOR = 0;

    void dfs(int u, int parent) {
        in[u] = timer++;
        subtreeXOR[u] = nums[u];
        for (int v : tree[u]) {
            if (v != parent) {
                dfs(v, u);
                subtreeXOR[u] ^= subtreeXOR[v];
            }
        }
        out[u] = timer++;
    }

    // Check if u is in subtree of v
    bool isDescendant(int u, int v) {
        return in[v] <= in[u] && out[u] <= out[v];
    }

    int minimumScore(vector<int>& nums_, vector<vector<int>>& edges) {
        nums = nums_;
        n = nums.size();
        tree.resize(n);
        subtreeXOR.resize(n);
        in.resize(n);
        out.resize(n);

        // Build tree
        for (auto& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        // Get full tree XOR and subtree XORs
        dfs(0, -1);
        totalXOR = subtreeXOR[0];

        int res = INT_MAX;
        int m = edges.size();
        
        // Try all pairs of edges
        for (int i = 0; i < m; ++i) {
            int a = edges[i][0], b = edges[i][1];
            int u = in[a] > in[b] ? a : b;

            for (int j = i + 1; j < m; ++j) {
                int c = edges[j][0], d = edges[j][1];
                int v = in[c] > in[d] ? c : d;

                int x, y, z;
                if (isDescendant(v, u)) {
                    x = subtreeXOR[v];
                    y = subtreeXOR[u] ^ subtreeXOR[v];
                    z = totalXOR ^ subtreeXOR[u];
                } else if (isDescendant(u, v)) {
                    x = subtreeXOR[u];
                    y = subtreeXOR[v] ^ subtreeXOR[u];
                    z = totalXOR ^ subtreeXOR[v];
                } else {
                    x = subtreeXOR[u];
                    y = subtreeXOR[v];
                    z = totalXOR ^ subtreeXOR[u] ^ subtreeXOR[v];
                }

                int mx = max({x, y, z});
                int mn = min({x, y, z});
                res = min(res, mx - mn);
            }
        }

        return res;
    }
};
*/