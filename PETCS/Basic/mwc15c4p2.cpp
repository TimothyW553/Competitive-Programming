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
    int a[N+5];
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < N; i++) {
        sort(a+i, a+N);
        if(i % 2 == 1) {
            swap(a[i], a[N-1]);
        }
    }
    for(int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
