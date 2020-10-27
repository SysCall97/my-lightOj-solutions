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
vector<ll> v, powOfFive;

void f() {
    ll n = 1, m, index, i=0;
    while(n<=100000000) {
        powOfFive.pb(n);
        n *= 5;
        ++i;
    }
    n = 1, m = 5, index = 0;
    while(n<=100000000) {
        v.pb(n);
        m += 5;
        if(index<i && m==powOfFive[index]) n+=(++index);
        else ++n;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    f();

    for(ll Case = 1; Case<=t; ++Case) {
        ll n;
        cin>>n;
        ll index = upper_bound(all(v), n)-v.begin();
        cout<<"Case "<<Case<<": ";
        if(v[index-1]==n) cout<<5*index<<el;
        else cout<<"impossible\n";
    }
    return 0;
}
