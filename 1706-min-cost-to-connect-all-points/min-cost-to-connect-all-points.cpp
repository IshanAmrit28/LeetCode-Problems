class Solution {
public:

    vector<int> parent;
    vector<int> rank;


    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    }

    void makeSet(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank.assign(n, 0);
    }

    int findParent(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }


    void unionset(int u, int v) {
        u = findParent(u);
        v = findParent(v);
        if (u != v) {
            if (rank[u] < rank[v]) {
                parent[u] = v;
            } else if (rank[v] < rank[u]) {
                parent[v] = u;
            } else {
                parent[v] = u;
                rank[u]++;
            }
        }
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        if (n <= 1) {
            return 0;
        }
        //yaha pr weight daal dia sbka manhatan distance leke
        // and isko bol lo adjacency matrix
        vector<vector<int>> adj;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dist = abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1]);
                adj.push_back({i, j, dist});
            }
        }
        //sort kr lia taki asan rakhe shortest edge leni hai ahr baar
        sort(adj.begin(), adj.end(), cmp);

        makeSet(n);

        int minweight = 0;
        int edges_added = 0;
        // matrix se values leke array wale me checck krna hai 
        for (int i = 0; i < adj.size(); ++i) {
            int u = adj[i][0];
            int v = adj[i][1];
            int wt = adj[i][2];

            int root_u = findParent(u);
            int root_v = findParent(v);

            if (root_u != root_v) {
                minweight += wt;
                unionset(u, v);
                edges_added++;

                if (edges_added == n - 1) {
                    break;
                }
            }
        }
        return minweight;
    }
};