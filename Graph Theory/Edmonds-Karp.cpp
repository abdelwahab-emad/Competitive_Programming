#include <bits/stdc++.h>

using namespace std;

#define int long long
const int OO = 1e18;

/*
  Time Complexity: O(V * E^2)
  Space Complexity: O(V^2)
*/



struct EdmondsKarp {
    int n;
    vector<vector<int>> cap;
    vector<vector<int>> adj;
    vector<int> par;

    EdmondsKarp(int nodes) {
        n = nodes;
        cap.assign(n + 1, vector<int>(n + 1, 0));
        adj.assign(n + 1, vector<int>());
        par.assign(n + 1, -1);
    }

    void addEdge(int u, int v, int c) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        cap[u][v] += c;
    }

    int getFlow(int src, int sink) {
        fill(par.begin(), par.end(), -1);
        par[src] = -2;
        queue<pair<int, int>> q;
        q.push({src, OO});

        while (!q.empty()) {
            auto [node, flow] = q.front();
            q.pop();

            for (auto nei: adj[node]) {
                if (par[nei] == -1 and cap[node][nei] > 0) {
                    par[nei] = node;
                    int newFlow = min(flow, cap[node][nei]);
                    if (nei == sink) return newFlow;
                    q.push({nei, newFlow});
                }
            }
        }
        return 0;
    }

    int maxFlow(int src, int sink) {
        int totalFlow = 0;
        int currentFlow;
        while (currentFlow = getFlow(src, sink)) {
            totalFlow += currentFlow;
            int cur = sink;
            while (cur != src) {
                int u = par[cur], v = cur;
                cap[u][v] -= currentFlow;
                cap[v][u] += currentFlow;
                cur = u;
            }
        }
        return totalFlow;
    }
};


signed main() {
    int n, m;
    cin >> n >> m;
    EdmondsKarp graph(n);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph.addEdge(a, b, c);
    }

    cout << graph.maxFlow(1, n) << endl;

    return 0;
}
