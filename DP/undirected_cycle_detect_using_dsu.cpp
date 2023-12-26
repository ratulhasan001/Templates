#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int parent[N];
int parentSize[N]; // size based dsu 
int parentLevel[N]; // rank based dsu
void dsu_set(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = -1;
        parentSize[i] = 1;
        parentLevel[i] = 0;
    }
}
int dsu_find(int node) {
    while (parent[node] != -1) {
        node = parent[node];
    }
    return node;
}
void dsu_union_using_size(int a, int b) {
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB) {
        if (parentSize[leaderA] > parentSize[leaderB]) {
            // A leader
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
        } else {
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}
void dsu_union_using_rank(int a, int b) {
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB) {
        if (parentLevel[leaderA] > parentLevel[leaderB]) {
            parent[leaderB] = leaderA;
        } else if (parentLevel[leaderB] > parentLevel[leaderA]) {
            parent[leaderA] = leaderB;
        } else {
            parent[leaderB] = leaderA;
            parentLevel[leaderA]++;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e, cnt = 0;
    cin >> n >> e;
    dsu_set(n);
    while (e--) {
        int a, b;
        cin >> a >> b;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if (leaderA == leaderB) cnt++; // cycle detection and counting

        else dsu_union_using_size(a, b);
        // else dsu_union_using_rank(a,b);

    }
    cout << cnt << endl;

    return 0;
}