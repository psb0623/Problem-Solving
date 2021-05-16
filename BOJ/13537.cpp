#include<bits/stdc++.h>
using namespace std;

int a[100010];

struct SegmentTree{
	int s,e;
	vector<int> v;
	SegmentTree *l, *r;
	
	void build(int start, int end){
		s = start;
		e = end;
		if(s!=e){
			l = new SegmentTree;
			r = new SegmentTree;
			
			l->build(s,(s+e)/2);
			r->build((s+e)/2+1,e);
			
			int xs = l->v.size();
			int ys = r->v.size();
		
			int x=0,y=0;
			while(x<xs || y<ys){
				
				int vx = 1e9+10, vy = 1e9+10;
				if(x<xs) vx = l->v[x];
				if(y<ys) vy = r->v[y];
				
				if(vx < vy){
					v.push_back(vx);
					x++;
				} else {
					v.push_back(vy);
					y++;
				}
			}	
		} else v.push_back(a[s]);
	}
	
	int get(int tarS, int tarE, int k){
		if(e<tarS||tarE<s) return 0;
		else if(tarS<=s&&e<=tarE){
			int ub = upper_bound(v.begin(),v.end(),k)-v.begin();
			return v.size()-ub;
		} else return l->get(tarS,tarE,k) + r->get(tarS,tarE,k);
	}
};
int n;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	SegmentTree* st = new SegmentTree;
	st->build(0,n-1);
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int x,y,k;
		scanf("%d %d %d",&x,&y,&k);
		printf("%d\n",st->get(x-1,y-1,k));
	}
}
