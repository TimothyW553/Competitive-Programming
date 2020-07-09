#include <bits/stdc++.h>
using namespace std;

int a[4][4];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> a[i][j];
        }
    }
    int refsum = a[0][0] + a[0][1] + a[0][2] + a[0][3];
    for(int i = 0; i < 4; i++) {
        int tmpsum = 0, tmpsum2 = 0;
        for(int j = 0; j < 4; j++) {
            tmpsum += a[i][j];
            tmpsum2 += a[j][i];
        }
        if(tmpsum != refsum or tmpsum2 != refsum) {
            return cout << "not magic" << "\n", 0;
        }
    }
    cout << "magic" << "\n";
    return 0;
}
