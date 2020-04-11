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
ll mul(ll a,ll b, ll M){if(b==0)return 0;ll t=mul(a,b/2,M);if(b&1)return (t+t+a)%M;return (t+t)%M;}
ll fpow(ll a, ll b, ll M){if(b==0)return 1;ll t=fpow(a,b/2,M);if(b&1)return mul(mul(t,t,M),a,M)%M;return mul(t,t,M)%M;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

int __attribute__((optimize("-O3"))) main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    int n, q; cin >> n >> q;
    cin.ignore();
    map<string, string> attributeDB; // to store attribute-value pairs
    string inputstr,tag_preamble = "";
    // get each HRML line
    for (int i = 0; i < n; i++) {
        getline(cin,inputstr);    
        // for each HRML line, break it up into token words
        stringstream ss(inputstr);
        string word, attribute, value;
        size_t pos;
        while(getline(ss, word, ' ')) { // for each token word
            // tag detected -> adjust tag_preamble by +/- tag
            if(word[0] == '<') {
                string tag;
                if (word[1] == '/') { // it's tag closing
                    tag = word.substr(2);   
                    tag = tag.substr(0,tag.length()-1); // rid of ">"
                    pos = tag_preamble.find("."+tag);
                    if(pos == string::npos) {
                        tag_preamble = "";
                    } else {
                        tag_preamble=tag_preamble.substr(0,pos);
                    }
                }
                else { // it's tag opening
                    tag = word.substr(1);
                    if(tag.find(">") != string::npos) {
                        tag = tag.substr(0,tag.length()-1); // rid of ">"
                    }
                    if(tag_preamble == "") {
                        tag_preamble = tag;
                    } else {
                        tag_preamble = tag_preamble + "." + tag;
                    }
                }
            }
            // value detected
            else if(word[0] == '"') {
                pos = word.find_last_of('"');
                value = word.substr(1,pos-1);
                attributeDB[attribute] = value; // insert into DB
            }
            // attribute name detected
            else if(word[0] != '=') {
                attribute = tag_preamble + "~" + word;  
            }
        }
    }

    // now we process the queries
    for (int i = 0; i < q; i++) {
        getline(cin, inputstr); 
        if (attributeDB.find(inputstr) == attributeDB.end()) {
            cout << "Not Found!" << "\n";
        } else {
            cout << attributeDB[inputstr] << "\n";
        }
    }
    return 0;
}
