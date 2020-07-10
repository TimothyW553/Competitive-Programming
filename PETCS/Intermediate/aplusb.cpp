#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    int a, b;
    for(int i = 0; i < N; i++) {
        cin >> a >> b;
        cout << a+b << "\n";
    }
    return 0;
}
