#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for(ll i = 1; i <= N; i <<= 1) {
        cout << "1";
    }
    return 0;
}
