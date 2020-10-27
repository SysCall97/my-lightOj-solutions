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
const int mx = 1e5 + 10;
ll arr[mx], tree[4*mx+10];

void build(ll node, ll b, ll e) {
    if(b==e) {
        tree[node] = arr[b];
        return;
    }
    ll mid = (b+e)/2;
    ll left = 2*node+1;
    ll right = left+1;
    build(left, b, mid);
    build(right, mid+1, e);
    tree[node] = tree[left] + tree[right];
}

void update(ll node, ll b, ll e, ll pos, ll val) {
    if(b>e || b>pos || e<pos) return;
    else if(b==e && b==pos) {tree[node] += val; return;}
    ll mid = (b+e)/2;
    ll left = 2*node+1;
    ll right = left+1;
    update(left, b, mid, pos, val);
    update(right, mid+1, e, pos, val);
    tree[node] = tree[left] + tree[right];
}

ll query(ll node, ll begin, ll end, ll b, ll e) {
    if(begin>end || begin>e || end<b) return 0;
    else if(b<=begin && e>=end) return tree[node];
    ll mid = (begin+end)/2;
    ll left = 2*node+1;
    ll right = left+1;
    return query(left, begin, mid, b, e) + query(right, mid+1, end, b, e);
}

int main() {
    ll t;
    scanf("%lld", &t);
    for(ll c=1; c<=t; ++c) {
        mem(arr, 0);
        mem(tree, 0);
        ll n, m, k, a, b;
        scanf("%lld%lld", &n, &m);
        for(ll i=0; i<n; ++i) scanf("%lld", &arr[i]);
        build(0, 0, n-1);
        printf("Case %lld:\n", c);
        for(ll i=0; i<m; ++i) {
            scanf("%lld", &k);
            if(k==1) {
                scanf("%lld", &a);
                ll ans = query(0, 0, n-1, a, a);
                printf("%lld\n", ans);
                update(0, 0, n-1, a, -ans);
            } else {
                scanf("%lld%lld", &a, &b);
                if(k==2) update(0, 0, n-1, a, b);
                else printf("%lld\n", query(0, 0, n-1, a, b));
            }
        }

    }

    return 0;
}

