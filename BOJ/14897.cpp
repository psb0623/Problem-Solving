#include<bits/stdc++.h>
using namespace std;

struct Node{
	int val;
	int s,e;
	int l,r;
} st[24000010];
int cn = 0;
int newSegmentTree(){
	return cn++;
}

int build(int ind, int s, int e){
	st[ind].s = s;
	st[ind].e = e;
	if(s!=e){
		st[ind].l = newSegmentTree();
		st[ind].r = newSegmentTree();
		return st[ind].val = build(st[ind].l,s,(s+e)/2) + build(st[ind].r,(s+e)/2+1,e);
	} else return st[ind].val = 0;
}
int get(int ind, int tarS, int tarE){
	int s = st[ind].s;
	int e = st[ind].e;
	if(e<tarS || tarE<s) return 0;
	else if(tarS<=s&&e<=tarE) return st[ind].val;
	else return get(st[ind].l,tarS,tarE)+get(st[ind].r,tarS,tarE); 
}
int update(int ind, int tar,int diff){
	int s = st[ind].s;
	int e = st[ind].e;
	if(e<tar||tar<s) return ind;
	int ret = newSegmentTree();
	st[ret].s = s;
	st[ret].e = e;
	if(e==tar&&s==tar) st[ret].val = st[ind].val+diff;
	else {
		st[ret].l = update(st[ind].l,tar,diff);
		st[ret].r = update(st[ind].r,tar,diff);
		st[ret].val = st[st[ret].l].val + st[st[ret].r].val;
	}
	return ret;
}

int n;

int a[1000001];
map<int,int> p;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);

	int et = newSegmentTree();
	vector<int> rt;
	rt.push_back(et);
	build(0,0,n);

	for(int i=1;i<=n;i++) {
		int prev = p[a[i]];
		p[a[i]] = i;
		rt.push_back(update(rt[i-1],prev,1));
	}
	
	int m;
	scanf("%d",&m);
	
	int ans = 0;
	
	for(int i=0;i<m;i++){
		int l,r;
		scanf("%d %d",&l,&r);
		ans = get(rt[r],0,l-1)-get(rt[l-1],0,l-1);
		printf("%d\n",ans);
	}
}
