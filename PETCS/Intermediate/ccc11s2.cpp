#include <bits/stdc++.h>
using namespace std;
const int MN = 10001;
int N, cnt = 0; char a[MN], b[MN];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < N; i++) {
        if(a[i] == b[i]) {
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
