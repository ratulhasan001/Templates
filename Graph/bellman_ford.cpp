#include <bits/stdc++.h>
using namespace std;
int n, e;
class Edge {
public:
    int u;
    int v;
    int w;
    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

void bellman_ford(int source,vector<Edge> &g) {
    int dis[n + 1];
    for (int i = 1; i <= n; i++) {
        dis[i] = INT_MAX;
    }
    dis[source] = 0;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < g.size(); j++) {
            Edge ed = g[j];
            int a = ed.u;
            int b = ed.v;
            int w = ed.w;
            if (dis[a] + w < dis[b]) {
                dis[b] = dis[a] + w;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << ": " << dis[i] << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 


    cin >> n >> e;
    vector<Edge> g;
    while (e--) {
        int a, b, w;
        cin >> a >> b >> w;
        Edge ed(a, b, w);
        g.push_back(ed);
    }
    int source = 1;
    bellman_ford(source,g);
    
    return 0;
}