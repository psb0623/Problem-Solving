#include<bits/stdc++.h>
using namespace std;
struct SegmentTree{
	int val;
	int s,e;
	SegmentTree* l;
	SegmentTree* r;
	int build(int start,int end){
		s = start;
		e = end;
		if(s!=e){
			l = new SegmentTree;
			r = new SegmentTree;
			return val = l->build(s,(s+e)/2) + r->build((s+e)/2+1,e);
		} else return val = 0;
	}
	int get(int tarS,int tarE){
		if(tarE<s||e<tarS) return 0;
		else if(tarS<=s&&e<=tarE) return val;
		else return l->get(tarS,tarE) + r->get(tarS,tarE);
	}
	void update(int tar,int diff){
		if(tar<s||e<tar) return;
		else if(tar==s&&tar==e) val = diff;
		else {
			l->update(tar,diff);
			r->update(tar,diff);
			val = l->val + r->val;
		}
	}
};
int n;
vector<int> v;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		v.push_back(t);
	}
	SegmentTree* st = new SegmentTree;
	st->build(0,n);
	for(int i=v.size()-1;i>0;i--){
		if(v[i]<v[i-1]){
			st->update(v[i],1);
			v.pop_back();
			break;
		}
		st->update(v[i],1);
		v.pop_back();
	}
	printf("%d\n",v.size());
	for(int i=0;i<v.size();i++){
		printf("%d ",v.size()-i+st->get(1,v[i])-1);
		st->update(v[i],1);
	}
}
