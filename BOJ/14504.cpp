#include<bits/stdc++.h>
using namespace std;
int n,m,sqrtN,a[100010];
vector<int> v[1000];
int main(){
	scanf("%d",&n);
	sqrtN = sqrt(n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		v[i/sqrtN].push_back(a[i]);
	}
	for(int i=0;i<=(n-1)/sqrtN;i++) sort(v[i].begin(), v[i].end());
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int t;
		scanf("%d",&t);
		if(t==1){
			int s,e,k;
			scanf("%d %d %d",&s,&e,&k);--s;--e;
			int bs = s/sqrtN;
			if(s%sqrtN) ++bs;
			int be = e/sqrtN-1;
			if((e+1)%sqrtN) --be;
			int ans = 0;
			
			if(bs<=be){
				for(int i=s;i<bs*sqrtN;i++) if(a[i] > k) ans++;
				for(int i=(be+1)*sqrtN;i<=e;i++) if(a[i] > k) ans++;
				for(int i=bs; i<=be; i++){
					int ub = upper_bound(v[i].begin(), v[i].end(), k) - v[i].begin();
					ans += v[i].size() - ub;
				}
			} else {
				for(int i=s;i<=e;i++) if(a[i] > k) ans++;
			}
			printf("%d\n",ans);
		} else {
			int tar, diff;
			scanf("%d %d",&tar,&diff);--tar;
			int idx = -1;
			int bn = tar/sqrtN;
			for(int i=0;i<sqrtN;i++){
				if(v[bn][i] == a[tar]){
					idx = i;
					a[tar] = v[bn][i] = diff;
					break;
				}
			}
			while(idx>0 && v[bn][idx]<v[bn][idx-1])	{
				int tmp = v[bn][idx];
				v[bn][idx] = v[bn][idx-1];
				v[bn][idx-1] = tmp;
				idx--;
			}		
			while(idx<v[bn].size()-1 && v[bn][idx]>v[bn][idx+1]){
				int tmp = v[bn][idx];
				v[bn][idx] = v[bn][idx+1];
				v[bn][idx+1] = tmp;
				idx++;
			}
		}
	}
}
