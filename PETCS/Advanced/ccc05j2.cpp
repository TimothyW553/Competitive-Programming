#include <bits/stdc++.h>
using namespace std;
int A, B, cnt = 0;
int numdivs(int n) {
    int cnts = 0;
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            cnts++;
        }
    }
    return cnts;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    scanf("%d %d", &A, &B);
    for(int i = A; i <= B; i++) {
        if(numdivs(i) == 4) {
            cnt++;
        }
    }
    printf("The number of RSA numbers between %d and %d is %d\n", A, B, cnt);
    return 0;
}
