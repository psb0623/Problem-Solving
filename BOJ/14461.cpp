#include<bits/stdc++.h>
using namespace std;
int n,a[101][101],t;
int d[101][101][3];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
	scanf("%d %d",&n,&t);
	for(int i=0;i<n;i++) for(int j=0;j<n;j++){
		scanf("%d",&a[i][j]);
		d[i][j][0] = d[i][j][1] = d[i][j][2] = 1e9;
	}
	priority_queue< pair< pair<int,int>, pair<int,int> > > pq;
	pq.push({{0,0},{0,0}});
	while(!pq.empty()){
		int val = -pq.top().first.first;
		int dist = pq.top().first.second;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();
		//printf("(%d,%d) : %d %d\n",y,x,val,dist);
		for(int i=0;i<4;i++){
			int xx = x+dx[i];
			int yy = y+dy[i];
			if(xx>=0&&yy>=0&&xx<n&&yy<n) {
				int next = val+t;
				if((dist+1)%3==0) next += a[yy][xx];
				if(next<d[yy][xx][(dist+1)%3]){
					d[yy][xx][(dist+1)%3] = next;
					pq.push({{-next,dist+1},{yy,xx}});
				}
			}
		}
	}
	//for(int i=0;i<n;i++,puts("")) for(int j=0;j<n;j++) printf("%d ",d[i][j]);
	printf("%d",min(d[n-1][n-1][0],min(d[n-1][n-1][1],d[n-1][n-1][2])));
}
