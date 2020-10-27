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

bool exist[1010][1010];
ll bit[1010][1010];

void update(ll x, ll y) {
    for(ll i=x; i<=1002; i+=(i&(-i))) {
        for(ll j=y; j<=1002; j+=(j&(-j))) {
            bit[i][j] += 1;
        }
    }
}

ll query(ll x, ll y) {
    ll sum = 0;
    if(x<0 || y<0) return 0;
    for(ll i=x; i>0; i-=(i&(-i))) {
        for(ll j=y; j>0; j-=(j&(-j))) {
            sum += bit[i][j];
        }
    }
    return sum;
}

ll solve(ll x1, ll y1, ll x2, ll y2) {
    return query(x2, y2) - query(x2, y1-1) - query(x1-1, y2) + query(x1-1, y1-1);
}

int main() {
    ll t;
    scanf("%lld", &t);
    for(ll c=1; c<=t; ++c) {
        mem(exist, 0);
        mem(bit, 0);
        ll q, k;
        scanf("%lld", &q);
        printf("Case %lld:\n", c);
        while(q--) {
            scanf("%lld", &k);
            if(k==0) {
                ll x, y;
                scanf("%lld%lld", &x, &y);
                if(exist[x][y]==false) {
                    exist[x][y] = true;
                    update(x+1, y+1);
                }
            } else {
                ll x1, x2, y1, y2;
                scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
                printf("%lld\n", solve(x1+1, y1+1, x2+1, y2+1));
            }
        }
    }

    return 0;
}

