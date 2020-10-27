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

const int mx = (1e5)+52000;

ll arr[mx], a[mx], seg[4*mx];

void initiate(ll node, ll first, ll last) {
    if(first==last) {
        seg[node] = 1;
        return;
    }

    ll mid   = (first+last)/2;
    ll left  = 2*node+1;
    ll right = left+1;

    initiate(left, first, mid);
    initiate(right, mid+1, last);

    seg[node] = seg[left] + seg[right];
}

void update(ll node, ll first, ll last, ll f, ll l, ll val) {
    if(first>last || first>l || last<f) return;
    else if(first>=f && last<=l) {
        seg[node] = val;
        return;
    }

    ll mid   = (first+last)/2;
    ll left  = 2*node+1;
    ll right = left+1;

    update(left, first, mid, f, l, val);
    update(right, mid+1, last, f, l, val);

    seg[node] = seg[left] + seg[right];
}

ll query(ll node, ll first, ll last, ll f, ll l) {
    if(first>last || first>l || last<f) return 0;
    else if(first>=f && last<=l) return seg[node];

    ll mid   = (first+last)/2;
    ll left  = 2*node+1;
    ll right = left+1;

    return query(left, first, mid, f, l) +
           query(right, mid+1, last, f, l);
}

int main() {
    ll t;
    scanf("%lld", &t);
    for(ll c=1; c<=t; ++c) {
        ll n, m, pos;
        scanf("%lld%lld", &n, &m);
        mem(arr, 0);
        mem(seg, 0);
        for(ll i=1; i<=n; ++i) {
            scanf("%lld", &a[i]);
            arr[i] = 1;
        }
        initiate(0, 1, mx);
        printf("Case %lld:\n", c);
        while(m--) {
            char ch = getchar();
            scanf("%c%lld", &ch, &pos);

            if(ch=='a') {
                ++n;
                a[n] = pos;
                arr[n] = 1;
                update(0, 1, mx, n, n, 1);
            } else if(ch=='c') {
                ll lo=1, hi=mx, mid, ans=0, k=30;
                while(k--) {
                    mid = (lo+hi)/2;
                    ll j = query(0, 1, mx, 1, mid);
                    if(j>=pos) {
                        ans = mid;
                        hi  = mid-1;
                    } else if(j<pos) lo = mid+1;
                }

                update(0, 1, mx, ans, ans, 0);
                if(ans && ans<=n) printf("%lld\n", a[ans]);
                else puts("none");
            }
        }
    }

    return 0;
}
