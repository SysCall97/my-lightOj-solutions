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

const int mx = 2 * (1e5) + 5;
ll type[mx], height[mx], seg[4*mx];

void build(ll node, ll f, ll l) {
    if(f==l) {
        seg[node] = height[f];
        return;
    }
    ll mid = (f+l)/2;
    ll left = 2*node+1;
    ll right = left+1;
    build(left, f, mid);
    build(right, mid+1, l);
    seg[node] = max(seg[left], seg[right]);
}

ll findMax(ll node, ll first, ll last, ll f, ll l) {
    if(first>last || first>l || last<f) return INT_MIN;
    else if(f<=first && l>=last) return seg[node];
    ll mid = (first+last)/2;
    ll left = 2*node+1;
    ll right = left+1;
    return max(findMax(left, first, mid, f, l), findMax(right, mid+1, last, f, l));
}

int main() {
    ll t;
    scanf("%lld", &t);
    for(ll c=1; c<=t; ++c) {
        ll n;
        scanf("%lld", &n);
        for(ll i=1; i<=n; ++i) scanf("%lld%lld", &type[i], &height[i]);

        build(0, 1, n);
        map<ll, ll> cnt;
        ll s=1, ans=0;
        for(ll i=1; i<=n; ++i) {
            ++cnt[type[i]];
            if(cnt[type[i]]==2) {
                ans += findMax(0, 1, n, s, i-1);
                cnt.clear();
                ++cnt[type[i]];
                s=i;
            }
        }

        ans += findMax(0, 1, n, s, n);
        printf("Case %lld: %lld\n", c, ans);
    }

    return 0;
}
