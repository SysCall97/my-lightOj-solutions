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
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PI;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t; cin>>t;
    for(ll Case=1; Case<=t; ++Case) {
        ll n; cin>>n;
        ll m=n, nod=(ll)(log10(n)/log10(2)), j=nod, sz=0;
        vector<ll> digits;
        bool b=0;
        while(n) {
            digits.pb(n%2);
            n/=2, ++sz;
        }
        digits.pb(0);
        ++sz;
        ll increase=0, decrease=0;
        for(ll i=0; i<sz-1; ++i) if(digits[i]==1 && digits[i+1]==0) {
            digits[i]=0, digits[i+1]=1;
            increase=(1<<i);
            for(ll j=0; j<i; ++j) {
                ll k=j;
                while(k>=0 && digits[k]==0 && digits[k+1]==1) {
                    digits[k]=1;
                    digits[k+1]=0;
                    decrease+=((1<<(k+1))-(1<<k));
                    if(decrease>=increase) {decrease-=((1<<(k+1))-(1<<k)); break;}
                    --k;
                }
            }
            break;
        }
        j=1;
        ll ans=0;
        for(ll i=0; i<sz; ++i) {ans+=(j*digits[i]); j<<=1;}
        cout<<"Case "<<Case<<": "<<ans<<el;
    }
    return 0;
}
