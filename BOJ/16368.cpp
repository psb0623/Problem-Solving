#include<bits/stdc++.h>
using namespace std;

vector<int> ret[2010];
int day[2010],per[2010],st[2010];

struct Point{
    int id,cnt,next;
    Point(int i,int c,int n){id=i;cnt=c;next=n;}
    bool operator<(const Point& r) const {
        return cnt<r.cnt;
    }
};

int sum(int* a, int size){
	int ret = 0;
	for(int i=1; i<=size; i++){
		ret += a[i];
	}
	return ret;
}

int main()
{
    priority_queue<Point> pq;
    queue<Point> q;
	int m,n,w,h;
    scanf("%d %d %d %d",&m,&n,&w,&h);
    for(int i=1;i<=m;i++) scanf("%d",&day[i]);
    for(int i=1;i<=n;i++){
        scanf("%d",&per[i]);
        st[i]=per[i];
    }
    if(sum(day,m)!=sum(per,n)) return !printf("-1");
	st[0]=0;
    for(int i=1;i<=n;i++) for(int j=1; j<w; j++) st[i+j] -= st[i];
    for(int i=1;i<=m;i++) pq.push(Point(i,day[i],1));
    Point now = {0,0,0};
    for(int i=1;i<=n;i++){
        while(q.size()&&q.front().next==i){
        	now = q.front();
            q.pop();
            pq.push(now);
        }
        while(st[i]--){
            if(pq.size()==0) return !printf("-1");
            else{
            	now = pq.top();
            	pq.pop();
            }
            if(n<i+w-1) return !printf("-1");
            ret[now.id].push_back(i);
            now.next = i+w+h;
            now.cnt -= w;
            if(now.cnt) q.push(now);
        }
    }
    if(pq.size()||q.size()) return !printf("-1");
    else{
    	printf("1\n");
	    for(int i=1;i<=m;i++){
	        int len = ret[i].size();
	        for(int j=0; j<len; j++){
	        	printf("%d ",ret[i][j]);
	        }
	        printf("\n");
	    }
    }
}
