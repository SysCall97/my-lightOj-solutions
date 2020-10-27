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
ll lazy[5*mx+10];

void update(ll startRange, ll endRange, ll node, ll b, ll e) {
    ll left = 2*node+1, right = left+1;

    if(lazy[node]>0 && b!=e) {
        lazy[left] += lazy[node];
        lazy[right] += lazy[node];
        lazy[node] = 0;
    }

    if(startRange>e || endRange<b) return;

    if((startRange<=b && endRange>=e)) {
        lazy[node]++;
        return;
    }

    if(b!=e) {
        ll mid = (b+e)/2;
        update(startRange, endRange, left, b, mid);
        update(startRange, endRange, right, mid+1, e);
    }
    return;
}

ll getChanges(ll pos, ll node, ll b, ll e) {
    if(b==e && b==pos) return lazy[node];

    ll left = 2*node+1, right = left+1;

    if(lazy[node]>0 && b!=e) {
        lazy[left] += lazy[node];
        lazy[right] += lazy[node];
        lazy[node] = 0;
    }

    ll mid = (b+e)/2;
    if(b!=e) {
        if(b<=pos && mid>=pos) return getChanges(pos, left, b, mid);
        else return getChanges(pos, right, mid+1, e);
    }
}

void solve(string& str, ll pos, ll sz) {
    ll changes = getChanges(pos, 0, 0, sz);
    if(changes%2) {
        if(str[pos]=='1') printf("0\n");
        else printf("1\n");
    } else printf("%c\n", str[pos]);
    return;
}

int main() {
    ll t,n, i, j, sz;
    char ch, c;
    scanf("%lld", &t);
    for(ll C=1; C<=t; ++C) {
        c = getchar();
        string inp;
        getline(cin, inp);
        scanf("%lld", &n);
        printf("Case %lld:\n", C);
        sz = inp.size()-1;
        mem(lazy, 0);

        for(ll x=0; x<n; ++x) {
            c = getchar();
            scanf("%c", &ch);
            if(ch=='Q') {
                scanf("%lld", &i);
                solve(inp, i-1, sz);
            } else {
                scanf("%lld%lld", &i, &j);
                update(i-1, j-1, 0, 0, sz);
            }
        }
    }
    return 0;
}
