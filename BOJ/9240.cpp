#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
int n;
pll operator-(pll a, pll b){return {a.x-b.x,a.y-b.y};}
long long cross(pll a, pll b){return a.x*b.y-b.x*a.y;}
bool ccw(pll a, pll b, pll c){return cross(b-a, c-a)>=0ll;}
double dist(pll a, pll b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
int main(){
	scanf("%d",&n);
	vector<pll> p;
	for(int i=0;i<n;i++) p.push_back({0ll,0ll}),scanf("%lld %lld",&p[i].first, &p[i].second);
	sort(p.begin(),p.end());
	vector<pll> up, down;
	up.push_back(p[0]);
	up.push_back(p[1]);
	down.push_back(p[0]);
	down.push_back(p[1]);
	int us = 2, ds = 2;
	for(int i=2;i<n;i++){
		while( us>=2 && ccw(up[us-2], up[us-1], p[i]) ) up.pop_back(), --us;
		while( ds>=2 && ccw(down[ds-2], p[i], down[ds-1]) ) down.pop_back(), --ds;
		up.push_back(p[i]),us++;
		down.push_back(p[i]),ds++;
	}
	reverse(down.begin(), down.end());
	int j=1;
	double ans = 0;
	/*for(int i=1;i<us;i++){
		pll now = up[i] - up[i-1];
		while(j<ds && cross(down[j]-down[j-1],now)>=0){
			ans = max(ans, dist(up[i-1],down[j]));
			ans = max(ans, dist(up[i],down[j-1]));
			ans = max(ans, dist(up[i-1],down[j-1]));
			ans = max(ans, dist(up[i],down[j]));
			j++;
		}
	}*/
	for(int i=0;i<us;i++){
		for(int j=0;j<ds;j++){
			ans = max(ans, dist(up[i],down[j]));
		}
	}
	printf("%lf",ans);
}
