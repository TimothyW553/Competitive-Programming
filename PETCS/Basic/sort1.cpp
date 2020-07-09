#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N;
    int m;
    for(int i = 0; i < N; i++) {
        cin >> m;
        v.push_back(m);
    }
    for(auto &x : v) {
        cout << x << " ";
    }
    cout << "\n";
    for(int i = 0; i < N-1; i++) {
        for(int j = 0; j < N-1; j++) {
            if(v[j] > v[j+1]) {
                swap(v[j], v[j+1]);
                for(auto &x : v) {
                    cout << x << " ";
                }
                cout << "\n";
            }
        }
    }
    return 0;
}
