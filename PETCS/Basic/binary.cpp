#include <bits/stdc++.h>
using namespace std;

int N;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N;
    int i;
    while(N--) {
        stack<int> st;
        string ans = "";
        cin >> i;
        while(i != 0) {
            st.push(i % 2);
            i /= 2;
        }
        if(st.size() % 4 != 0) {
            for(int j = 0; j < 4-(st.size() % 4); j++) {
                ans += "0";
            }
        }
        while(!st.empty()) {
            ans += to_string(st.top());
            st.pop();
        }
        for(int i = 0; i < ans.size(); i++) {
            if(i%4 == 0 and i != 0) {
                cout << " ";
            }
            cout << ans[i];
        }
        cout << "\n";
    }
    return 0;
}
