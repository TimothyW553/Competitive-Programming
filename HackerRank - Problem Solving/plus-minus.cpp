#include <bits/stdc++.h>
using namespace std;

int pos = 0, neg = 0, zero = 0;
int main() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        if(a > 0) pos++;
        else if(a < 0) neg++;
        else if(a == 0) zero++;
    }
    printf("%.6f\n", ((double)pos/n));
    printf("%.6f\n", ((double)neg/n));
    printf("%.6f\n", ((double)zero/n));
}