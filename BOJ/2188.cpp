#include<bits/stdc++.h>

using namespace std;

struct Edge{
	int to,c,f;
	Edge* inv;
	Edge(): Edge(-1, 0){}
    Edge(int to1, int c1): to(to1), c(c1), f(0), inv(nullptr){}
    int spare(){
    	return c-f;
    }
    void update(int val){
    	f += val;
    	inv->f -= val;
    }
};

vector<Edge*> adj[410];

void connect(int s, int e, int val){
	Edge *e1 = new Edge(e,val);
	Edge *e2 = new Edge(s,0);
	e1->inv = e2;
	e2->inv = e1;
	adj[s].push_back(e1);
	adj[e].push_back(e2);
}

int n,m;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		int cnt;
		scanf("%d",&cnt);
		for(int j=0;j<cnt;j++){
			int t;
			scanf("%d",&t);
			connect(i,n+t-1,1);
		}
	}
	
	int S = n+m, E = n+m+1;
	
	for(int i=0;i<n;i++) connect(S,i,1);
	for(int i=n;i<n+m;i++) connect(i,E,1);
	int ans = 0;
	while(1){
		queue<int> q;
		int prev[410];
		fill(prev,prev+410,-1);
		Edge* path[410] = {};
		
		q.push(S);
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			for(Edge* e:adj[cur]){
				int next = e->to;
				if(e->spare()>0 && prev[next]==-1){
					q.push(next);
					prev[next] = cur;
					path[next] = e;
					if(next == E) break;
				}
			}
		}
		if(prev[E]==-1) break;
		
		int flow = 1e9;
		for(int i = E; i!=S; i=prev[i]) flow = min(flow,path[i]->spare());
		for(int i = E; i!=S; i=prev[i]) path[i]->update(flow);
		ans += flow;
	}
	printf("%d",ans);
}
