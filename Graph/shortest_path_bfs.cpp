#include <bits/stdc++.h>

using namespace std;

//bfs
const int N = 1e5 + 5;
vector < int > g[N];
bool visited[N];
int dis[N];
int par[N];

void bfs(int s) {
    queue < int > q;
    q.push(s);
    dis[s] = 0;
    par[s] = -1;
    visited[s] = true;
    while (!q.empty()) {
        int parent = q.front();
        q.pop();
        for (int child: g[parent]) {
            if (!visited[child]) {
                q.push(child);
                visited[child] = true;
                par[child] = parent;
                dis[child] = dis[parent] + 1;
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e;
    cin >> n >> e;
    while (e--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u); // undirected
    }
    bfs(1);

    // for any specific node source
    int source;
    cin >> source;
    if (visited[source]) {
        vector < int > path;
        int search = source;
        while (search != -1) {
            path.push_back(search);
            search = par[search];
        }
        reverse(path.begin(), path.end());

        for (int val: path) cout << val << " ";
        cout << '\n';
    } else cout << "NO PATH\n";

    return 0;
}