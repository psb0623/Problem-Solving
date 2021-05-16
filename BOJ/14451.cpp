#include<bits/stdc++.h>
using namespace std;
int a[22][22];
int d[22][22][22][22][4];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n;
int main(){
	scanf("%d",&n);
	for(int i=n;i>=1;i--){
		char t[100];
		scanf("%s",t);
		for(int j=1;j<=n;j++) a[i][j] = (t[j-1]=='E')?0:1;
	}
	for(int i=0;i<=n+1;i++) a[i][0] = a[i][n+1] = a[n+1][i] = a[0][i] = 1;
	queue< pair< pair< pair<int,int> , int>, pair< pair<int,int> , int> > > q;
	q.push({{{1,1},0},{{1,1},0}});
	int nowsize = 1;
	int level = 0;
	while(!q.empty()){
		auto F = q.front().first;
		auto S = q.front().second;
		int y1 = F.first.first;
		int x1 = F.first.second;
		int dir1 = F.second;
		int y2 = S.first.first;
		int x2 = S.first.second;
		int dir2 = (dir1+1)%4;
		int num = S.second;
		q.pop();
		if(d[y1][x1][y2][x2][dir1]) continue;
		d[y1][x1][y2][x2][dir1] = 1;
		
		if(y1==n&&x1==n&&y2==n&&x2==n) {
			printf("%d",num);
			break;
		}
		//printf("%d\n",num);
		//straight
		int xx1 = x1 + dx[dir1];
		int yy1 = y1 + dy[dir1];
		if(a[yy1][xx1] || (x1==n&&y1==n)) {
			yy1 = y1;
			xx1 = x1;	
		}
		int xx2 = x2 + dx[dir2];
		int yy2 = y2 + dy[dir2];
		if(a[yy2][xx2] || (y2==n&&x2==n)) {
			yy2 = y2;
			xx2 = x2;	
		}
		if(!d[yy1][xx1][yy2][xx2][dir1]) q.push({{{yy1,xx1},dir1},{{yy2,xx2},num+1}});
		//right
		if(!d[y1][x1][y2][x2][(dir1+3)%4]) q.push({{{y1,x1},(dir1+3)%4},{{y2,x2},num+1}});
		//left
		if(!d[y1][x1][y2][x2][(dir1+1)%4]) q.push({{{y1,x1},(dir1+1)%4},{{y2,x2},num+1}});
	}
}
