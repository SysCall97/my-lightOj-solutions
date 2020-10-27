/***************************************************************
 *    Name:  KAZI NUR  ALAM MASHRY                             *
 *  School:  MAWLANA BHASHANI SCIENCE & TECHNOLOGY UNIVERSITY  *
 *           CSE (14TH BATCH)                                  *
 ***************************************************************/
#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define el '\n'
#define x first
#define y second
#define pi acos(-1.0)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define mem(x,y) memset(x , y , sizeof(x))
using namespace std;
typedef unsigned long long ll;
typedef pair<ll, ll> PI;
ll maxi=1000010, mod=1000003;

ll bigMod(ll n, ll p)
{
    if(p==0) return 1;
    if(p%2) return (n * bigMod(n,p-1)) % mod;
    else {
        ll ans = bigMod(n, p/2) % mod;
        return (ans * ans) % mod;
    }
}

int main() {
    vector<ll> fact(maxi);
    fact[0]=1;
    for(ll i=1; i<maxi; ++i) fact[i]=(fact[i-1]*(i%mod))%mod;
    ll t, n, m; cin>>t;
    for(ll Case=1; Case<=t; ++Case) {
        cin>>n>>m;
        ll g = (fact[m]*fact[n-m]) % mod;
        cout<<"Case "<<Case<<": "<<(fact[n]*bigMod(g, mod-2))%mod<<el;
    }
    return 0;
}
