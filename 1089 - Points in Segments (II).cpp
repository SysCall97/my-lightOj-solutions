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

const int mx = (1e6)+10;

map<ll, ll> comp;
vector<PI> pv;
vector<ll> sorted, v;
ll seg[4*mx];

void initiate() {
    comp.clear();
    pv.clear();
    sorted.clear();
    v.clear();
    mem(seg, 0);
}

void update(ll node, ll first, ll last, ll f, ll l) {
    ll mid   = (first+last)/2;
    ll left  = 2*node+1;
    ll right = left+1;

    if(first<last) {
        seg[left] += seg[node];
        seg[right] += seg[node];
        seg[node]=0;
    }
    if(first>last || first>l || last<f) return;
    else if(f<=first && l>=last) {
        seg[node] += 1;
        return;
    }

    update(left, first, mid, f, l);
    update(right, mid+1, last, f, l);
}

ll query(ll node, ll first, ll last, ll f, ll l) {
    ll mid   = (first+last)/2;
    ll left  = 2*node+1;
    ll right = left+1;

    if(first<last) {
        seg[left] += seg[node];
        seg[right] += seg[node];
        seg[node]=0;
    }
    if(first>last || first>l || last<f) return 0;
    else if(f<=first && l>=last) return seg[node];

    return query(left, first, mid, f, l) + query(right, mid+1, last, f, l);
}

int main() {
    ll t;
    scanf("%lld", &t);
    for(ll c=1; c<=t; ++c) {
        ll n, m, cnt = 1, a, b;
        initiate();
        scanf("%lld%lld", &n, &m);
        for(ll i=0; i<n; ++i) {
            scanf("%lld%lld", &a, &b);
            if(comp[a]==0) sorted.pb(a);
            if(comp[b]==0) sorted.pb(b);
            comp[a]=1;
            comp[b]=1;
            pv.pb({a, b});
        }


        sort(all(sorted));
        ll sz=sorted.size();

        v.pb(-1);
        for(ll i=0; i<sz; ++i) {
            comp[sorted[i]] = cnt;
            v.pb(-1);
            v.pb(-1);
            cnt+=2;
        }

        for(ll i=0; i<n; ++i) {
            a = comp[pv[i].first], b = comp[pv[i].second];
            update(0, 1, cnt, a, b);
        }

        printf("Case %lld:\n", c);
        for(ll i=0; i<m; ++i) {
            scanf("%lld", &a);
            if(a>=sorted[0] && a<=sorted[sz-1]) {
                ll pos = upper_bound(all(sorted), a)-sorted.begin();
                if(sorted[pos-1]==a) pos = 2*pos-1;
                else pos = 2*pos;
                if(v[pos]==-1) v[pos] = query(0, 1, cnt, pos, pos);
                printf("%lld\n", v[pos]);
            } else printf("0\n");
        }
    }
    return 0;
}
