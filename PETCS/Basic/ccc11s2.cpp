#include <bits/stdc++.h>
using namespace std;

int N;
string que[10005], ans[10005];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> que[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> ans[i];
    }
    int count = 0;
    for(int i = 0; i < N; i++) {
        if(ans[i] == que[i]) {
            count++;
        }
    }
    cout << count << "\n";
    return 0;
}
