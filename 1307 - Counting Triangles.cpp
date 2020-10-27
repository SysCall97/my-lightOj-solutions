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
    ll t;
    cin>>t;
    for(ll Case = 1; Case<=t; ++Case) {
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(ll i=0; i<n; ++i) cin>>v[i];
        sort(all(v));
        ll ans = 0;

//        for(auto i: v) cout<<i<<" ";
//        cout<<el;

        for(ll i=0; i<n; ++i) {
            for(ll j=i+1; j<n; ++j) {
                ll sz = v[i] + v[j];
                ll index = upper_bound(all(v), sz) - v.begin();
                if(sz == v[index-1]) --index;
                ans += (index-j-1);
//                cout<<i<<" "<<j<<" "<<index<<" ans: "<<ans<<el;
            }
        }
        cout<<"Case "<<Case<<": "<<ans<<el;
    }

    return 0;
}

