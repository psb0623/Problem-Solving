#include<bits/stdc++.h>
using namespace std;

long long a[100010];

struct MaxSegmentTree{
	long long val;
	int s,e;
	MaxSegmentTree* left;
	MaxSegmentTree* right;
	
	long long build(int start,int end){
		s = start;
		e = end;
		if(s==e) return val = a[s];
		else {
			left = new MaxSegmentTree;
			right = new MaxSegmentTree;
			return val = max(left->build(s,(s+e)/2),right->build((s+e)/2+1,e));
		}
	}
	long long get(int tarS, int tarE){
		if(e<tarS||tarE<s) return 0ll;
		else if(tarS<=s&&e<=tarE){
			return val;
		}
		else return max(left->get(tarS,tarE),right->get(tarS,tarE));
	}
	void update(int tar, long long diff){
		if(e<tar||tar<s) return;
		else if(tar==s&&tar==e) val = diff;
		else {
			left->update(tar, diff);
			right->update(tar,diff);
			val = max(left->val,right->val);
		}
	}
};

struct Edge{
	int to, val, idx;
};
vector<Edge> adj[100010];
vector<int> child[100010];

class HeavyLightDecomposition{
private:
	vector<int> subtree_size, num, chain, head, tail, depth, parent;
	int dcnt=0, ccnt=0;
public:
	int get_subtree_size(int cur, int prev=-1){
		subtree_size[cur] = 1;
		for(auto E:adj[cur]){
			int next;
			next = E.to;
			if(next != prev){
				subtree_size[cur] += get_subtree_size(next, cur);
				child[cur].push_back(next);
			}
		}
		return subtree_size[cur];
	}
	void make_chain(int cur, int d){
		int u = num[cur] = dcnt++;
		chain[u] = ccnt;
		depth[u] = d;
		if(head[ccnt]<0) head[ccnt] = u;
		tail[ccnt] = u;
		if(child[cur].empty()) {
			head.push_back(-1);
			tail.push_back(-1);
			ccnt++;
			return;
		}
		int heavy = child[cur][0];
		for(int i=1;i<child[cur].size();i++){
			int now = child[cur][i];
			if(subtree_size[heavy] < subtree_size[now]) heavy = now;
		}
		make_chain(heavy, d+1);
		for(int next:child[cur]){
			if(next != heavy){
				make_chain(next, d+1);
				parent[num[next]] = num[cur];
			}
		}
	}
	void ready(int n){
		subtree_size.resize(n);
		num.resize(n);
		chain.resize(n);
		depth.resize(n);
		parent.resize(n);
		head.push_back(-1);
		tail.push_back(-1);
		get_subtree_size(0);
		make_chain(0,0);
	}
	void decompose(vector< pair<int,int> >& a, int u, int v){
		if(u==v) return;
		u = num[u];
		v = num[v];
		while(chain[u] != chain[v]){
			if(depth[head[chain[u]]] > depth[head[chain[v]]]){
				a.push_back({head[chain[u]],u});
				u = parent[head[chain[u]]];
			} else {
				a.push_back({head[chain[v]],v});
				v = parent[head[chain[v]]];
			}
		}
		a.push_back({min(u,v)+1,max(u,v)});
	}
	int getnum(int i){
		return num[i];
	}
	int getdepth(int i){
		return depth[i];
	}
};

int n;

int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int t1,t2,val;
		scanf("%d %d %d",&t1,&t2,&val);
		t1--;
		t2--;
		adj[t1].push_back({t2,val,i});
		adj[t2].push_back({t1,val,i});
	}
	
	HeavyLightDecomposition HLD;
	
	HLD.ready(n);
	
	int tar[100010];
	
	for(int i=0;i<n;i++){
		int u = HLD.getnum(i);
		for(Edge E:adj[i]){
			int next, val, idx;
			next = E.to;
			val = E.val;
			idx = E.idx;
			int v = HLD.getnum(next);
			
			if(HLD.getdepth(u)<HLD.getdepth(v)){
				tar[idx] = v;
				a[v] = val;
			}
		}
	}
	
	MaxSegmentTree* st = new MaxSegmentTree;
	st->build(0,n-1);
	
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int t;
		scanf("%d",&t);
		if(t==1){
			int idx, diff;
			scanf("%d %d",&idx,&diff);
			st->update(tar[idx],diff);
		} else {
			int u,v;
			scanf("%d %d",&u,&v);
			u--;
			v--;
			vector< pair<int,int> > q;
			HLD.decompose(q,u,v);
			long long res = 0;
			for(auto x:q){
				int s = x.first;
				int e = x.second;
				//printf("{%d,%d}\n",s,e);
				res = max(res, st->get(s,e));
			}
			printf("%d\n",res);
		}
	}
	
}
