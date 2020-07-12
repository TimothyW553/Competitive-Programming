#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    while(N--) {
        int num; cin >> num;
        if(num == 0) {
            cout << "0000" << "\n";
            continue;
        }
        string bin = "";
        while(num != 0) {
            bin = to_string(num % 2) + bin;
            num /= 2;
        }
        int len = bin.length();
        if(bin.length() % 4 != 0) {
            for(int i = 0; i < 4-(len%4); i++) {
                bin = "0" + bin;
            }
        }
        for(int i = 0; i < bin.length(); i++) {
            if(i % 4 == 0 and i > 0) {
                cout << " ";
            }
            cout << bin[i];
        }
        cout << "\n";
    }
    return 0;
}
