#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
vector < int > g[N];
bool visited[N];
int depth[N];
int height[N];

void dfs(int source) {
    visited[source] = true;
    //cout << "Visiting node: " << u << endl;
    for (int child: g[source]) {
        if (visited[child] == true) continue;
        depth[child] = depth[source] + 1;
        dfs(child);
        height[source] = max(height[source], height[child] + 1);
    }
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

    dfs(1);

    for (int i = 1; i <= n; i++) {
        cout << "Depth of Node " << i << ": " << depth[i] << endl;
    }
    cout << "***************\n";
    for (int i = 1; i <= n; i++) {
        cout << "Height of Node " << i << ": " << height[i] << endl;
    }

    return 0;

}