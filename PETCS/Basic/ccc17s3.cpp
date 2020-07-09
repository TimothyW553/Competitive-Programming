#include <bits/stdc++.h>
using namespace std;

int N, a[2005], b[4005];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    cin >> N;
    int m;
    for(int i = 0; i < N; i++) {
        cin >> m;
        a[m]++;
    }
    // b is the array where i represents the number of ways to get to i from a
    for(int i = 1; i < 2001; i++) {
        for(int j = i; j < 2001; j++) {
            if(i == j) {
                b[i+j] += a[i] / 2; // a[i] / 2 because the number of ways to get to i*2 is a[i]/2
            } else {
                b[i+j] += min(a[i], a[j]); // we take the min bcus we cant take more 
            }
        }
    }
    int mxn = 1, cnt = 0;
    // find highest fence and number of fences equal to it, reset to 1 if found a fence that is higher
    for(int i = 1; i < 4001; i++) {
        if(b[i] > mxn) {
            mxn = b[i];
            cnt = 1;
        } else if(b[i] == mxn) {
            cnt++;
        }
    }
    cout << mxn << " " << cnt << "\n";
    return 0;
}
