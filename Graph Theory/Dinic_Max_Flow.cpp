#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
     Total Time Complexity: O(V^2 * E)
     Total Space Complexity: O(V + E)
*/
struct Dinic {
    struct Edge {
        int to;
        ll cap, flow = 0;
        Edge(int to, ll cap) : to(to), cap(cap) {}
    };

    const ll INF = 1e18;
    vector<Edge> edges;
    vector<vector<int>> adj;
    vector<int> level, ptr;
    int n, s, t;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int from, int to, ll cap) {
        adj[from].push_back(edges.size());
        edges.emplace_back(to, cap);
        adj[to].push_back(edges.size());
        edges.emplace_back(from, 0);
    }

    bool bfs() {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow > 0 && level[edges[id].to] == -1) {
                    level[edges[id].to] = level[v] + 1;
                    q.push(edges[id].to);
                }
            }
        }
        return level[t] != -1;
    }

    ll dfs(int v, ll pushed) {
        if (pushed == 0 || v == t) return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); ++cid) {
            int id = adj[v][cid];
            int u = edges[id].to;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow == 0) continue;
            ll tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0) continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    ll max_flow() {
        ll flow = 0;
        while (bfs()) {
            fill(ptr.begin(), ptr.end(), 0);
            while (ll pushed = dfs(s, INF)) {
                flow += pushed;
            }
        }
        return flow;
    }
};