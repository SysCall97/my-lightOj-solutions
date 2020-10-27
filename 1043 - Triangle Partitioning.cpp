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

void AD(double a, double area, double r) {
    double low = 0, high = a, ad;
    while(true) {
        ad = (low+high)/2;
        double sArea = ad * ad * area / (a * a);
        double bdec = area - sArea;
        double _ratio = sArea/bdec;
        if(abs(_ratio-r)<0.000000001) break;
        else if(_ratio>r) high = ad;
        else if(_ratio<r) low = ad;
    }
    cout<<fixed<<setprecision(6)<<ad<<el;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    for(ll Case = 1; Case<=t; ++Case) {
        double a, b, c, r;
        cin>>a>>b>>c>>r;
        double area = (a+b+c)/2;
        area = sqrt(area*(area-a)*(area-b)*(area-c));
        cout<<"Case "<<Case<<": ";
        AD(a, area, r);
    }
    return 0;
}

