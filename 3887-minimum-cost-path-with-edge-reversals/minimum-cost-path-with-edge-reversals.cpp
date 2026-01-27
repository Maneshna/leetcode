class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n), radj(n);

    for (auto &e : edges) {
        int u = e[0], v = e[1], w = e[2];
        adj[u].push_back({v, w});
        radj[v].push_back({u, w});
    }

    const long long INF = 1e18;
    vector<vector<long long>> dist(n, vector<long long>(2, INF));

    priority_queue<array<long long,3>,
        vector<array<long long,3>>,
        greater<array<long long,3>>> pq;

    dist[0][0] = 0;
    pq.push({0, 0, 0}); // cost, node, used_switch_at_node

    while (!pq.empty()) {
        auto [cost, u, used] = pq.top();
        pq.pop();

        if (cost > dist[u][used]) continue;

        // Normal edges
        for (auto &[v, w] : adj[u]) {
            if (dist[v][0] > cost + w) {
                dist[v][0] = cost + w;
                pq.push({dist[v][0], v, 0});
            }
        }

        // Reversed edges (only if switch unused at u)
        if (used == 0) {
            for (auto &[v, w] : radj[u]) {
                if (dist[v][0] > cost + 2LL * w) {
                    dist[v][0] = cost + 2LL * w;
                    pq.push({dist[v][0], v, 0});
                }
            }
        }
    }

    long long ans = min(dist[n-1][0], dist[n-1][1]);
    return ans == INF ? -1 : ans;
    }
};