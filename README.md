# Competitive Programming

Compilation of all the programs for practice and contests

Under the contest package, you will find my Java solutions to various programming contests and practice problems. The solutions are oganized by the name of the contest

Problems sets are organized into different folders

## Note: This is only for help if you are stuck.

  - Canadian Computing Competition - Junior
  - Canadian Computing Competition - Senior
  - HackerRank - Problem Solving
  - CS Academy
  - USACO
  - T-414-ÁFLV

## Profile Links
  - [HackerRank](www.hackerrank.com/TimothyW553)
  - [DMOJ](https://dmoj.ca/user/timothyw553)
  - [CS Academy](https://csacademy.com/user/TimothyW553)

## Competitive Templates:
### C++
```C
#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    return 0;
}
```
### Java
```Java
import java.util.*;
import java.io.*;

public class Main {
    
    static BufferedReader br;
    static PrintWriter out;
    static StringTokenizer st;
    
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(new OutputStreamWriter(System.out));
   
    }
    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
        st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }

    static long readLong () throws IOException {
        return Long.parseLong(next());
    }

    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }

    static double readDouble () throws IOException {
        return Double.parseDouble(next());
    }

    static char readCharacter () throws IOException {
        return next().charAt(0);
    }

    static String readLine () throws IOException {
        return br.readLine().trim();
    }
}
```
### C
```C
#define _GNU_SOURCE
#include <stdio.h>

#define getchar() (*_pbuf ? *_pbuf++ : (_buf[fread_unlocked(_pbuf = _buf, 1, 65536, stdin)] = 0, *_pbuf++))
char _buf[65537], *_pbuf = _buf;

int readint() {
	int n = 0, c, o = 0;
	while ((c = getchar()) < '0') n |= c == '-';
	do o = (o << 3) + (o << 1) + c - '0';
	while ((c = getchar()) >= '0');
	return n ? -o : o;
}
int main(void) {
}
```
