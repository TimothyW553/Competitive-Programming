#include <bits/stdc++.h>
using namespace std;

set<int> st;
int n, d;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> d;
        st.insert(d);
    }
    cout << st.size() << "\n";
    return 0;
}
