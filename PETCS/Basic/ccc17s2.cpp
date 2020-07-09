#include <bits/stdc++.h>
using namespace std;

int N, tides[105];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> tides[i];
    }
    sort(tides, tides+N);
    int low = (N-1)/2, high = low+1;
    for(int i = 0; i < N; i++) {
        if(i % 2 == 1) {
            cout << tides[high++] << " ";
        } else {
            cout << tides[low--] << " ";
        }
    }
    return 0;
}
