#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// dp[k][node] = min cost from src to node using at most k edges
vector<int> bellmanford(vector<vector<int>> &adj, int maxK, int n, int src) {
    // dp[k][node]
    vector<vector<int>> dp(maxK + 1, vector<int>(n, INT_MAX));

    // base case: 0 edges, only src is reachable
    dp[0][src] = 0;

    for (int k = 1; k <= maxK; k++) {
        // carry forward previous row (using 0 extra edges may still be optimal)
        dp[k] = dp[k - 1];
        for (auto &x : adj) {
            int u = x[0];
            int v = x[1];
            int w = x[2];
            if (dp[k - 1][u] != INT_MAX) {
                dp[k][v] = min(dp[k][v], dp[k - 1][u] + w);
            }
        }
    }

    return dp[maxK];
}

int main() {
    // edges: {u, v, weight}
    vector<vector<int>> adj = {
        {0, 1, 4}, {0, 2, 2}, {1, 3, 5}, {2, 1, 1}, {2, 3, 8}, {3, 4, 2}
    };
    int n = 5;   // number of vertices
    int src = 2;

    vector<int> dist = bellmanford(adj, n - 1, n, src);

    for (int i = 0; i < n; i++) {
        cout << "dist[" << src << "][" << i << "] = ";
        if (dist[i] == INT_MAX) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}