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

const int mx = (1e5) + 10;
ll arr[mx], mxArr[4*mx], mnArr[4*mx];

void build(ll node, ll f, ll l) {
    if(f==l) {
        mxArr[node] = arr[f];
        mnArr[node] = arr[f];
        return;
    }
    ll mid = (f+l)/2;
    ll left = 2*node+1;
    ll right = left+1;
    build(left, f, mid);
    build(right, mid+1, l);
    mxArr[node] = max(mxArr[left], mxArr[right]);
    mnArr[node] = min(mnArr[left], mnArr[right]);
}

ll findMax(ll node, ll first, ll last, ll f, ll l) {
    if(first>last || first>l || last<f) return -1;
    else if(first>=f && last<=l) return mxArr[node];
    ll mid = (first+last)/2;
    ll left = 2*node+1;
    ll right = left+1;
    return max(findMax(left, first, mid, f, l), findMax(right, mid+1, last, f, l));
}

ll findMin(ll node, ll first, ll last, ll f, ll l) {
    if(first>last || first>l || last<f) return INT_MAX;
    else if(first>=f && last<=l) return mnArr[node];
    ll mid = (first+last)/2;
    ll left = 2*node+1;
    ll right = left+1;
    return min(findMin(left, first, mid, f, l), findMin(right, mid+1, last, f, l));
}

int main() {
    ll t;
    scanf("%lld", &t);
    for(ll c=1; c<=t; ++c) {
        ll n, d;
        scanf("%lld%lld", &n, &d);

        mem(arr, 0);
        for(ll i=1; i<=n; ++i) scanf("%lld", &arr[i]);

        build(0, 1, n);

        ll ans = findMax(0, 1, n, 1, d)-findMin(0, 1, n, 1, d);

        for(ll i=d+1, j=2; i<=n; ++i, ++j)
            ans = max(ans, findMax(0, 1, n, j, i)-findMin(0, 1, n, j, i));

        printf("Case %lld: %lld\n", c, ans);
    }
    return 0;
}

