#include<bits/stdc++.h>
using namespace std;
int ans[100];
unsigned long long d[40];

unsigned long long P(unsigned long long a, int n){
	if(n==0) return 1ull;
	if(n==1) return a;
	
	unsigned long long x = P(a,n/2);
	
	if(n%2) return x*x*a;
	else return x*x;
}

void query1(int n, int s, int e, unsigned long long k){
	int mid = 6-s-e;
	
	if(n==1) {
		ans[n] = e;
		return;
	}

	unsigned long long sub = P(2ull,n-1);
	
	if( k < sub ){
		ans[n] = s;
		query1(n-1, s, mid, k); // 2^(n-1)-1
	} else if( k == sub ) {
		ans[n] = e;
		query1(n-1, s, mid, k-1ull); // 1
	} else {
		ans[n] = e;
		query1(n-1, mid, e, k - sub); // 2^(n-1)-1
	}
}

void query2(int n, int s, int e, unsigned long long k){
	int mid = 6-s-e;
	
	if(n==1) {
		if(k==1ull) ans[n] = mid; // 1
		else if(k==2ull) ans[n] = e; // 1
		return;
	}

	unsigned long long sub = P(3ull,n-1);
	
	if( k < sub ){
		ans[n] = s;
		query2(n-1, s, e, k); // 3^(n-1)-1
	} else if( k == sub ) {
		ans[n] = mid;
		query2(n-1, s, e, k-1ull); // 1
	} else if( k < 2ull*sub) {
		ans[n] = mid;
		query2(n-1, e, s, k-sub); // 3^(n-1)-1
	} else if( k == 2ull*sub) {
		ans[n] = e;
		query2(n-1, e, s, k-1ull-sub);// 1
	} else {
		ans[n] = e;
		query2(n-1, s, e, k-2ull*sub);// 3^(n-1)-1
	}
}

void query3(int n, int s, int e, unsigned long long k){
	int mid = 6-s-e;
	
	if(n==1) {
		if(k==1ull) ans[n] = mid; // 1
		else if(k==2ull) ans[n] = e; // 1
		return;
	}
	if(n==2) {
		if(k==1ull){
			ans[2] = s;
			ans[1] = mid;
		}
		if(k==2ull){
			ans[2] = s;
			ans[1] = e;
		}
		if(k==3ull){
			ans[2] = mid;
			ans[1] = e;
		}
		if(k==4ull){
			ans[2] = mid;
			ans[1] = s;
		}
		if(k==5ull){
			ans[2] = e;
			ans[1] = s;
		}
		if(k==6ull){
			ans[2] = e;
			ans[1] = mid;
		}
		if(k==7ull){
			ans[2] = e;
			ans[1] = e;
		}
		return;
	}
	
	if( k <= d[n-1] ){
		ans[n] = s;
		query3(n-1, s, e, k); // d[n-1]
	} else if( k == d[n-1]+1ull ) {
		ans[n] = mid;
		query3(n-1, s, e, k-1ull); // 1
	} else if( k <= d[n-1]+1ull+d[n-2]) {
		ans[n] = mid;
		ans[n-1] = e;
		query3(n-2, e, mid, k-d[n-1]-1ull); // d[n-2]
	} else if( k == d[n-1]+1ull+d[n-2]+1ull ) {
		ans[n] = mid;
		ans[n-1] = s;
		query3(n-2, e, mid, k-d[n-1] - 1ull - 1ull);// 1
	} else if( k <= d[n-1] + 1ull + d[n-2] + 1ull + d[n-2]){
		ans[n] = mid;
		ans[n-1] = s;
		query3(n-2, mid, s, k- d[n-1] -1ull - d[n-2] - 1ull);// d[n-2]
	} else if(k==d[n-1] + 1ull + d[n-2] + 1ull + d[n-2] + 1ull){
		ans[n] = e;
		ans[n-1] = s;
		query3(n-2, mid, s, k- d[n-1] - 1ull - d[n-2] -1ull - 1ull);// 1
	} else {
		ans[n] = e;
		query3(n-1, s, e, k - d[n-1] - 1ull - d[n-2] - 1ull - d[n-2] - 1ull ); // d[n-1]
	}
}

int m,n;
unsigned long long k;

int main(){
	d[1] = 2ull;
	d[2] = 7ull;
	for(int i=3;i<=30;i++) {
		d[i] = 2ull*d[i-1] + 2ull*d[i-2] + 3ull;
	}
	scanf("%d %d %llu",&m,&n,&k);
	if(k==0ull) {
		for(int i=1;i<=n;i++) printf("%d ",1);
		return 0;
	}
	if(m==1) query1(n,1,3,k);
	else if(m==2) query2(n,1,3,k);
	else if(m==3) query3(n,1,3,k);
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	
}
