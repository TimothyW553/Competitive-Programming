#include <bits/stdc++.h>
using namespace std;
int P, G, R, O, amt, cnt = 0, min_val = INT_MAX;
int main() {
    scanf("%d %d %d %d %d", &P, &G, &R, &O, &amt);
    for(int p = 0; p <= amt; p++) {
        for(int g = 0; g <= amt; g++) {
            for(int r = 0; r <= amt; r++) {
                for(int o = 0; o <= amt; o++) {
                    if(p*P + g*G + r*R + o*O == amt) {
                        printf("# of PINK is %d # of GREEN is %d # of RED is %d # of ORANGE is %d\n", p, g, r, o);
                        cnt++; min_val = min(min_val, p+g+r+o);
                    }
                }
            }
        }
    }
    printf("Total combinations is %d.\n", cnt);
    printf("Minimum number of tickets to print is %d.\n", min_val);
    return 0;
}
