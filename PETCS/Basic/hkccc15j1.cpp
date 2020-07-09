#include <bits/stdc++.h>
using namespace std;

int N;
string a[105], b[105];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> b[i];
    }
    int alice = 0, bob = 0;
    for(int i = 0; i < N; i++) {
        if(a[i] == b[i]) {
            continue;
        }
        if(a[i] == "rock" and b[i] == "scissors" or
           a[i] == "scissors" and b[i] == "paper" or 
           a[i] == "paper" and b[i] == "rock") {
            alice++;
            continue;
        }
        bob++;
    }
    cout << alice << " " << bob << "\n";
    return 0;
}
