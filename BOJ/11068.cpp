#include<bits/stdc++.h>
using namespace std;
bool check(vector<int> v){
	for(int i=0;i<v.size();i++) if(v[i] != v[v.size()-1-i]) return false;
	return true;
}
vector<int> v(int x,int n){
	vector<int> res;
	while(x){
		res.push_back(x%n);
		x/=n;
	}
	return res;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int x;
		scanf("%d",&x);
		bool flag = 0;
		for(int i=2;i<=64;i++) if(check(v(x,i))) flag = 1;
		printf("%d\n",flag);
	}
}
