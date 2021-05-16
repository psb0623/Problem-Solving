#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

struct Matrix{
	int n,m;
	long long val[101][101];
	
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

Matrix ones(int n, int m){
	Matrix res(n,m);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) res.val[i][j] = 1ll;
	return res;
}

Matrix Power(Matrix A, int n){
	if(n == 1) return A;
	Matrix X = Power(A, n/2);
	if(n%2 == 0){
		return X * X;
	} else {
		return X * X * A;
	}
}

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	Matrix A(n,n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%lld", &A.val[i][j]);
		}
	}
	printf("%lld", (ones(1,n)*Power(A,k)*ones(n,1)).val[1][1] );
}
