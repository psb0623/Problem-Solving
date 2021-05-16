#include<bits/stdc++.h>
using namespace std;
int vis[9][9];
int dx[8] = {-2,-1,1,2,2,1,-1,-2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};

int main(){
	int sx,sy,ex,ey;
	cin>>sx>>sy>>ex>>ey;
	queue< pair<int, pair<int,int> > > q;
	q.push({0,{sx,sy}});
	while(!q.empty()){
		int l = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		if(vis[x][y]) continue;
		vis[x][y] = 1;
		if(x==ex&&y==ey) {
			printf("%d",l);
			return 0;
		}
		
		for(int i=0;i<8;i++){
			int xx = x+dx[i];
			int yy = y+dy[i];
			if(1<=xx&&xx<=8&&1<=yy&&yy<=8&&!vis[xx][yy]) q.push({l+1,{xx,yy}}); 
		}
	}
}

