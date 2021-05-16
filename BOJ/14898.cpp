#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

using namespace std;

struct PST;
PST* newPST();

struct PST{
	int val;
	int s,e;
	PST *l, *r;
	int build(int start, int end){
		s = start;
		e = end;
		if(s!=e){
			l = newPST();
			r = newPST();
			return val = l->build(s,(s+e)/2) + r->build((s+e)/2+1,e);
		} else return val = 0;
	}
	int get(int tarS, int tarE){
		if(e<tarS || tarE<s) return 0;
		else if(tarS<=s&&e<=tarE) return val;
		else return l->get(tarS,tarE)+r->get(tarS,tarE); 
	}
	PST* update(int tar,int diff){
		if(e<tar||tar<s) return this;
		PST* ret = newPST();
		ret->s = s;
		ret->e = e;
		if(e==tar&&s==tar) ret->val = val+diff;
		else {
			ret->l = l->update(tar,diff);
			ret->r = r->update(tar,diff);
			ret->val = ret->l->val + ret->r->val;
		}
		return ret;
	}
};

PST container[24*1000000];
int cn = 0;
PST* newPST(){ return &container[cn++]; }

int n;

int a[1000001];
map<int,int> p;
vector<PST*> st;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];

	PST* rt = new PST;
	st.push_back(rt);
	st[0]->build(0,n);

	for(int i=1;i<=n;i++) {
		int prev = p[a[i]];
		p[a[i]] = i;
		st.push_back(st[i-1]->update(prev,1));
	}
	
	int m;
	cin >> m;
	
	int ans = 0;
	
	for(int i=0;i<m;i++){
		int l,r;
		cin >> l >> r;
		l += ans;
		ans = st[r]->get(0,l-1)-st[l-1]->get(0,l-1);
		cout << ans << "\n";
	}
}
