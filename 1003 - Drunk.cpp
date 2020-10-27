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
#define all(v)        v.begin(), v.end()
#define allr(v)       v.rbegin(), v.rend()
#define mem(x,y)      memset(x , y , sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PI;

const int mx = 20010;

map<string, ll> mp;
vector<ll> graph[mx], sorted;
ll counter[mx];

void initiate() {
    for(ll i=0; i<mx; ++i) {
        graph[i].clear();
        counter[i]=0;
    }
    sorted.clear();
    mp.clear();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;

    for(ll c=1; c<=t; ++c) {
        initiate();
        ll m, cnt=1, sz=0;
        cin>>m;
        cin.ignore();
        for(ll i=0; i<m; ++i) {
            string s1, s2;
            cin>>s1>>s2;
            if(mp[s1]==0) mp[s1] = cnt++;
            if(mp[s2]==0) mp[s2] = cnt++;

            graph[mp[s1]].pb(mp[s2]);
            ++counter[mp[s2]];

        }

        for(ll i=0; i<cnt; ++i) if(counter[i]==0) {
            sorted.push_back(i);
            ++sz;
        }

        for(ll i=0; i<sz; ++i) {
            ll u = sorted[i];
            for(ll j=0; j<graph[u].size(); ++j) {
                --counter[graph[u][j]];
                if(counter[graph[u][j]]==0) {
                    sorted.push_back(graph[u][j]);
                    ++sz;
                }
            }
        }


        bool bl=0;
        for(ll i=1; i<cnt; ++i) if(counter[i]) {
            bl=1;
            break;
        }
        printf("Case %d: ", c);
        if(bl) puts("No");
        else puts("Yes");
    }
    return 0;
}
