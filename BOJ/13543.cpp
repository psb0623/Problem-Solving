#include<bits/stdc++.h>
#define MOD 4294967296ull

using namespace std;
typedef unsigned long long ull;

ull C[11][11];

struct Node{
	Node *p, *l, *r;
	int cnt;
	ull val;
	ull sum[11]; // sum[k] = sum i^k * a_i 
} *root;

void update(Node* x){
	x->cnt = 1;
	
	ull pw = 1ull;
	int lcnt = 1;
	if(x->l) lcnt = x->l->cnt+1;
	
	for(int i=0;i<=10;i++){
		x->sum[i] = (x->val*pw) % MOD;
		pw *= (ull)lcnt;
		pw %= MOD;
	}
	
	if(x->l) {
		x->cnt += x->l->cnt;
		for(int i=0;i<=10;i++) x->sum[i] += x->l->sum[i], x->sum[i] %= MOD;
	}
	
	int k = lcnt;
	
	if(x->r) {
		x->cnt += x->r->cnt;
		x->sum[0] += x->r->sum[0];
		x->sum[0] %= MOD;
		for(int i=1;i<=10;i++){
			ull now = 1ull;
			for(int j=i;j>=0;j--){
				x->sum[i] += (((C[i][j]*now)%MOD) * x->r->sum[j])%MOD;
				x->sum[i] %= MOD;
				now *= (ull)k;
				now %= MOD;
			}
		}
	}
}

void rotate(Node* x){
	Node* p = x->p;
	Node* b;
	if(p->l == x) p->l = b = x->r, x->r = p;
	else p->r = b = x->l, x->l = p;
	x->p = p->p, p->p = x;
	if(b) b->p = p;
	(x->p ? x->p->l == p ? x->p->l : x->p->r : root ) = x;
	update(p);
	update(x);
}

void Splay(Node* x){
	while(x->p){
		Node* p = x->p;
		Node* g = p->p;
		if(g) rotate( (g->l == p) == (p->l == x) ? p : x );
		rotate(x);
	}
}

void kth(int k){
	Node* x = root;
	while(1){
		while(x->l&&x->l->cnt>k) x = x->l;
		if(x->l) k -= x->l->cnt;
		if(!k--) break;
		x = x->r;
	}
	Splay(x);
}

void insert(int k, ull val){
	Node* y = new Node;
	y->l = y->p = y->r = nullptr;
	y->val = val;
	for(int i=0;i<=10;i++) y->sum[i] = val;
	y->cnt = 1;
	if(!root){
		root = y;
		return;
	}
	kth(k);
	if(!root->r) {
		y->p = root;
		root->r = y; 
	} else {
		Node* x = root->r;
		while(x->l) x = x->l;
		y->p = x;
		x->l = y;
	}
	Splay(y);
}

void erase(int k){
	if(!root) return;
	kth(k);
	Node* x = root;
	if(x->l&&x->r){
		root = x->l;
		root->p = nullptr;
		Node* y = root;
		while(y->r) y = y->r;
		y->r = x->r;
		x->r->p = y;
		Splay(y);
	} else if(x->l){
		root = x->l;
		root->p = nullptr;
	} else if(x->r){
		root = x->r;
		root->p = nullptr;
	}
	delete x;
}

int main(){
	for(int i=0;i<=10;i++) C[i][0] = C[i][i] = 1ull;
	for(int i=1;i<=10;i++) for(int j=1;j<i;j++) C[i][j] = C[i-1][j-1] + C[i-1][j];
	
	int n;
	scanf("%d",&n);
	
	insert(-1,0ull);
	for(int i=0;i<n;i++){
		ull t;
		scanf("%llu",&t);
		insert(i,t);
	}
	insert(n,0ull);
	int sz = n+2;
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int t;
		scanf("%d",&t);
		if(t==1){
			int p; ull v;
			scanf("%d %llu",&p,&v);
			insert(p,v);
			sz++;
		} else if(t==2) {
			int p;
			scanf("%d",&p);
			erase(p+1);
			sz--;
		} else if(t==3) {
			int p; ull v;
			scanf("%d %llu",&p,&v);
			kth(p+1);
			root->val = v;
			update(root);
		} else {
			int l,r,k;
			scanf("%d %d %d",&l,&r,&k);
			kth(l);
			Node* x = root;
			root = x->r;
			root->p = nullptr;
			kth(r-l+1);
			x->r = root;
			root->p = x;
			root = x;
			printf("%llu\n",root->r->l->sum[k]);
			/*for(int j=0;j<=2;j++){
				printf("sum[%d] = %llu\n",j,root->r->l->sum[j]);
			}*/
		}
		/*printf("result : ");
		for(int i=0;i<sz;i++){
			kth(i);
			printf("%llu ",root->val);
		}
		puts("");*/
	}
}
