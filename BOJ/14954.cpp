#include<bits/stdc++.h>
using namespace std;
set<int> s;
int f(int x){
	if(x==0) return 0;
	return (x%10)*(x%10) + f(x/10);
}
int main(){
	int n;
	scanf("%d",&n);
	while(n>1){
		if(s.count(n)) return !printf("UNHAPPY");
		s.insert(n);
		n = f(n);
	}
	printf("HAPPY");
}
