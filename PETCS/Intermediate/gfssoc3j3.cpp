#include <bits/stdc++.h>
using namespace std;
const int MAX = 25;
int P, T;
pair<double, string> presents[MAX];
pair<int, string> teachers[MAX];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> P >> T; cin.ignore();
    for(int i = 0; i < P; i++) {
        string s; getline(cin, s);
        double price; cin >> price; cin.ignore();
        presents[i] = {price, s};
    }
    for(int i = 0; i < T; i++) {
        string s; getline(cin, s);
        int mark; cin >> mark; cin.ignore();
        teachers[i] = {mark, s};
    }
    sort(presents, presents+P);
    sort(teachers, teachers+T);
    for(int i = 0; i < T; i++) {
        cout << teachers[i].second << " will get a " << presents[i].second << "\n";
    }
    return 0;
}
