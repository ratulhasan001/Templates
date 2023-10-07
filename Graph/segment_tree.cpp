#include <bits/stdc++.h>
using namespace std;

vector<int> v;       
vector<int> seg_tree;   

void build_seg_tree(int node, int begin, int end) {

    if(begin == end) {
        seg_tree[node] = v[begin];
        return;
    }
    int left, right, mid;
    left = node * 2;
    right = (node * 2) + 1;             
    mid = begin + ((end - begin) / 2);    
    build_seg_tree(left, begin, mid);        
    build_seg_tree(right, mid + 1, end); 
    // as per condition
    seg_tree[node] = min(seg_tree[left], seg_tree[right]); // min case
    // seg_tree[node] = seg_tree[left] + seg_tree[right]; // for addition case
}

int query(int node, int begin, int end, int i, int j) {

    if(end < i or j < begin) return INT_MAX;
    // if(end < i or j < begin) return 0; // for addition case
        
    if(i <= begin and end <= j) return seg_tree[node];

    int left, right, mid, q1, q2;
    left = node*2;
    right = (node * 2) + 1;
    mid = begin + ((end - begin) / 2);
    q1 = query(left, begin, mid, i, j);  
    q2 = query(right, mid+1, end, i, j);
    // operation of the query
    // here the query is to find minimum in given range
    // return q1 + q2; // for addition case
    return min(q1, q2);                     
}
void update(int node, int begin, int end, int i, int newvalue) {
    if (i > end or i < begin)
        return; 
    if (begin >= i and end <= i) { 
        seg_tree[node] = newvalue; // single update
        return;
    }
    // if (begin == i and end == i) { 
    //     seg_tree[node] += newvalue; // for addition in that element
    //     return;
    // }
    int Left = node * 2; 
    int Right = node * 2 + 1;
    int mid = (begin + end) / 2;
    update(Left, begin, mid, i, newvalue);
    update(Right, mid + 1, end, i, newvalue);
    seg_tree[node] = seg_tree[Left] + seg_tree[Right];
}
int32_t main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    
    int n;
    cin >> n;
    v.assign(n + 2, 0);
    seg_tree.assign((4 * n) + 2, 0);
    for(int i = 1; i <= n; i++) cin>>v[i];
        
    build_seg_tree(1, 1, n);   
    int q;
    cin >> q;
    while (q--) {
        int i, j;
        cin >> i >> j;
        cout << query(1, 1, n, i + 1, j + 1) << "\n";    
    }
    
    
    return 0;
}


