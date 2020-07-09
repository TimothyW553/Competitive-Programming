#include <bits/stdc++.h>
using namespace std;

int N, K;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> K;
    int swords = 0, count = 0;
    while(N > 0) {
        N--; // use a bar to make a sword
        swords++; // update number of swords by 1 (used a bar)
        count++; // upd counter by 1 (# of swords created)
        if(swords == K) { // we can sell all the swords if swords == K for a bar
            N++; // number of bar thus increases
            swords = 0; // no more swords left because we sold of all them
        }
    }
    cout << count << "\n";
    return 0;
}