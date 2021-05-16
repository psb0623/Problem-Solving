#include<bits/stdc++.h>
using namespace std;
struct Segtree{
	int val;
	int s,e;
	Segtree* l;
	Segtree* r;
	int build(int start,int end){
		s = start;
		e = end;
		if(s!=e){
			l = new Segtree;
			r = new Segtree;
			return val = l->build(s,(s+e)/2)+r->build((s+e)/2+1,e);
		} else return val = 0;
	}
	int get(int tarS,int tarE){
		if(tarE<s||e<tarS) return 0;
		else if(tarS<=s&&e<=tarE) return val;
		else return l->get(tarS,tarE)+r->get(tarS,tarE);
	}
	void update(int tar,int diff){
		if(tar<s||e<tar) return;
		else if(tar==s&&e==tar) val = diff;
		else {
			l->update(tar,diff);
			r->update(tar,diff);
			val = l->val + r->val;
		}
	}
};
int n;
int p[50001];
int a[100001];
int main(){
	scanf("%d",&n);
	for(int i=0;i<2*n;i++){
		int t;
		scanf("%d",&t);
		if(!p[t]) p[t] = 1;
		else p[t] = i;
		a[i] = t;
	}
	Segtree* st = new Segtree;
	st->build(0,2*n);
	long long ans = 0ll;
	for(int i=0;i<2*n;i++){
		if(i!=p[a[i]])ans += st->get(i,p[a[i]]);
		st->update(p[a[i]],1);
	}
	printf("%lld",ans);
}
