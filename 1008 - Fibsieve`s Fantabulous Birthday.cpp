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
typedef unsigned long long ll;
typedef pair<ll, ll> PI;

ll fsqrt(ll n) {
    ll hi=n, lo=0, mid;
    while(1) {
        mid=(lo+hi)/2;
        if(mid*mid==n || (mid*mid<n && (mid+1)*(mid+1)>n)) return mid;
        else if(mid*mid<n) lo=mid+1;
        else hi=mid-1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    for(ll Case=1; Case<=t; ++Case) {
        ll n;
        cin>>n;
//        if(n==1) cout<<"Case "<<Case<<": "<<1<<" "<<1<<el;
        ll sq=fsqrt(n);
        if(sq*sq==n) {
            if(n&1) cout<<"Case "<<Case<<": "<<1<<" "<<sq<<el;
            else cout<<"Case "<<Case<<": "<<sq<<" "<<1<<el;
        } else {
            ++sq;
            ll x=1, y=sq, mid=(sq*sq)-sq+1;
            if(n<=mid) x=sq;
            else x+=(sq*sq)-n;
            if(n<mid) y=n-(sq-1)*(sq-1);
            if(sq&1) cout<<"Case "<<Case<<": "<<x<<" "<<y<<el;
            else cout<<"Case "<<Case<<": "<<y<<" "<<x<<el;
        }
    }

    return 0;
}
