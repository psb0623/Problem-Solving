#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")

using namespace std;
typedef complex<double> cpx;
typedef vector<cpx> vec;

bool p[1000010];

const double PI = acos(-1);

void sieve(int n){
	p[0] = p[1] = 1;
	for(int i=2;i*i<=n;i++){
		if(p[i]) continue;
		for(int j=i+i;j<=n;j+=i) p[j] = 1;
	}
}

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

int MAXN = 500000;

int main(){
	
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	vec a(MAXN+1), b(MAXN+1);
	sieve(2*MAXN);
	//printf("sieve complete\n");
	for(int i=3;i<=2*MAXN;i++) if(!p[i]) a[i/2] = b[i/2] = cpx(1,0);
	//printf("FFT start\n");
	vec c = conv(a,b);
	//printf("FFT end\n");
	
	
	int T;
	cin>>T;
	while(T--){
		int t;
		cin >> t;
		if(t==4) cout << "1\n";
		else cout << (int)round(c[t/2-1].real())/2 + !p[t/2] << endl;
	}
}
