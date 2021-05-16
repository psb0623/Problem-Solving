#include<bits/stdc++.h>
using namespace std;

int rt;

struct Query{
	int s,e,idx;
	bool operator<(const Query& b)const{
		if(s/rt==b.s/rt) return (e < b.e);
		return (s/rt)<(b.s/rt);
	}
} q[100010];

int n, m;
int a[100010], result[100010], cnt[100010], cnt2[100010];


int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	rt = sqrt(n);
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int s,e;
		scanf("%d %d",&s,&e);
		q[i] = {s-1,e-1,i};
	}
	sort(q,q+m);
	
	int s = q[0].s, e = q[0].e;
	cnt2[0] = n;
	
	for(int i=s;i<=e;i++){
		cnt2[cnt[a[i]]]--;
		cnt[a[i]]++;
		cnt2[cnt[a[i]]]++;
	}
	
	int ans = 0;
	for(int i=s;i<=e;i++) if(cnt2[cnt[a[i]]]) ans = max(ans,cnt[a[i]]);
	result[q[0].idx] = ans;
	
	for(int i=1;i<m;i++){
		while(q[i].s < s) {
			s--;
			cnt2[cnt[a[s]]]--;
			cnt[a[s]]++;
			cnt2[cnt[a[s]]]++;
		}
		while(e < q[i].e){
			e++;
			cnt2[cnt[a[e]]]--;
			cnt[a[e]]++;
			cnt2[cnt[a[e]]]++;
		}
		while(q[i].s > s) {
			cnt2[cnt[a[s]]]--;
			cnt[a[s]]--;
			cnt2[cnt[a[s]]]++;
			s++;
		}
		while(e > q[i].e){
			cnt2[cnt[a[e]]]--;
			cnt[a[e]]--;
			cnt2[cnt[a[e]]]++;
			e--;
		}
		int D = abs(q[i-1].s-s) + abs(q[i-1].e-e);
		int pans = ans;
		for(int i=max(0,pans-D);i<=min(100000,pans+D);i++) if(cnt2[i]) ans = i;
		result[q[i].idx] = ans;
	}
	for(int i=0;i<m;i++) printf("%d\n",result[i]);
}
