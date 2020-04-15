#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))
#define all(x) (x).begin(), (x).end()

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
ll mul(ll a,ll b, ll M){if(b==0)return 0;ll t=mul(a,b/2,M);if(b&1)return (t+t+a)%M;return (t+t)%M;}
ll fpow(ll a, ll b, ll M){if(b==0)return 1;ll t=fpow(a,b/2,M);if(b&1)return mul(mul(t,t,M),a,M)%M;return mul(t,t,M)%M;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

class Person {
private:
    string firstName;
    string lastName;
    int id;
public:
    Person(string firstName, string lastName, int identification) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->id = identification;
    }
    void printPerson() {
        cout << "Name: " << lastName << ", " << firstName <<"\nID: " << id << "\n"; 
    }
};

class Student : public Person {
private:
    vector<int> testScores;
public:
    Student(string firstName, string lastName, int identification, vector<int> testScores) : Person(firstName, lastName, identification), testScores(testScores) {

    }
    string calculate() {
        double avg = 0.0;
        string ans = "";
        for(auto &x : testScores) {
            avg += x;
        }
        avg /= testScores.size();
        if(avg >= 90 and avg <= 100) {
            ans = "O";
        } else if(avg >= 80 and avg < 90) {
            ans = "E";
        } else if(avg >= 70 and avg < 80) {
            ans = "A";
        } else if(avg >= 55 and avg < 70) {
            ans = "P";
        } else if(avg >= 40 and avg < 55) {
            ans = "D";
        } else if(avg < 40) {
            ans = "T";
        }
        return ans;
    }
};

int __attribute__((optimize("-O3"))) main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    string firstName; string lastName;
    int id, numScores;
    cin >> firstName >> lastName >> id >> numScores;
    vector<int> scores;
    for(int i = 0; i < numScores; i++) {
        int tmpScore; cin >> tmpScore;
        scores.pb(tmpScore);
    }
    Student* s = new Student(firstName, lastName, id, scores);
    s->printPerson();
    cout << "Grade: " << s->calculate() << "\n";
    return 0;
}
