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

const int sz = 1e5;
ll seg[4*sz];
ll mod = 1000000007;

void update(ll node, ll start, ll end, ll s, ll e, ll val) {
    if(start>end || start>e || end<s) return;
    else if(start>=s && end<=e) {
        seg[node] = (seg[node]+val)%mod;
        return;
    }

    ll mid   = (start+end)/2;
    ll left  = 2*node+1;
    ll right = left+1;

    update(left, start, mid, s, e, val);
    update(right, mid+1, end, s, e, val);

    seg[node] = (seg[left] + seg[right]) % mod;
}

ll query(ll node, ll start, ll end, ll s, ll e) {
    if(start>end || start>e || end<s) return 0;
    else if(start>=s && end<=e) return seg[node];

    ll mid   = (start+end)/2;
    ll left  = 2*node+1;
    ll right = left+1;

    return (query(left, start, mid, s, e) +
            query(right, mid+1, end, s, e))%mod;
}

bool comp(PI p1, PI p2) {
    if(p1.first<p2.first) return true;
    else if(p1.first==p2.first && p1.second>p2.second) return true;
    else return false;
}

int main() {
    ll t, root=0;
    scanf("%lld", &t);
    for(ll c=1; c<=t; ++c) {
        ll n, m;
        scanf("%lld", &n);
        vector<PI> v(n);
        for(ll i=0; i<n; ++i) {
            scanf("%lld", &m);
            v[i] = {m, i+1};
        }

        sort(all(v), comp);
        mem(seg, 0);

        for(ll i=0; i<n; ++i) {
            ll indx = v[i].second;
            ll node = 0, start = 0, end = n, s = 0, e = indx-1;
            ll val  = query(node, start, end, s, e) + 1;
            s=e=indx;
            update(node, start, end, s, e, val);
        }

        printf("Case %lld: %lld\n", c, seg[root]);

    }
    return 0;
}
