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

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
ll fpow(ll b, ll exp, ll mod) { if (exp == 0) return 1; ll t = fpow(b, exp / 2, mod); if (exp & 1) return t * t % mod * b % mod; return t * t % mod; }
ll divmod(ll i, ll j, ll mod) { i %= mod, j %= mod; return i * fpow(j, mod - 2, mod) % mod; }
/*
bool isLeapYear(int year) {
    if(year % 4 == 0) {
        if(year % 100 == 0) {
            if(year % 400 == 0) { return true; }
            else { return false; }
        } else { return true; }
    } else { return false; }
}
*/

#define n 4
int count = 0;

bool check(int board[n][n], int row, int col) {
    for (int i = 0; i < 8; i++) {
        if (board[col][i]) { return false; }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) { return false; }
    }
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j]) { return false; }
    }
    return true;
}

bool queenSolve(int board[n][n], int col) { // solve by each column
    if (col >= n) { return true; }
    for (int i = 0; i < n; i++) {
        if (check(board, i, col)) {
            board[i][col] = 1;
            if (queenSolve(board, col + 1)) { return true; }
            board[i][col] = 0;
        }
    }
    return false;
}

bool solve() {
    int board[n][n] = {{0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0}};
    if (queenSolve(board, 0) == false) {
        cout << "no solution";
        return false;
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
