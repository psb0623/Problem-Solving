#include<bits/stdc++.h>
using namespace std;
typedef complex<double> cpx;
const double pi = acos(-1);

void FFT(vector<cpx>&v, cpx w){
	int n = v.size();
	if(n==1) return;
	vector<cpx> even(n/2), odd(n/2);
	for(int i=0;i<n;i++){
		if(i%2) odd[i/2] = v[i];
		else even[i/2] = v[i];
	}
	FFT(odd,w*w); FFT(even,w*w);
	cpx now(1,0);
	for(int i=0;i<n/2;i++){
		v[i] = even[i] + now*odd[i];
		v[i+n/2] = even[i] - now*odd[i];
		now *= w;
	}
}

vector<cpx> conv(vector<cpx> a, vector<cpx> b){
	int n = 1;
	while(n<max(a.size(),b.size())<<1) n *= 2;
	a.resize(n); b.resize(n);
	vector<cpx> c(n);
	cpx w(cos(2*pi/n), sin(2*pi/n));
	FFT(a,w); FFT(b,w);
	for(int i=0;i<n;i++) c[i] = a[i]*b[i];
	cpx wbar(cos(2*pi/n), -sin(2*pi/n));
	FFT(c,wbar);
	for(int i=0;i<n;i++) c[i] /= cpx(n,0);
	return c;
}

int main(){
	int n;
	scanf("%d",&n);
	vector<cpx> a;
	vector<cpx> b;
	
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		a.push_back(cpx(t,0));
	}
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		b.push_back(cpx(t,0));
	}
	for(int i=0;i<n;i++){
		a.push_back(0);
		b.push_back(b[i]);
	}
	reverse(b.begin(), b.end());
	vector<cpx> c = conv(a,b);
	int ans = 0;
	for(int i=n-1;i<2*n-1;i++) ans = max(ans, (int)round(c[i].real()));
	printf("%d",ans);
}
