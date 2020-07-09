#include <bits/stdc++.h>
using namespace std;

int n, m;
string adj[5], noun[5];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> adj[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> noun[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << adj[i] << " as " << noun[j] << "\n";
        }
    }
    return 0;
}
