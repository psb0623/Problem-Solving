#include<bits/stdc++.h>
using namespace std;
int n, S[1010][1010], A[1010];
int main(){
	
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d", &S[i][j]);
	
	if(n==2) {
		printf("1 1");
		return 0;
	}
	
	A[1] = (S[1][2] + S[2][3] + S[3][1])/2 - S[2][3];
	
	for(int i=2;i<=n;i++) A[i] = S[i][1] - A[1];
	
	for(int i=1;i<=n;i++) printf("%d ", A[i]);
} 
