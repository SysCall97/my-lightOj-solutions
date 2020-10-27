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
const int mx=1e5;
ll segTree[4*mx+10], arr[mx+10];

void build(ll node, ll b, ll e) {
    if(b==e) {
        segTree[node] = arr[b];
        return;
    }
    ll left = (node<<1)+1, right = left+1, mid = (b+e)/2;
    build(left, b, mid);
    build(right, mid+1, e);
    segTree[node] = min(segTree[left], segTree[right]);
}

ll query(ll startRange, ll endRange, ll node, ll b, ll e) {
    if(startRange>e || endRange<b) return INT_MAX;
    else if(startRange<=b && endRange>=e) return segTree[node];
    ll left = (node<<1)+1, right = left+1, mid = (b+e)/2;
    return min(query(startRange, endRange, left, b, mid), query(startRange, endRange, right, mid+1, e));
}

int main() {
    ll t;
    scanf("%lld", &t);
    for(ll C=1; C<=t; ++C) {
        mem(segTree, INT_MAX);
        ll n, q, b, e;
        scanf("%lld%lld", &n, &q);
        for(ll i=0; i<n; ++i) scanf("%lld", &arr[i]);
        build(0, 0, n-1);
        printf("Case %lld:\n", C);
        while(q--) {
            scanf("%lld%lld", &b, &e);
            printf("%lld\n", query(b-1, e-1, 0, 0, n-1));
        }
    }
    return 0;
}

