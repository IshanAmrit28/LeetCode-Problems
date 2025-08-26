class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for (auto &p : prerequisites)
            adj[p[1]].push_back(p[0]);

        vector<int> vis(n, 0), pathvis(n, 0), topo;
        stack<int> st;

        function<bool(int)> dfs = [&](int u) {
            vis[u] = 1;
            pathvis[u] = 1;
            for (int v : adj[u]) {
                if (!vis[v]) {
                    if (dfs(v)) return true;
                } else if (pathvis[v]) {
                    return true;
                }
            }
            pathvis[u] = 0;
            st.push(u);
            return false;
        };

        for (int i = 0; i < n; i++) {
            if (!vis[i] && dfs(i)) return {};
        }

        while (!st.empty()) {
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
    }
};