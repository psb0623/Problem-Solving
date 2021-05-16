#include<bits/stdc++.h>
using namespace std;
typedef complex<double> cpx;
typedef vector<cpx> vec;

bool p[1000010];

const double PI = acos(-1);

void sieve(int n){
	p[0] = p[1] = 1;
	for(int i=2;i*i<=n;i++){
		if(p[i]) continue;
		for(int j=i*2;j<=n;j+=i) p[j] = 1;
	}
}

/*void fft(vec& v, cpx w){
	int n = v.size();
	if(n==1) return;
	vec even(n>>1), odd(n>>1);
	for(int i=0;i<n;i++){
		if(i&1) odd[i>>1] = v[i];
		else even[i>>1] = v[i];
	}
	fft(even, w*w); fft(odd,w*w);
	cpx now(1,0);
	for(int i=0;i<n/2;i++){
		v[i] = even[i] + now*odd[i];
		v[i+n/2] = even[i] - now*odd[i];
		now *= w;
	}
}*/


inline unsigned bitreverse(const unsigned n, const unsigned k) {
    unsigned r, i;
    for (r = 0, i = 0; i < k; ++i)
        r |= ((n >> i) & 1) << (k - i - 1);
    return r;
}

void fft(vec &v, bool rev=0) {
    const unsigned n = v.size(), k = __builtin_ctz(n);
    unsigned s, i, j;
    for(i=0;i<n;i++){
        j = bitreverse(i, k);
        if(i<j) swap(v[i],v[j]);
    }
    for(s=2;s<=n;s*=2){
        double t = 2*PI/s * (rev?-1:1);
        cpx w(cos(t),sin(t));
        for(i=0;i<n;i+=s) {
            cpx now(1,0);
            for(j=0;j<s/2;j++) {
                cpx tmp = v[i+j+s/2] * now;
                v[i+j+s/2] = v[i+j] - tmp;
                v[i+j] += tmp;
                now *= w;
            }
        }
    }
}

vec conv(vec a, vec b){
	int n = 1;
	int l = max(a.size(), b.size())<<1;
	while(n<l) n <<= 1;
	vec c(n);
	a.resize(n); b.resize(n);
	cpx w(cos(2*PI/n), sin(2*PI/n));
	cpx wbar(cos(2*PI/n), -sin(2*PI/n));
	fft(a); fft(b);
	for(int i=0;i<n;i++) c[i] = a[i] * b[i];
	fft(c,1);
	for(int i=0;i<n;i++) c[i] /= cpx(n,0);
	return c;
}

int MAXN = 1000000;

int main(){
	vec a(MAXN+1), b(MAXN+1);
	sieve(MAXN);
	//printf("sieve complete\n");
	for(int i=0;i<=MAXN;i++) if(!p[i]) a[i] = cpx(1,0);
	for(int i=0;i<=MAXN;i++) if(i%2==0 && (!p[i/2])) b[i] = cpx(1,0);
	//printf("FFT start\n");
	vec c = conv(a,b);
	//printf("FFT end\n");
	
	
	int T;
	scanf("%d",&T);
	while(T--){
		int t;
		scanf("%d",&t);
		printf("%d\n", (int)round(c[t].real()) );
	}
}
