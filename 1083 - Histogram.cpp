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
const int mx = 3*(1e4)+10;
ll arr[mx];

int main() {
    ll t;
    scanf("%lld", &t);
    for(ll c=0; c<t; ++c) {
        ll n, m, ans = -1;;
        stack<ll> s;
        scanf("%lld", &n);
        for(ll i=0; i<n; ++i) {
            scanf("%lld", &arr[i]);
            if(s.empty() || arr[s.top()]<arr[i]) s.push(i);
            else {
                while(!(s.empty()) && arr[s.top()]>=arr[i]) {
                    ll tp = s.top();
                    s.pop();
                    ll areaWithTop=arr[tp]*(s.empty()?i:i-s.top()-1);
                    ans=max(ans,areaWithTop);
                }
                s.push(i);
            }
        }

        while(!(s.empty())) {
            ll tp = s.top();
            s.pop();
            ll areaWithTop=arr[tp]*(s.empty()?n:n-s.top()-1);
            ans=max(ans,areaWithTop);
        }
        printf("Case %lld: %lld\n", c+1, ans);
    }
    return 0;
}
