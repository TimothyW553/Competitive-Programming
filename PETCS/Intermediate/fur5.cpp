#include <bits/stdc++.h>
using namespace std;
int N;
void towerofhanoi(int n, char src, char dest, char ind) {
    if(n == 1) {
        cout << src << dest << "\n";
        return;
    }
    towerofhanoi(n-1, src, ind, dest);
    towerofhanoi(1, src, dest, ind);
    towerofhanoi(n-1, ind, dest, src);
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N;
    towerofhanoi(N, 'A', 'C', 'B');
    return 0;
}
