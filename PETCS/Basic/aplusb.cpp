#include<bits/stdc++.h>
using namespace std;

int n, a, b;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << a+b << "\n";
    }
    return 0;
}