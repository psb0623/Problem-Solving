#include<bits/stdc++.h>
using namespace std;
map<char,int> m;
int main(){
	int t=0;
	while(t!=7){
		cin>>t;
		char t1,t2;
		int x;
		switch(t){
			case 1:
				cin>>t1>>x;
				m[t1] = x;
				break;
			case 2:
				cin>>t1;
				cout<<m[t1]<<"\n";
				break;
			case 3:
				cin>>t1>>t2;
				m[t1] = m[t1]+m[t2];
				break;
			case 4:
				cin>>t1>>t2;
				m[t1] = m[t1]*m[t2];
				break;
			case 5:
				cin>>t1>>t2;
				m[t1] = m[t1]-m[t2];
				break;
			case 6:
				cin>>t1>>t2;
				m[t1] = m[t1]/m[t2];
				break;
			case 7:
				return 0;
			
		}
	}
}
