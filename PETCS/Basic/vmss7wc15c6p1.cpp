#include <bits/stdc++.h>
using namespace std;

int arr[256], brr[256];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    string a, b; getline(cin, a);
                 getline(cin, b);
    for(int i = 0; i < a.size(); i++) {
        if(a[i] != ' ') {
            arr[tolower(a[i])]++;
        }
    }
    for(int i = 0; i < b.size(); i++) {
        if(b[i] != ' ') {
            brr[tolower(b[i])]++;
        }
    }
    for(int i = 0; i < 256; i++) {
        if(arr[i] != brr[i]) {
            return cout << "no" << "\n", 0;
        }
    }
    cout << "yes" << "\n";
    return 0;
}
