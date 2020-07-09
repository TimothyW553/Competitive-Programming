#include <bits/stdc++.h>
using namespace std;

int n, ans;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    switch(n) {
        case 1: 
            ans = 1;
            break;
        case 2:
            ans = 2;
            break;
        case 3:
            ans = 2;
            break;
        case 4:
            ans = 3;
            break;
        case 5:
            ans = 3;
            break;
        case 6:
            ans = 3;
            break;
        case 7:
            ans = 2;
            break;
        case 8:
            ans = 2;
            break;
        case 9:
            ans = 1;
            break;
        case 10:
            ans = 1;
            break;
    }
    cout << ans << "\n";
    return 0;
}
