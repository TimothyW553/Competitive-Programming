#include <bits/stdc++.h>
using namespace std;
int N, sum = 0; stack<int> st;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N;
    for(int i = 0, m; i < N; i++) {
        cin >> m;
        if(m != 0) {
            st.push(m);
        } else {
            st.pop();
        }
    }
    while(!st.empty()) {
        sum += st.top(); st.pop();
    }
    cout << sum << "\n";
    return 0;
}
