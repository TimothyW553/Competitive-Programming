#include <bits/stdc++.h>
using namespace std;

int N;
stack<int> st;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N;
    int m;
    for(int i = 0; i < N; i++) {
        cin >> m;
        if(m == 0) {
            st.pop();
        } else {
            st.push(m);
        }
    }
    int sum = 0;
    while(!st.empty()) {
        sum += st.top();
        st.pop();
    }
    cout << sum << "\n";
    return 0;
}
