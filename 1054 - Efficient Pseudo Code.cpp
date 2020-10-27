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
#define Max 100005
#define ll unsigned long long
using namespace std;
typedef pair<ll, ll> PI;
ll MOD=1000000007;
bool table[Max]= {0};
ll prime[Max/10];
void sieve() {
    ll i,j,k=4,n=Max;
    for(i=5; i<=n; i+=k) {
        for(j=2*i; j<=n; j+=i) {
            table[j]=1;
        }
        if(k==2) k=4;
        else k=2;
    }
    k=4;
    for(i=5,j=2; i<=n; i+=k) {
        if(table[i]==0) {
            prime[j]=i;
            j++;
        }
        if(k==2) k=4;
        else k=2;
    }
    prime[0]=2,prime[1]=3;
}

ll bigMod(ll n, ll p) {
    if(p==0) return 1;
    if(p%2) return ((n%MOD)*bigMod(n,p-1))%MOD;
    else {
        ll ans = (bigMod(n,p/2)%MOD);
        return (ans*ans)%MOD;
    }
}

ll modularInverse(ll n) {
    ll x, y;
    ll gcd= __gcd(n, MOD);
    if(gcd==1) return bigMod(n, MOD-2);
}

ll S(ll n, ll p) {
    ll u=(bigMod(n, p+1)-1)%MOD;
    ll l=modularInverse(n-1)%MOD;
    return (u*l)%MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    ll t;
    cin>>t;
    for(ll Case=1; Case<=t; ++Case) {
        ll n, m;
        cin>>n>>m;
        ll ans=1;
        for(ll i=0; prime[i]*prime[i]<=n; ++i) if(n%prime[i]==0) {
                ll cnt=0;
                while(n%prime[i]==0) {
                    ++cnt;
                    n/=prime[i];
                }
                ans=(ans*S(prime[i], cnt*m))%MOD;
            }
        if(n>1) {
            if(n%MOD==0) ans=1;
            else ans=(ans*S(n, m))%MOD;
        }

        cout<<"Case "<<Case<<": "<<ans<<el;
    }

    return 0;
}
