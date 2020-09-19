#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int H, K, ar[1005];
int diff(int a, int b) {
    if(a > b) {
        swap(a, b);
    }
    return min(b-a, a-b+1000000);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> H;
    for(int i = 0; i < H; i++) {
        cin >> ar[i];
    }
    sort(ar, ar+H);
    cin >> K;
    int lo = 0, hi = 500000;
    while(lo < hi) {
        int mid = lo + (hi - lo) / 2;
        int best = INF;
        for(int i = 0; i < H; i++) {
            int cnt = 1, pos = ar[i];
            for(int j = 0; j < H; j++) {
                if((diff(pos, ar[(i+j)%H])+1)/2 > mid) {
                    pos = ar[(i+j)%H];
                    cnt++;
                }
            }
            best = min(best, cnt);
        }
        if(best <= K) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << hi << "\n";
    return 0;
}
