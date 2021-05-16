#include<bits/stdc++.h>
using namespace std;
int d[1010][1010];
char s1[1010], s2[1010];
int main(){
	scanf("%s", s1);
	scanf("%s", s2);
	int n = strlen(s1);
	int m = strlen(s2);
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i-1] == s2[j-1]) {
				d[i][j] = d[i-1][j-1] + 1;
			} else {
				d[i][j] = max(d[i-1][j], d[i][j-1]);
			}
		}
	}
	
	printf("%d", n + m - d[n][m]);
}
