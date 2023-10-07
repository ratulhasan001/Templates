#include <bits/stdc++.h>
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int s;
    cin >> s;
    bool dp[n + 1][s + 1];
    dp[0][0] = true;
    for (int i = 1; i <= s; i++) {
        dp[0][i] = false;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            if (a[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j - a[i - 1]] || dp[i - 1][j]; // for counting +
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    if (dp[n][s])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    cout<<dp[n][s]; // when we use + insted of ||
    return 0;
}


// Count Subset Sum with Given Difference
/*
    s1 = (dif+sum)/2;
    s1%2==0 true
    just count subset sum of s1
    same is target sum

*/