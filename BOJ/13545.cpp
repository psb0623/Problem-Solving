#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int sqrtN, sqrtK;
int a[100010];

list<int> dq[200010];

struct Query{
	int idx;
	int s,e;
	bool operator <(const Query &O) const {
		if(s/sqrtN == O.s/sqrtN) return e < O.e;
		return s < O.s;
	}
};

int num[100010];
int bucket[100010];

int getmax(){
	for(int i=n/sqrtN; i>=0; i--){
		if(bucket[i]==0) continue;
		for(int j = min((i+1)*sqrtN, 100000);;j--) if(num[j] > 0) return j;
	}
	return 0;
}

void update(int tar, int diff){
	num[tar] += diff;
	bucket[tar/sqrtN] += diff;
}

void dq_push(int k, int i){
	
	k += 1e5+1;
	
	if(dq[k].empty()){
		dq[k].push_front(i);
		update(dq[k].back()-dq[k].front(), 1);
	} else {
		update(dq[k].back()-dq[k].front(), -1);
		if(dq[k].front() < i) dq[k].push_back(i);
		else dq[k].push_front(i);
		update(dq[k].back()-dq[k].front(), 1);
	}
}

void dq_pop(int k, int i){
	
	k += 1e5+1;
	
	if(dq[k].empty()) return;
	
	update(dq[k].back() - dq[k].front(), -1);
	
	if(dq[k].front()==i) dq[k].pop_front();
	else if(dq[k].back()==i) dq[k].pop_back();
	
	if(!dq[k].empty()) update(dq[k].back() - dq[k].front(), 1);
}
void print(int x){
	printf("%d th query :",x);
	for(int i=0;i<=k;i++) printf("%d ",num[i]);
	printf(", ");
	for(int i=0;i<=k/sqrtK;i++) printf("%d ", bucket[i]);
	puts("");
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	n++;
	sqrtN = sqrt(n);
	for(int i=1;i<n;i++)cin >> a[i],a[i]+=a[i-1];
	cin >> m;
	vector<Query> Q;
	Q.resize(m);
	for(int i=0;i<m;i++){
		int s,e;
		cin >> s >> e;
		Q[i] = {i,s-1,e};
	}
	vector<int> ans;
	ans.resize(m);
	sort(Q.begin(), Q.end());
	for(int i=Q[0].s; i<=Q[0].e; i++) dq_push(a[i], i);
	//print(Q[0].idx);
	ans[Q[0].idx] = getmax();
	int s = Q[0].s, e = Q[0].e;
	for(int i=1;i<m;i++){
		
		while(Q[i].s < s) s--, dq_push(a[s], s);
		while(e < Q[i].e) e++, dq_push(a[e], e);
		while(s < Q[i].s) dq_pop(a[s], s), s++;
		while(Q[i].e < e) dq_pop(a[e], e), e--;
		
		ans[Q[i].idx] = getmax();
		//print(Q[i].idx);
		
	}
	for(int i=0;i<m;i++) cout << ans[i] << "\n";
}
