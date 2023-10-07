#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int N = 1005;
bool vis[N][N];
int dis[N][N];
int n, m;
vector<pii> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool isValid(int cI, int cJ) {
    if (cI >= 0 && cI < n && cJ >= 0 && cJ < m) return true;
    else return false;
}
void bfs(int si, int sj) {
    queue<pii> q;
    q.push({si, sj});
    dis[si][sj] = 0;
    vis[si][sj] = true;
    while (!q.empty()) {
        pii parent = q.front();
        int pI = parent.first;
        int pJ = parent.second;
        q.pop();
        for(pii p : direction) {
            int cI = pI + p.first;
            int cJ = pJ + p.second;
            if (isValid(cI, cJ) && !vis[cI][cJ]) {
                vis[cI][cJ] = true;
                q.push({cI, cJ});
                dis[cI][cJ] = dis[pI][pJ] + 1;
            }
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 

    cin >> n >> m;
    char a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int si, sj;
    cin >> si >> sj;
    bfs(si, sj);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}