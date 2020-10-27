/***************************************************************
 *    Name:  KAZI NUR  ALAM MASHRY                             *
 *  School:  MAWLANA BHASHANI SCIENCE & TECHNOLOGY UNIVERSITY  *
 *           CSE (14TH BATCH)                                  *
 ***************************************************************/
#include<bits/stdc++.h>
#define INF           0x3f3f3f3f
#define el            '\n'
#define x             first
#define y             second
#define pi            acos(-1.0)
#define pb            push_back
#define mp            make_pair
#define all(v)        v.begin(), v.end()
#define allr(v)       v.rbegin(), v.rend()
#define mem(x,y)      memset(x , y , sizeof(x))
#define Max           10100
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PI;
bool table[Max]= {0};
int prime[Max/5];
void sieve() {
    int i,j,k=4,n=Max;
    for(i=5; i*i<=n; i+=k) {
        for(j=2*i; j<=n; j+=i) {
            table[j]=1;
        }
        k=(k==2)?4:2;
    }
    k=4;
    for(i=5,j=2; i<=n; i+=k) {
        if(table[i]==0) {
            prime[j]=i;
            j++;
        }
        k=(k==2)?4:2;
    }
    prime[0]=2,prime[1]=3;
}

void mul(string& a,ll b) {
    ll carry = 0, len = a.size();
    for(ll i=0; i<len; i++) {
        carry += (a[i]-'0')*b;
        a[i] = (carry%10)+'0';
        carry /= 10;
    }
    while(carry) {
        a += (carry%10)+'0';
        carry /= 10;
    }
}
int main() {
    sieve();
    ll t;
    cin>>t;
    for(ll Case=1; Case<=t; ++Case) {
        ll n;
        cin>>n;
        ll arr[10100]= {0}, m;
        vector<ll> v;
        for(ll i=0; i<n; ++i) {
            cin>>m;
            for(ll j=0; prime[j]*prime[j]<=m; ++j) if(m%prime[j]==0) {
                    ll cnt=0;
                    while(m%prime[j]==0) m/=prime[j], ++cnt;
                    if(arr[prime[j]]==0) v.pb(prime[j]);
                    arr[prime[j]]=max(arr[prime[j]], cnt);
                }
            if(m>1) {
                if(arr[m]==0) v.pb(m);
                arr[m]=max(arr[m], (ll)1);
            }
        }
        string ans="1";
        ll sz=v.size();
        for(ll i=0; i<sz; ++i) {
            ll nmbr=pow(v[i], arr[v[i]]);
            mul(ans, nmbr);
        }
        reverse(all(ans));
        cout<<"Case "<<Case<<": "<<ans<<el;
    }
    return 0;
}
