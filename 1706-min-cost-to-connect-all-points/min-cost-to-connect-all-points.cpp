class Solution {
public:

    vector<int> parent;
    vector<int> rank_dsu;


    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    }

    void makeSet(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank_dsu.assign(n, 0);
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
            if (rank_dsu[u] < rank_dsu[v]) {
                parent[u] = v;
            } else if (rank_dsu[v] < rank_dsu[u]) {
                parent[v] = u;
            } else {
                parent[v] = u;
                rank_dsu[u]++;
            }
        }
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        if (n <= 1) {
            return 0;
        }

        vector<vector<int>> actual_edges;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dist = abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1]);
                actual_edges.push_back({i, j, dist});
            }
        }

        sort(actual_edges.begin(), actual_edges.end(), cmp);

        makeSet(n);

        int minweight = 0;
        int edges_added = 0;

        for (int i = 0; i < actual_edges.size(); ++i) {
            int u_node = actual_edges[i][0];
            int v_node = actual_edges[i][1];
            int wt = actual_edges[i][2];

            int root_u = findParent(u_node);
            int root_v = findParent(v_node);

            if (root_u != root_v) {
                minweight += wt;
                unionset(u_node, v_node);
                edges_added++;

                if (edges_added == n - 1) {
                    break;
                }
            }
        }
        return minweight;
    }
};