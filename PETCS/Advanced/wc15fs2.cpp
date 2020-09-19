#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000005;
int N, M, K, cows[MAX], troughs[MAX], num[MAX];
bool check(int n) {
    fill(num, num+MAX, 0);
    for(int i = N-1; i >= 0; i--) {
        int lo = 0, hi = M;
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if(troughs[mid] > cows[i] || num[mid] >= n) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        } lo--;
        if(lo != -1 and cows[i] - troughs[lo] <= K) {
            num[lo]++;
        } else {
            return false;
        }
    }
    return true;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++) {
        cin >> cows[i];
    }
    for(int i = 0; i < M; i++) {
        cin >> troughs[i];
    }
    sort(cows, cows+N);
    sort(troughs, troughs+M);
    int lo = 1, hi = N+1;
    while(lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if(check(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << (lo != N + 1 ? lo : -1) << "\n";
    return 0;
}