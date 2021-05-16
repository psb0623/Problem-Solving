#include<bits/stdc++.h>
using namespace std;

struct Trie{
	struct Node{
		Node(){
			for(int i=0;i<26;i++) go[i]=0;
		}
		int go[26];
		int fail = 0;
		bool output = 0;
	};
	
	vector<Node> v;
	Trie(){
		v.push_back(Node());
	}
	
	void insert(int cur, char* str){
		if(!(*str)) {
			v[cur].output = 1;
			return;
		}
		int next = (*str) - 'a';
		if(!v[cur].go[next]) {
			v[cur].go[next] = v.size();
			v.push_back(Node());
		}
		insert(v[cur].go[next], str+1);
	}
	
	void insert(char* str){
		insert(0, str);
	}
	
	void make_fail(){
		queue<int> q;
		q.push(0);
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			for(int i=0;i<26;i++){
				int next = v[cur].go[i];
				if(!next) continue;
				if(cur){
					int nfail = v[cur].fail;
					while(!v[nfail].go[i] && nfail) nfail = v[nfail].fail;
					if(v[nfail].go[i]) nfail = v[nfail].go[i];
					v[next].fail = nfail;
					v[next].output |= v[v[next].fail].output;
				}
				q.push(next);
			}
		}
	}
	
	bool match(char* str){
		int cur = 0;
		while(*str){
			int next = (*str) - 'a';
			while(cur && !v[cur].go[next]) cur = v[cur].fail;
			if(v[cur].go[next]) cur = v[cur].go[next];
			if(v[cur].output) return 1;
			str++;
		}
		return 0;
	}
	
	void debug(){
		for(int i=0;i<v.size();i++){
			printf("Node %d : \n",i);
			printf("fail : Node %d\n", v[i].fail);
			for(int j=0;j<26;j++) if(v[i].go[j]) printf("%c -> Node %d ", j+'a', v[i].go[j]);
			puts("");
			puts("");
		}
	}
};
int m,n;
char t[100010];
int main(){
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	
	Trie T;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> t;
		T.insert(t);
	}
	T.make_fail();
	cin >> m;
	for(int i=0;i<m;i++){
		cin >> t;
		cout << (T.match(t)?"YES":"NO") << "\n";
	}
}
