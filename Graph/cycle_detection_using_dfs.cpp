#include<bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
vector < int > g[N];
bool visited[N];

bool dfs(int source, int p = -1) {
    bool cycleExists = false;
    visited[source] = true;
    for (int child: g[source]) {
        if (child == p) continue;
        if (visited[child]) return true;
        cycleExists = cycleExists | dfs(child, source);
    }
    return cycleExists;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bool isCycle = false;

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        isCycle |= dfs(i);
    }

    if (isCycle)
        cout << "Cycle Detected!\n";
    else
        cout << "No Cycles!\n";

    return 0;

}