#include <bits/stdc++.h>
using namespace std;

int N;
set<int> st;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N;
    int m;
    while(N--) {
        cin >> m;
        st.insert(m);
    }
    cout << st.size() << "\n";
    return 0;
}
