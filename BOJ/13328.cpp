#include<bits/stdc++.h>
#define MOD 31991
using namespace std;

struct Matrix{
	int n,m;
	vector<long long> v[60];
	Matrix(int N,int M):n(N),m(M){
		for(int i=0;i<n;i++) v[i].resize(m);
	}
	Matrix operator*(Matrix A){
		int k=A.m;
		Matrix X(n,k);
		for(int i=0;i<n;i++){
			for(int j=0;j<k;j++){
				X.v[i][j]=0ll;
				for(int r=0;r<m;r++) {
					X.v[i][j] += v[i][r]*A.v[r][j];
					X.v[i][j] %= MOD;
				}
			}
		}
		return X;
	}
	void print(){
		for(int i=0;i<n;i++,puts(""))
			for(int j=0;j<m;j++) printf("%lld ",v[i][j]);
	}
};

Matrix P(Matrix A,long long n){
	if(n==1ll) return A;
	Matrix X = P(A,n/2);
	if(n%2) return X*X*A;
	else return X*X;
}

int main(){
	int d,t;
	scanf("%d %d",&d,&t);
	Matrix A(d,d);
	Matrix A0(d,1);
	A0.v[0][0] = 1;
	for(int i=0;i<d;i++) A.v[0][i] = 1;
	for(int i=0;i<d-1;i++) A.v[i+1][i] = 1;

	Matrix Ans = P(A,t)*A0;

	printf("%lld",Ans.v[0][0]);
}
