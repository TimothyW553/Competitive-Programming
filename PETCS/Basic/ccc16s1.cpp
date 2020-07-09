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
    string a, b; cin >> a >> b;
    for(int i = 0; i < a.size(); i++) {
        arr[a[i]]++;
    }
    for(int i = 0; i < b.size(); i++) {
        brr[b[i]]++;
    }
    int count = 0;
    for(int i = 0; i < 256; i++) {
        if(i != int('*')) {
            if(arr[i] != brr[i]) {
                count += abs(arr[i]-brr[i]);
            }
        }
    }
    if(count == brr[int('*')]) {
        cout << "A" << "\n";
    } else {
        cout << "N" << "\n";
    }
    return 0;
}
