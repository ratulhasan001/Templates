#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
using ll = long long;
using ld = long double;
using u128 = __uint128_t;
using ull = unsigned long long;
using pii = pair < int, int >;
using pll = pair < ll, ll >;
template <typename T> using ordered_set = tree<T, null_type, less<T>,
rb_tree_tag,  tree_order_statistics_node_update>;

#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define minimum(x) *min_element(x.begin(),x.end())
#define maximum(x) *max_element(x.begin(),x.end())

#ifdef ONLINE_JUDGE
#define debug(...) 31
#define debug_array(x,y) 31
#else
#include "deBUG.h"
#endif

void hello_world() {
    
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    for(int testCase = 1; testCase <= T; testCase++) {
    
        hello_world();
        // cout << "Case " << testCase << ": " << ;
    }
    return 0;
}