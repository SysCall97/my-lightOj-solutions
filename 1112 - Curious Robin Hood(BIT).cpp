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
ll arr[mx], tree[mx+5];

ll getParent(ll index) {
    return index - (index & -index);
}

ll getNext(ll index) {
    return index + (index & -index);
}

void update(ll val, ll indx, ll len) {
    indx += 1;
    while(indx<=len) {
        tree[indx] += val;
        indx = getNext(indx);
    }
}

void build(ll n) {
    for(ll i=0; i<n; ++i) update(arr[i], i, n);
}

ll query(ll indx) {
    indx += 1;
    int sum = 0;
    while(indx>0) {
        sum += tree[indx];
        indx = getParent(indx);
    }
    return sum;
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
        build(n);
        printf("Case %lld:\n", c);
        for(ll i=0; i<m; ++i) {
            scanf("%lld", &k);
            if(k==1) {
                scanf("%lld", &a);
                ll ans = query(a) - query(a-1);
                printf("%lld\n", ans);
                update(-ans, a, n);
            } else {
                scanf("%lld%lld", &a, &b);
                if(k==2) update(b, a, n);
                else printf("%lld\n", query(b)-query(a-1));
            }
        }

    }

    return 0;
}

