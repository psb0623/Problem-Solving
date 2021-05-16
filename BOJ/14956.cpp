#include <bits/stdc++.h>
using namespace std;
int n,m;
int ansx, ansy;
void get(int n, int cur, int x, int y, vector<int> v){
    int h = n/2, k = h*h;
    if (cur<1||cur>n*n) return;
    if (n==1){
    	ansx = x;
    	ansy = y;
		return;
	}
    get(h,cur, x+((v[0]%2)?h:0), y+((v[0]/2)?h:0), {v[0],v[3],v[2],v[1]});
    get(h,cur-k, x+((v[1]%2)?h:0), y+((v[1]/2)?h:0), v);
    get(h,cur-2*k, x+((v[2]%2)?h:0), y+((v[2]/2)?h:0), v);
    get(h,cur-3*k, x+((v[3]%2)?h:0), y+((v[3]/2)?h:0), {v[2],v[1],v[0],v[3]});
}
int main(){
    scanf("%d %d",&n,&m);
    get(n,m,1,1,{0,2,3,1});
    printf("%d %d", ansx, ansy);
}
