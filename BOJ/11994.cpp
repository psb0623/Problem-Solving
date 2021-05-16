#include<bits/stdc++.h>
using namespace std;
long long a[110];
long long d[8][110][110];
long long m[8][110][110];
int n,kk;

long long solve(long long* a){
	for(int i=1;i<=7;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				d[i][j][k] = LLONG_MAX;
			}
		}
	}
	d[1][0][0] = 0ll;
	for(int i=1;i<n;i++){
		d[1][0][i] = d[1][0][i-1] + i*a[i];
	}
	for(int k=0;k<n;k++){
		for(int j=0;j<=k;j++){
			if(j==0) m[1][j][k] = d[1][j][k];
			else m[1][j][k] = min(m[1][j-1][k],d[1][j][k]);
		}
	}
	for(int i=2;i<=7;i++){
		for(int j=i-1;j<n;j++){
			for(int k=j;k<n;k++){
				if(j==k){
					d[i][j][k] = m[i-1][k-1][k-1];
				} else d[i][j][k] = d[i][j][k-1] + (k-j)*a[k];
			}
		}
		for(int k=i-1;k<n;k++){
			for(int j=0;j<=k;j++){
				if(j==0) m[i][j][k] = d[i][j][k];
				else m[i][j][k] = min(m[i][j-1][k],d[i][j][k]);
			}
		}
	}
	/*for(int i=1;i<7;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				printf("%lld ",d[i][j][k]);
			}
			puts("");
		}
		puts("");
	}*/
	long long ans = LLONG_MAX;
	for(int i=1;i<=kk;i++){
		for(int j=i-1;j<n;j++){
			ans = min(ans,d[i][j][n-1]);
		}
	}
	return ans;
}

int main(){
	scanf("%d %d",&n,&kk);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	long long aa[220];
	for(int i=0;i<n;i++) aa[i] = aa[i+n] = a[i];
	long long ans = LLONG_MAX;
	for(int i=0;i<n;i++){
		//printf("%d\n",solve(aa+i));
		ans = min(ans, solve(aa+i));
	}
	printf("%lld",ans);
}
