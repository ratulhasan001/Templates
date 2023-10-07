#include <bits/stdc++.h>
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    
    int n;
    cin >> n;
    int w[n];
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    int s;
    cin >> s;
    int dp[n + 1][s + 1];
    dp[0][0] = 1;
    for (int i = 1; i <= s; i++) dp[0][i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            if (w[i - 1] <= j) {
                dp[i][j] = dp[i][j - w[i - 1]] + dp[i - 1][j]; // all ways to select (maximum s times)
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][s] << endl;
    return 0;
}


/*

// if the coins can be used maximum c[i] times

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= s; j++) {
                dp[i][j] = dp[i - 1][j];

                for (int k = 1; k <= min(j / w[i - 1], c[i - 1]); k++) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k * w[i - 1]]) 
                }
            }
        }





















*/