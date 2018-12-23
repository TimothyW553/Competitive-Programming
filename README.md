# Competitive Programming

Compilation of all the programs for practice and contests

Under the contest package, you will find my Java solutions to various programming contests and practice problems. The solutions are oganized by the name of the contest

Problems sets are organized into different folders

## Note: This is only for help if you are stuck. I am not doing this to boost my ego, unlike other people who upload their solutions on GITHUB

  > Canadian Computing Competition - Junior
  - `Junior #1` ✔
  - `Junior #2` ✔
  - `Junior #3` ✔
  - `Junior #4` ✔
  - `Junior #5`
  
  > Canadian Computing Competition - Senior
  
  > HackerRank - Problem Solving
  

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

#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;

int __attribute__((optimize("-O3"))) main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
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
