#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

struct Matrix{
	int n,m;
	int val[81][81];
	
	Matrix(int N, int M):n(N),m(M){}
	
	Matrix operator*(const Matrix& O){
		Matrix res(n,O.m);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=O.m;j++){
				res.val[i][j] = 0;
				for(int k=1;k<=m;k++){
					res.val[i][j] += val[i][k] * O.val[k][j]; 
					res.val[i][j] %= MOD;
				}
			}
		}
		return res;
	}
};

Matrix zeros(int n, int m){
	Matrix res(n,m);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) res.val[i][j] = 0;
	return res;
}

Matrix Power(Matrix* A, int n){
	if(n == 1) return *A;
	Matrix X = Power(A, n/2);
	if(n%2 == 0){
		return X * X;
	} else {
		return X * X * (*A);
	}
}

int n,m;
int main(){
	while(1){
		scanf("%d %d",&n,&m);
		if(n==0 && m==0) break;
		Matrix P = zeros(n,n);
		for(int i=1;i<=n;i++){
			int t;
			scanf("%d",&t);
			P.val[t][i] = 1;
		}
		Matrix b = zeros(n,1);
		for(int i=1;i<=n;i++) b.val[i][1] = i;
	
		Matrix v = Power(&P,m)*b;
		
		char s[100];
		scanf("%c",&s[0]);
		for(int i=0;i<=n;i++) scanf("%c",&s[i]);
		s[n] = '\0';
		
		for(int i=1;i<=n;i++) printf("%c",s[v.val[i][1]-1]);
		printf("\n");
	}
}
