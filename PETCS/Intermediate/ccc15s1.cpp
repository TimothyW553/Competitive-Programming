#include <bits/stdc++.h>
using namespace std;
int N, sum = 0;
stack<int> st;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    int m;
    for(int i = 0; i < N; i++) {
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
