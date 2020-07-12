#include <bits/stdc++.h>
using namespace std;
const int MN = 100005;
int N, a[MN];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a, a+N);
    for(int i = 0; i < N; i++) {
        cout << a[i] << "\n";
    }
    return 0;
}
