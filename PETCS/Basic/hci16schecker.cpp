#include <bits/stdc++.h>
using namespace std;

int N;
map<string, int> mp;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N;
    for(int i = 0; i < N; i++) {
        string s; cin >> s;
        mp[s]++;
    }
    string word;
    while(cin >> word) {
        if(mp[word] == 0) {
            return cout << "Incorrect" << "\n", 0;
        }
    }
    cout << "Correct" << "\n";
    return 0;
}
