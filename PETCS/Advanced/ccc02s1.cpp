#include <bits/stdc++.h>
using namespace std;
int P, G, R, O, S, cnt = 0, min_val = 9999;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    scanf("%d %d %d %d %d", &P, &G, &R, &O, &S);
    for(int p = 0; p <= S; p++) {
        for(int g = 0; g <= S; g++) {
            for(int r = 0; r <= S; r++) {
                for(int o = 0; o <= S; o++) {
                    if(p*P + g*G + r*R + o*O == S) {
                        cnt++;
                        printf("# of PINK is %d # of GREEN is %d # of RED is %d # of ORANGE is %d\n", p, g, r, o);
                        min_val = min(min_val, p+g+r+o);
                    }
                }
            }
        }
    }
    printf("Total combinations is %d.\n", cnt);
    printf("Minimum number of tickets to print is %d.\n", min_val);
    return 0;
}
