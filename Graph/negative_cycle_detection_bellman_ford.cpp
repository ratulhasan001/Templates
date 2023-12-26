// #include <bits/stdc++.h>
// using namespace std;

// class Edge {
// public:
//     int u;
//     int v;
//     int w;
//     Edge(int u, int v, int w) {
//         this->u = u;
//         this->v = v;
//         this->w = w;
//     }
// };

// int32_t main() {
//     ios_base::sync_with_stdio(false); 
//     cin.tie(nullptr); 

//     int n, e;
//     cin >> n >> e;
//     vector<Edge> g;
//     while (e--) {
//         int a, b, w;
//         cin >> a >> b >> w;
//         Edge ed(a, b, w);
//         g.push_back(ed);
//     }
//     int dis[n + 1];
//     for (int i = 1; i <= n; i++)
//     {
//         dis[i] = INT_MAX;
//     }
//     dis[1] = 0;
//     for (int i = 1; i <= n - 1; i++) {
//         for (int j = 0; j < g.size(); j++) {
//             Edge ed = g[j];
//             int a = ed.u;
//             int b = ed.v;
//             int w = ed.w;
//             if (dis[a] + w < dis[b]) {
//                 dis[b] = dis[a] + w;
//             }
//         }
//     }
//     bool cycle = false;
//     for (int j = 0; j < g.size(); j++) {
//         Edge ed = g[j];
//         int a = ed.u;
//         int b = ed.v;
//         int w = ed.w;
//         if (dis[a] + w < dis[b]) {
//             cycle = true;
//             break;
//             dis[b] = dis[a] + w;
//         }
//     }
//     if (cycle) {
//         cout << "Cycle Exist" << endl;
//     }
//     else {
//         for (int i = 1; i <= n; i++) {
//             cout << "Node " << i << ": " << dis[i] << endl;
//         }
//     }
//     return 0;
// }

// using pair

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair < ll, ll > ;
const char nl = '\n';

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define minimum(x) * min_element(x.begin(), x.end())
#define maximum(x) * max_element(x.begin(), x.end())

const int N = 1e5 + 7;
const ll INF = 1e18 + 7;
vector < pii > g[N];
vector < pair < pii, ll >> list_of_edges;
ll d[N];
int n, m;
bool cycle = false;
void bellman_ford(int source) {
    for (int i = 1; i <= n; i++) d[i] = INF;

    d[source] = 0;

    for (int i = 1; i < n; i++) {
        for (auto edge: list_of_edges) {
            ll u = edge.first.first;
            ll v = edge.first.second;
            ll w = edge.second;

            if (d[u] != INF && d[v] > d[u] + w)
                d[v] = d[u] + w;
        }
    }
    for (auto edge: list_of_edges) {
        ll u = edge.first.first;
        ll v = edge.first.second;
        ll w = edge.second;

        if (d[u] != INF && d[v] > d[u] + w) {
            cycle = true;
            break;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    while (m--) {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        list_of_edges.push_back({{u, v}, w});
    }
    int source;
    cin >> source;

    bellman_ford(source);

    int q, flag = 0;
    cin >> q;

    while (q--) {
        int x;
        cin >> x;
        if (cycle) {
            flag = 1;
            continue;
        }
        if (d[x] == INF) cout << "Not Possible" << '\n';
        else cout << d[x] << endl;
    }
    if (flag and cycle) cout << "Negative Cycle Detected" << '\n';

    return 0;

}