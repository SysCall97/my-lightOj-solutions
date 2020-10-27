#include<bits/stdc++.h>
using namespace std;
#define fori(a,b) for(int i=a; i<b; ++i)
#define ford(a,b) for(int i=a; i>=b; --i)
#define nl puts("")
typedef long long ll;
ll dp[10100];
ll func(ll n)
{
    if(dp[n]==-1)
        dp[n]=func(n-1)+func(n-2)+func(n-3)+func(n-4)+func(n-5)+func(n-6);
    dp[n]=dp[n]%10000007;
    return dp[n];
}

void preCall(ll a, ll b, ll c, ll d, ll e, ll f, ll n)
{
    for(int i=0; i<=n+1; ++i)
        dp[i]=-1;
    dp[0]=a,dp[1]=b,dp[2]=c;
    dp[3]=d,dp[4]=e,dp[5]=f;
}

int main()
{
    ll Case=0,t;
    scanf("%lld",&t);
    while(t--) {
        ll a,b,c,d,e,f,n;
        scanf("%lld%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f,&n);
        preCall(a,b,c,d,e,f,n);
        printf("Case %lld: %lld\n",++Case,func(n));
    }
    return 0;
}
