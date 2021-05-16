#include<bits/stdc++.h>
using namespace std;
int n;
long long t;
int a[20010];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	scanf("%lld",&t);
	sort(a,a+n);
	long long ans = 1e18;
	int ansi = -1;
	for(long long i=1;i<=a[n-1];i++){
		// i:buffer size
		int idx = -1;
		vector<long long> v;
		v.push_back(-1ll);
		long long j = 1;
		while(idx<n-1){
			idx = upper_bound(a,a+n,j*i)-a-1;
			j++;
			v.push_back((long long)idx);
		}
		long long tmp = 0ll;
		for(int j=1;j<v.size();j++) tmp += (v[j]-v[j-1])*j*(i+t);
		
		if(tmp < ans){
			ans = tmp;
			ansi = i;
		}
	}
	printf("%lld %d",ans,ansi);
}
